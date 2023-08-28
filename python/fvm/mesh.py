#!/usr/bin/env python3
import openmesh as om
import numpy as np
from utils import *
from problem import Problem
from diamond import Diamond
from scipy.sparse import csr_matrix, csc_matrix
from scipy.sparse.linalg import gmres, bicgstab, minres, qmr
from scipy.spatial.distance import pdist


def readmesh(fname):
    """read mesh and then processing it"""
    mesh = om.read_polymesh(fname)

    if not mesh.has_vertex_property("global_index"):
        mesh.vertex_property("global_index")

    if not mesh.has_face_property("diameter"):
        mesh.face_property("diameter")

    # Set global index
    index = 0
    for vh in mesh.vertices():
        mesh.set_vertex_property("global_index", vh, index)
        index += 1

    #
    for fh in mesh.faces():
        vertices = np.vstack([mesh.point(vh)[:2] for vh in mesh.fv(fh)])
        diameter = np.max(pdist(vertices))
        mesh.set_face_property("diameter", fh, diameter)

    return mesh


# def write_mesh(fname, u, mesh):
#     for vh in mesh.vertices():
#         point = mesh.point(vh)
#         point += np.array([0, 0, u[vh.idx()]])
#         if point[2] < 0:
#             point[2] = -0.2
#         om.write_mesh(fname, mesh)


def vertex_handle_prev(mesh, fh, vh):
    for heh in mesh.fh(fh):
        if mesh.to_vertex_handle(heh) == vh:
            return mesh.from_vertex_handle(heh)


def vertex_handle_next(mesh, fh, vh):
    for heh in mesh.fh(fh):
        if mesh.from_vertex_handle(heh) == vh:
            return mesh.to_vertex_handle(heh)


if __name__ == "__main__":
    fname = "meshes/quadrangle_uniform_1.obj"
    mesh = readmesh(fname)
    print(mesh.n_vertices(), mesh.n_faces())

    global_indices = [mesh.face_property("global_index", fh) for fh in mesh.faces()]
    global_indices += [
        mesh.vertex_property("global_index", vh) for vh in mesh.vertices()
    ]
    print(global_indices)

    for fh in mesh.faces():
        print(f"face - #{mesh.face_property('global_index', fh)}")
        for vh in mesh.fv(fh):
            print(mesh.vertex_property("global_index", vh))

    for fh in mesh.faces():
        K = mesh.calc_face_centroid(fh)[:2]
        # print(f'K: {K}')
        for vh in mesh.fv(fh):
            v = mesh.point(vh)[:2]
            vh_prev = vertex_handle_prev(mesh, fh, vh)
            vh_next = vertex_handle_next(mesh, fh, vh)
            v_prev = mesh.point(vh_prev)[:2]
            v_next = mesh.point(vh_next)[:2]
            # print(f"v={v}, v_prev={v_prev}, v_next={v_next}")
            diamond = Diamond(K, v, v_prev, v_next)
            # print(diamond)

            # alpha = 1 / (4 * diamond.area) * (diamond.dist_p)**2 * (diamond.normal @ diamond.normal)
            # print(alpha)

    for vh in mesh.vertices():
        if not mesh.is_boundary(vh):
            v = mesh.point(vh)[:2]
            for fh in mesh.vf(vh):
                K = mesh.calc_face_centroid(fh)[:2]
                vh_prev = vertex_handle_prev(mesh, fh, vh)
                vh_next = vertex_handle_next(mesh, fh, vh)
                v_prev = mesh.point(vh_prev)[:2]
                v_next = mesh.point(vh_next)[:2]
                diamond = Diamond(K, v, v_prev, v_next)
                # print(diamond)
