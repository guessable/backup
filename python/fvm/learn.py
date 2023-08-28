#!/usr/bin/env python3
# _*_ coding:utf-8 _*_
#      "
#    '':''
#   ___:____      |\/|
# ,'        `.    \  /
# |  O        \___/  |
# ~^~^~^~^~^~^~^~^~^~^

import openmesh as om
import numpy as np


def vertex_handle_next(mesh, fh, vh):
    for heh in mesh.fh(fh):
        if mesh.from_vertex_handle(heh) == vh:
            return mesh.to_vertex_handle(heh)


def halfedge_handle_face(mesh, fh, heh):
    heh = mesh.opposite_halfedge_handle(heh)
    for ff in mesh.ff(fh):
        for halfedge in mesh.fh(ff):
            if halfedge == heh:
                return ff


def halfedge_face_prev(mesh, fh, heh):
    heh = mesh.prev_halfedge_handle(heh)
    while mesh.is_boundary(mesh.opposite_halfedge_handle(heh)):
        heh = mesh.prev_halfedge_handle(heh)
    return halfedge_handle_face(mesh, fh, heh)


def halfedge_face_next(mesh, fh, heh):
    heh = mesh.next_halfedge_handle(heh)
    while mesh.is_boundary(mesh.opposite_halfedge_handle(heh)):
        heh = mesh.next_halfedge_handle(heh)
    return halfedge_handle_face(mesh, fh, heh)


# for fh in mesh.faces():
#     for vh in mesh.fv(fh):
#         vh_next = vertex_handle_next(mesh, fh, vh)
#         heh = mesh.find_halfedge(vh, vh_next)

#         heh_next = mesh.next_halfedge_handle(heh)
#         print(heh_next)

# oppo_heh = mesh.opposite_halfedge_handle(heh)
# if not mesh.is_boundary(oppo_heh):
#     ne_face = halfedge_handle_face(mesh, fh, oppo_heh)
#     print(f"{fh.idx()}:{ne_face.idx()}")

if __name__ == "__main__":
    mesh = om.read_polymesh("./meshes/triangle_uniform_1.obj")
    for fh in mesh.faces():
        for vh in mesh.fv(fh):
            vh_next = vertex_handle_next(mesh, fh, vh)
            heh = mesh.find_halfedge(vh, vh_next)

            if not mesh.is_boundary(mesh.opposite_halfedge_handle(heh)):
                heh_prev = halfedge_face_prev(mesh, fh, heh)
                print(f"{fh.idx()}->{heh_prev.idx()}")
        for ff in mesh.ff(fh):
            print(f"next{fh.idx()}->{ff.idx()}")
