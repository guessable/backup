#!/usr/bin/env python3
"""
Vertex Centered Diamond Scheme (VertexCenteredDiamond) on arbitrary polygonal mesh
"""
import numpy as np
from vertex_centered_scheme import VertexCenteredScheme
from diamond import Diamond
from mesh import vertex_handle_prev, vertex_handle_next
from scipy.sparse import csr_matrix
from scipy.sparse.linalg import gmres, bicgstab


class VertexCenteredDiamond(VertexCenteredScheme):
    def _element_stiffness_matrix(self, fh):
        mesh, problem = self.mesh, self.problem

        N = len(list(mesh.fv(fh)))
        AK = np.zeros((N, N))
        K = mesh.calc_face_centroid(fh)[:2]
        Lambda = problem.diffusive(K)

        for i, vh in enumerate(mesh.fv(fh)):
            # Construction of diamond
            vh_prev = vertex_handle_prev(mesh, fh, vh)
            vh_next = vertex_handle_next(mesh, fh, vh)
            vh_prev_prev = vertex_handle_prev(mesh, fh, vh_prev)
            vh_next_next = vertex_handle_next(mesh, fh, vh_next)

            v = mesh.point(vh)[:2]
            v_prev = mesh.point(vh_prev)[:2]
            v_next = mesh.point(vh_next)[:2]
            v_prev_prev = mesh.point(vh_prev_prev)[:2]
            v_next_next = mesh.point(vh_next_next)[:2]

            d = Diamond(v, v_prev, v_next, K)
            d_prev = Diamond(v_prev, v_prev_prev, v, K)
            d_next = Diamond(v_next, v, v_next_next, K)

            a = (1 - 1 / N) / (4 * d.area) * (Lambda @ d.norm2 @ d.norm2)
            b = (1 - 1 / N) / (8 * d.area) * (Lambda @ d.norm1 @ d.norm2)
            a_prev = (
                1
                / (4 * d_prev.area)
                * (Lambda @ (d_prev.norm1 / 2 - d_prev.norm2 / N) @ d_prev.norm2)
            )
            b_prev = (
                1
                / (8 * d_prev.area)
                * (Lambda @ d_prev.norm1 @ (d_prev.norm1 / 2 - d_prev.norm2 / N))
            )
            a_next = (
                -1
                / (4 * d_next.area)
                * (Lambda @ (d_next.norm1 / 2 + d_next.norm2 / N) @ d_next.norm2)
            )
            b_next = (
                -1
                / (8 * d_next.area)
                * (Lambda @ d_next.norm1 @ (d_next.norm1 / 2 + d_next.norm2 / N))
            )

            i_prev_prev, i_prev = (i - 2) % N, (i - 1) % N
            i_next_next, i_next = (i + 2) % N, (i + 1) % N

            AK[i, i] += a
            AK[i, i_prev] -= b
            AK[i, i_next] += b

            AK[i, i_prev] += a_prev
            AK[i, i_prev_prev] -= b_prev
            AK[i, i] += b_prev

            AK[i, i_next] += a_next
            AK[i, i] -= b_next
            AK[i, i_next_next] += b_next

            tmp = (a + a_prev + a_next) / N
            for j, nuh in enumerate(mesh.fv(fh)):
                AK[i, j] -= tmp

                if nuh not in [vh, vh_prev, vh_next]:
                    nuh_prev = vertex_handle_prev(mesh, fh, nuh)
                    nuh_next = vertex_handle_next(mesh, fh, nuh)

                    nu = mesh.point(nuh)[:2]
                    nu_prev = mesh.point(nuh_prev)[:2]
                    nu_next = mesh.point(nuh_next)[:2]

                    j_prev, j_next = (j - 1) % N, (j + 1) % N

                    d = Diamond(nu, nu_prev, nu_next, K)

                    a_nu = -1 / N / (4 * d.area) * (Lambda @ d.norm2 @ d.norm2)
                    b_nu = -1 / N / (8 * d.area) * (Lambda @ d.norm1 @ d.norm2)

                    AK[i, j] += a_nu
                    AK[i, j_prev] -= b_nu
                    AK[i, j_next] += b_nu

                    for k, muh in enumerate(mesh.fv(fh)):
                        AK[i, k] -= a_nu / N

        return AK

    def compute_h1_error(self):
        mesh, problem, ua = self.mesh, self.problem, self.ua
        err_h1 = 0

        for vh in mesh.vertices():
            if not mesh.is_boundary(vh):
                for fh in mesh.vf(vh):
                    K = mesh.calc_face_centroid(fh)[:2]
                    vh_prev = vertex_handle_prev(mesh, fh, vh)
                    vh_next = vertex_handle_next(mesh, fh, vh)

                    v = mesh.point(vh)[:2]
                    v_prev = mesh.point(vh_prev)[:2]
                    v_next = mesh.point(vh_next)[:2]

                    idx_v = mesh.vertex_property("global_index", vh)
                    idx_v_prev = mesh.vertex_property("global_index", vh_prev)
                    idx_v_next = mesh.vertex_property("global_index", vh_next)

                    d = Diamond(v, v_prev, v_next, K)

                    N = len(list(mesh.fv(fh)))
                    ua_sum = 0
                    for muh in mesh.fv(fh):
                        mu = mesh.point(muh)[:2]
                        ua_sum += ua[mesh.vertex_property("global_index", muh)]

                    ua_grad = (
                        1
                        / (2 * d.area)
                        * (
                            (ua[idx_v_next] - ua[idx_v_prev]) / 2 * d.norm1
                            + (ua[idx_v] - ua_sum / N) * d.norm2
                        )
                    )
                    ue_grad = problem.grad(d.center)
                    err_h1 += d.area * np.linalg.norm(ua_grad - ue_grad) ** 2

        return np.sqrt(err_h1)


if __name__ == "__main__":
    from utils import show_errors
    from options import Options
    from problem import Problem
    from mesh import readmesh

    args = Options().parse()
    problem = Problem(case=args.case)

    n_levels = 5
    hmeshes = []
    errors_max = []
    errors_l2 = []
    errors_h1 = []

    print("\n" + "=" * 70)
    print(f"Vertex Centered Diamond Scheme (case: {args.case}, mesh: {args.mesh})\n")
    print(
        f"{'hmesh':>11s}{'error_max':>11s}{'error_l2':>11s}{'error_h1':>11s}{'Symmetry':>10}"
    )
    for i in range(n_levels):
        fname = f"meshes/{args.mesh}_{i+1}.obj"
        mesh = readmesh(fname)

        solver = VertexCenteredDiamond(problem, mesh)
        solver.assemble_stiffness_matrix()
        solver.assemble_source_term()
        solver.treat_boundary_condition()
        solver.solve()
        hmesh, error_max, error_l2, error_h1 = solver.compute_errors()

        hmeshes.append(hmesh)
        errors_max.append(error_max)
        errors_l2.append(error_l2)
        errors_h1.append(error_h1)

        symmetry = "T" if solver.is_symmetry() else "F"
        print(
            f"{hmeshes[i]:11.3e}{errors_max[i]:11.3e}{errors_l2[i]:11.3e}{errors_h1[i]:11.3e}{symmetry:>10}"
        )

    print("\n" + "-" * 70)
    show_errors(hmeshes, errors_max, errors_l2, errors_h1)
    print("=" * 70 + "\n")
