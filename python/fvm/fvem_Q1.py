#!/usr/bin/env python3
"""
Q1 Finite Volume Element Method (fvem_Q1) on quadrilateral mesh
"""
import numpy as np
import numpy as np
from vertex_centered_scheme import VertexCenteredScheme
from diamond import Diamond
from mesh import vertex_handle_prev, vertex_handle_next
from scipy.sparse import csr_matrix
from scipy.sparse.linalg import gmres, bicgstab


def gradient_basis(x, xi):
    """

    Params
    ======
    x:  (4,2) np.array
    xi: (2,) np.array

    Returns
    =======
    (2,4) np.array

    """
    grad_basis_reference = (
        np.array(
            [
                [-1 + xi[1], 1 - xi[1], 1 + xi[1], -1 - xi[1]],
                [-1 + xi[0], -1 - xi[0], 1 + xi[0], 1 - xi[0]],
            ]
        )
        / 4
    )

    # Jacobian matrix
    J = np.zeros((2, 2))
    J[0, 0] = np.dot(x[:, 0], grad_basis_reference[0])
    J[0, 1] = np.dot(x[:, 1], grad_basis_reference[0])
    J[1, 0] = np.dot(x[:, 0], grad_basis_reference[1])
    J[1, 1] = np.dot(x[:, 1], grad_basis_reference[1])

    # inverse of J
    J_inv = np.linalg.inv(J)

    grad_basis = J_inv @ grad_basis_reference

    return grad_basis


class FVEM_Q1(VertexCenteredScheme):
    def _element_stiffness_matrix(self, fh):
        mesh, problem = self.mesh, self.problem

        AK = np.zeros((4, 4))
        K = mesh.calc_face_centroid(fh)[:2]
        Lambda = problem.diffusive(K)

        x = []
        for vh in mesh.fv(fh):
            x.append(mesh.point(vh)[:2])
        x = np.vstack(x)

        xi = np.array([0, 0])
        for i, vh in enumerate(mesh.fv(fh)):
            # Choice of xi_prev and xi_next
            if i == 0:
                xi_prev, xi_next = np.array([-1, 0]), np.array([0, -1])
            elif i == 1:
                xi_prev, xi_next = np.array([0, -1]), np.array([1, 0])
            elif i == 2:
                xi_prev, xi_next = np.array([1, 0]), np.array([0, 1])
            elif i == 3:
                xi_prev, xi_next = np.array([0, 1]), np.array([-1, 0])

            # Construction of diamond
            vh_prev = vertex_handle_prev(mesh, fh, vh)
            vh_next = vertex_handle_next(mesh, fh, vh)

            v = mesh.point(vh)[:2]
            v_prev = mesh.point(vh_prev)[:2]
            v_next = mesh.point(vh_next)[:2]

            d = Diamond(v, v_prev, v_next, K)

            norm_prev = d.norm_prev
            norm_next = d.norm_next

            grad_basis = gradient_basis(x, xi)
            grad_basis_prev = gradient_basis(x, xi_prev)
            grad_basis_next = gradient_basis(x, xi_next)

            AK[i] = (
                -(
                    (norm_prev + norm_next).T @ Lambda @ grad_basis
                    + norm_prev.T @ Lambda @ grad_basis_prev
                    + norm_next.T @ Lambda @ grad_basis_next
                )
                / 2
            )

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
    print(f"FVEM-Q1  (case: {args.case}, mesh: {args.mesh})\n")
    print(
        f"{'hmesh':>11s}{'error_max':>11s}{'error_l2':>11s}{'error_h1':>11s}{'Symmetry':>10}"
    )
    for i in range(n_levels):
        fname = f"meshes/{args.mesh}_{i+1}.obj"
        mesh = readmesh(fname)

        solver = FVEM_Q1(problem, mesh)
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
