#!/usr/bin/env python
import numpy as np


class Problem:
    def __init__(self, case=0, eps=1e-3):
        super().__init__()
        self.case = case
        self.eps = eps

    def diffusive(self, X):
        """Compute the diffusion tensor

        Params
        ======
        X (2, ) ndarray

        Return
        ======
        (2, 2) ndarray
        """
        x, y = X[0], X[1]

        if self.case in (0, 1, 2, 3, 4, 5, 12):
            return np.eye(2)

        elif self.case == 6:
            if x <= 0.5:
                return np.array([[3.0, 1.0], [1.0, 3.0]])
            else:
                return np.array([[10.0, 3.0], [3.0, 10.0]])

        elif self.case == 7:
            return np.array([[1.5, 0.5], [0.5, 1.5]])

        elif self.case == 8:
            if x <= 0.5:
                return np.eye(2)
            else:
                return 4 * np.eye(2)

        elif self.case == 9:
            if y < 0.5:
                if x < 0.5:
                    return np.array([[10, 0], [0, 0.01]])
                else:
                    return np.array([[0.1, 0], [0, 100.0]])
            else:
                if x < 0.5:
                    return np.array([[100, 0], [0, 0.1]])
                else:
                    return np.array([[0.01, 0], [0, 10]])

        elif self.case in (10, 11):
            beta = self.eps
            return np.array(
                [
                    [beta * x**2 + y**2, (beta - 1) * x * y],
                    [(beta - 1) * x * y, x**2 + beta * y**2],
                ]
            ) / (x**2 + y**2)

    def sol(self, X):
        x, y = X[0], X[1]

        if self.case == 0:
            return 1.0

        elif self.case == 1:
            return x + y

        elif self.case == 2:
            return x**2 + y**2

        elif self.case == 3:
            return x**3 + y**3

        elif self.case == 4:
            return x**4 + y**4

        elif self.case == 5:
            return np.exp(-(x**2) - y**2)

        elif self.case == 6:
            if x <= 0.5:
                return 14 * x + y
            else:
                return 4 * x + y + 5

        elif self.case == 7:
            xx = 1.0 - x
            yy = 1.0 - y
            return 0.5 * (np.sin(xx * yy) / np.sin(1.0) + xx**3 * yy**2)

        elif self.case == 8:
            if x <= 0.5:
                return 1 - 2 * y**2 + 4 * x * y + 6 * x + 2 * y
            else:
                return 3.25 - 2 * y**2 + 3.5 * y + x * y + 1.5 * x

        elif self.case == 9:
            if y < 0.5:
                if x < 0.5:
                    c = 0.1
                else:
                    c = 10.0
            else:
                if x < 0.5:
                    c = 0.01
                else:
                    c = 100

            return c * np.sin(2 * np.pi * x) * np.sin(2 * np.pi * y) + 12.0

        elif self.case == 10:
            return np.sin(np.pi * x) * np.sin(np.pi * y)

        elif self.case == 12:
            return 2 - x**2 - y**2

    def grad(self, X):
        x, y = X[0], X[1]

        if self.case == 0:
            return np.array([0, 0])

        elif self.case == 1:
            return np.array([1, 1])

        elif self.case == 2:
            return np.array([2 * x, 2 * y])

        elif self.case == 3:
            u_x = 3 * x**2
            u_y = 3 * y**2
            return np.array([u_x, u_y])

        elif self.case == 4:
            u_x = 4 * x**3
            u_y = 4 * y**3
            return np.array([u_x, u_y])

        elif self.case == 5:
            u_x = -2 * x * np.exp(-(x**2) - y**2)
            u_y = -2 * y * np.exp(-(x**2) - y**2)
            return np.array([u_x, u_y])

        elif self.case == 6:
            if x <= 0.5:
                u_x = 14
                u_y = 1
            else:
                u_x = 4
                u_y = 1
            return np.array([u_x, u_y])

        elif self.case == 7:
            x = 1.0 - x
            y = 1.0 - y

            u_x = 0.5 * (-y * np.cos(x * y) / np.sin(1.0) - 3 * x**2 * y**2)
            u_y = 0.5 * (-x * np.cos(x * y) / np.sin(1.0) - 2 * x**3 * y)
            return np.array([u_x, u_y])

        elif self.case == 8:
            if x <= 0.5:
                u_x = 4 * y + 6.0
                u_y = -4 * y + 4 * x + 2.0
            else:
                u_x = y + 1.5
                u_y = x - 4 * y + 3.5
            return np.array([u_x, u_y])

        elif self.case == 9:
            if y < 0.5:
                if x < 0.5:
                    c = 0.1
                else:
                    c = 10.0
            else:
                if x < 0.5:
                    c = 0.01
                else:
                    c = 100

            u_x = c * 2 * np.pi * np.cos(2 * np.pi * x) * np.sin(2 * np.pi * y)
            u_y = c * 2 * np.pi * np.sin(2 * np.pi * x) * np.cos(2 * np.pi * y)
            return np.array([u_x, u_y])

        elif self.case == 10:
            """Heterogenous rotating anisotropy"""
            beta = self.eps

            u_x = np.pi * np.cos(np.pi * x) * np.sin(np.pi * y)
            u_y = np.pi * np.sin(np.pi * x) * np.cos(np.pi * y)
            return np.array([u_x, u_y])

        elif self.case == 12:
            u_x = -2 * x
            u_y = -2 * y
            return np.array([u_x, u_y])

    def source(self, X):
        x, y = X[0], X[1]

        if self.case in (0, 1):
            return 0.0

        elif self.case == 2:
            return -4.0

        elif self.case == 3:
            return -6.0 * x - 6.0 * y

        elif self.case == 4:
            return -12.0 * x**2 - 12.0 * y**2

        elif self.case == 5:
            return -4 * (x**2 + y**2 - 1) * self.sol(X)

        elif self.case == 6:
            return 0

        elif self.case == 7:
            K = self.diffusive(X)
            kxx = K[0, 0]
            kxy = K[0, 1]
            kyy = K[1, 1]

            x = 1.0 - x
            y = 1.0 - y

            ux = -y * np.cos(x * y) / np.sin(1.0) - 3 * x**2 * y**2
            uy = -x * np.cos(x * y) / np.sin(1.0) - 2 * x**3 * y
            uxx = -(y**2) * np.sin(x * y) / np.sin(1.0) + 6 * x * y**2
            uxy = (
                -x * y * np.sin(x * y) / np.sin(1.0)
                + np.cos(x * y) / np.sin(1.0)
                + 6 * x**2 * y
            )
            uyy = -(x**2) * np.sin(x * y) / np.sin(1.0) + 2 * x**3

            return -0.5 * (kxx * uxx + 2 * kxy * uxy + kyy * uyy)

        elif self.case == 8:
            K = self.diffusive(X)
            kxx = K[0, 0]
            kxy = K[0, 1]
            kyy = K[1, 1]

            if x <= 0.5:
                ux = 4 * y + 6.0
                uy = -4 * y + 4 * x + 2.0
                uxx = 0.0
                uxy = 4.0
                uyy = -4.0

            else:
                ux = y + 1.5
                uy = x - 4 * y + 3.5
                uxx = 0.0
                uxy = 1.0
                uyy = -4.0

            return -(kxx * uxx + 2 * kxy * uxy + kyy * uyy)

        elif self.case == 9:
            K = self.diffusive(X)
            kxx = K[0, 0]
            kxy = K[0, 1]
            kyy = K[1, 1]

            if y < 0.5:
                if x < 0.5:
                    c = 0.1
                else:
                    c = 10.0
            else:
                if x < 0.5:
                    c = 0.01
                else:
                    c = 100

            ux = c * 2 * np.pi * np.cos(2 * np.pi * x) * np.sin(2 * np.pi * y)
            uy = c * 2 * np.pi * np.sin(2 * np.pi * x) * np.cos(2 * np.pi * y)
            uxx = -c * (2 * np.pi) ** 2 * np.sin(2 * np.pi * x) * np.sin(2 * np.pi * y)
            uxy = c * (2 * np.pi) ** 2 * np.cos(2 * np.pi * x) * np.cos(2 * np.pi * y)
            uyy = -c * (2 * np.pi) ** 2 * np.sin(2 * np.pi * x) * np.sin(2 * np.pi * y)

            return -(kxx * uxx + 2 * kxy * uxy + kyy * uyy)

        elif self.case == 10:
            """Heterogenous rotating anisotropy"""
            beta = self.eps

            K = self.diffusive(X)
            kxx = K[0, 0]
            kxy = K[0, 1]
            kyy = K[1, 1]

            scale = (beta - 1) / (x**2 + y**2) ** 2
            kxx_x = 2 * x * y**2 * scale
            kxy_x = y * (y**2 - x**2) * scale
            kyx_y = x * (x**2 - y**2) * scale
            kyy_y = 2 * x**2 * y * scale

            ux = np.pi * np.cos(np.pi * x) * np.sin(np.pi * y)
            uy = np.pi * np.sin(np.pi * x) * np.cos(np.pi * y)

            uxx = -np.pi**2 * np.sin(np.pi * x) * np.sin(np.pi * y)
            uxy = np.pi**2 * np.cos(np.pi * x) * np.cos(np.pi * y)
            uyy = -np.pi**2 * np.sin(np.pi * x) * np.sin(np.pi * y)

            return -(
                (kxx_x + kyx_y) * ux
                + (kxy_x + kyy_y) * uy
                + (kxx * uxx + 2 * kxy * uxy + kyy * uyy)
            )

        elif self.case == 11:
            return 10 if 3 / 8 <= x <= 5 / 8 and 3 / 8 <= y <= 5 / 8 else 0

        elif self.case == 12:
            return 4

    def bc_dirichlet(self, x):
        if self.case == 11:
            return 0
        else:
            return self.sol(x)

    def bc_neumann(self, x):
        return None

    def __repr__(self):
        return f"Poisson problem with {self.case} case"


