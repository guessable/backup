# Abstract Base Class of numerical schemes for diffuion problems
import numpy as np
from diamond import Diamond
from mesh import readmesh, vertex_handle_prev, vertex_handle_next
from scipy.sparse import csr_matrix
from scipy.sparse.linalg import gmres, bicgstab


class VertexCenteredScheme:
    def __init__(self, problem, mesh):
        self.problem = problem
        self.mesh = mesh

        n_vertices = mesh.n_vertices()

        self.A = np.zeros((n_vertices, n_vertices))
        self.b = np.zeros(n_vertices)
        self.ua = np.zeros(n_vertices)

    def _element_stiffness_matrix(self, fh):
        raise NotImplementedError()

    def assemble_stiffness_matrix(self):
        mesh, problem = self.mesh, self.problem

        for fh in mesh.faces():
            AK = self._element_stiffness_matrix(fh)

            for i, vh in enumerate(mesh.fv(fh)):
                if not mesh.is_boundary(vh):
                    k = mesh.vertex_property("global_index", vh)

                    for j, uh in enumerate(mesh.fv(fh)):
                        l = mesh.vertex_property("global_index", uh)
                        self.A[k, l] += AK[i, j]

    def assemble_source_term(self):
        mesh, problem = self.mesh, self.problem

        for vh in mesh.vertices():
            if not mesh.is_boundary(vh):
                i = mesh.vertex_property("global_index", vh)
                v = mesh.point(vh)[:2]

                area = 0.0
                b_temp = 0.0
                for fh in mesh.vf(vh):
                    K = mesh.calc_face_centroid(fh)[:2]
                    vh_prev = vertex_handle_prev(mesh, fh, vh)
                    vh_next = vertex_handle_next(mesh, fh, vh)

                    v_prev = mesh.point(vh_prev)[:2]
                    v_next = mesh.point(vh_next)[:2]

                    diamond = Diamond(v, v_prev, v_next, K)
                    area += diamond.area  # new D_v * f_v
                    b_temp += problem.source(diamond.center) * diamond.area

                self.b[i] = b_temp

    def treat_boundary_condition(self):
        mesh, problem = self.mesh, self.problem

        for vh in mesh.vertices():
            if mesh.is_boundary(vh):
                i = mesh.vertex_property("global_index", vh)
                self.A[i, i] = 1.0
                self.b[i] = problem.bc_dirichlet(mesh.point(vh)[:2])

    def solve(self, solver_name="gmres", tol=1e-13, maxiter=5000):
        # Transfer full_matrix to csr_matrix when solving the linear system
        A = csr_matrix(self.A)
        b = self.b

        if solver_name == "gmres":
            self.ua, info = gmres(A, b, tol=tol, maxiter=maxiter)
        elif solver_name == "bicgstab":
            self.ua, info = bicgstab(A, b, tol=tol, maxiter=maxiter)

        if info > 0:
            print(f"Convergence to tolerance not achieved! (#it = {info})")
        elif info < 0:
            print("Illegal input or breakdown!")

    def compute_max_error(self):
        mesh, problem, ua = self.mesh, self.problem, self.ua
        err_max = -np.inf

        for vh in mesh.vertices():
            if not mesh.is_boundary(vh):
                i = mesh.vertex_property("global_index", vh)
                v = mesh.point(vh)[:2]
                ue_ = problem.sol(v)
                ua_ = ua[i]
                err = np.abs(ue_ - ua_)
                if err > err_max:
                    err_max = err

        return err_max

    def compute_l2_error(self):
        mesh, problem, ua = self.mesh, self.problem, self.ua
        err_l2 = 0

        for vh in mesh.vertices():
            if not mesh.is_boundary(vh):
                i = mesh.vertex_property("global_index", vh)
                v = mesh.point(vh)[:2]
                ue_ = problem.sol(v)
                ua_ = ua[i]
                err = np.abs(ue_ - ua_)

                area_control_volume = 0
                for fh in mesh.vf(vh):
                    K = mesh.calc_face_centroid(fh)[:2]
                    vh_prev = vertex_handle_prev(mesh, fh, vh)
                    vh_next = vertex_handle_next(mesh, fh, vh)
                    v = mesh.point(vh)[:2]
                    v_prev = mesh.point(vh_prev)[:2]
                    v_next = mesh.point(vh_next)[:2]
                    d = Diamond(v, v_prev, v_next, K)
                    area_control_volume += d.area

                err_l2 += err**2 * area_control_volume

        return np.sqrt(err_l2)

    def compute_h1_error(self):
        raise NotImplementedError()

    def compute_errors(self):
        mesh = self.mesh

        hmesh = np.max([mesh.face_property("diameter", fh) for fh in mesh.faces()])
        err_max = self.compute_max_error()
        err_l2 = self.compute_l2_error()
        err_h1 = self.compute_h1_error()

        return hmesh, err_max, err_l2, err_h1

    def is_symmetry(self):
        A = self.A
        L = []  # store the indices of interior vertices
        for i in range(A.shape[0]):
            if abs(A[i].sum() - A[i, i]) > 1e-13:
                L.append(i)
        for i in L:
            for j in L:
                if abs(A[i][j] - A[j][i]) > 1e-13:
                    return False
        return True