if __name__ == "__main__":
    problem = Problem(11, eps=1e-1)
    # print(problem.case)

    def limiter(X, alpha=3):
        x, y = X[0], X[1]
        res = (1 - min(x, y) / max(x, y)) ** alpha if x > 0 and y > 0 else 1
        return res * (x - y)

    import matplotlib.pyplot as plt
    from mpl_toolkits import mplot3d

    # u = np.array([problem.sol(X[i]) for i in range(len(X))]).reshape(xx.shape)
    N = 7
    x = np.linspace(-1, 1, 200)
    y = np.linspace(-1, 1, 200)
    xx, yy = np.meshgrid(x, y)
    X = np.vstack((xx.flatten(), yy.flatten())).T
    f = np.array([limiter(X[i], alpha=N) for i in range(len(X))]).reshape(xx.shape)

    fig = plt.figure()
    ax = fig.add_subplot(1, 2, 1)

    # ax.plot_surface(xx, yy, f, rstride=1, cstride=1,
    #             cmap='rainbow', edgecolor='none')
    cs = ax.contour(
        xx,
        yy,
        f,
        levels=[
            -2,
            -1.75,
            -1.5,
            -1.25,
            -1,
            -0.75,
            -0.5,
            -0.375,
            -0.25,
            -0.125,
            0,
            0.125,
            0.25,
            0.375,
            0.5,
            0.75,
            1,
            1.25,
            1.5,
            1.75,
            2,
        ],
    )
    ax.clabel(cs, fontsize=9, inline=True)
    ax.set_aspect("equal")
    ax.set_xlim(-1, 1)
    ax.set_ylim(-1, 1)
    ax.set_title(f"N={N}")

    ax = fig.add_subplot(projection="3d")
    ax.view_init(32, -48)
    plt.show()
