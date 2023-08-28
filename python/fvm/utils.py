#!/usr/bin/env python
import numpy as np
from problem import Problem


def normal(v):
    """find orthogonal vector of the vector v counterclockwisely"""
    R = np.array([[0, -1], [1, 0]])
    return R @ v


def area(a, b, c):
    """find area of the triangle consisting of three vertices a, b and c"""
    ab = b - a
    ac = c - a
    return 0.5 * abs(ab[0] * ac[1] - ab[1] * ac[0])


def dist(a, b):
    """find distance of two points a and b"""
    return np.linalg.norm(b - a)


def show_errors(hmeshes, errors_max, errors_l2, errors_h1):
    print(
        f"{'hmesh':>11s}{'error_max':>11s}{'ratio':>7s}{'error_l2':>11s}{'ratio':>7s}{'error_h1':>11s}{'ratio':>7s} "
    )
    for i in range(len(hmeshes)):
        if i == 0:
            print(
                f"{hmeshes[i]:11.3e}{errors_max[i]:11.3e}{' ':7s}{errors_l2[i]:11.3e}{' ':7s}{errors_h1[i]:11.3e} {' ':8s}"
            )
        else:
            r_max = np.log(errors_max[i - 1] / errors_max[i]) / np.log(
                hmeshes[i - 1] / hmeshes[i]
            )
            r_l2 = np.log(errors_l2[i - 1] / errors_l2[i]) / np.log(
                hmeshes[i - 1] / hmeshes[i]
            )
            r_h1 = np.log(errors_h1[i - 1] / errors_h1[i]) / np.log(
                hmeshes[i - 1] / hmeshes[i]
            )
            print(
                f"{hmeshes[i]:11.3e}{errors_max[i]:11.3e}{r_max:7.3f}{errors_l2[i]:11.3e}{r_l2:7.3f}{errors_h1[i]:11.3e}{r_h1:7.3f}"
            )


def checkout(case, mesh):
    print("=" * 40)
    # print(f'mesh_type: {mesh}, case: {case}')
    if case in (6, 10):
        if mesh not in [
            "triangle_uniform",
            "triangle_classic",
            "triangle_kershaw",
            "quadrangle_uniform",
            "quadrangle_kershaw",
            "quadrangle_trapezoidal",
            "quadrangle_random1",
            "quadrangle_random2",
            "quadrangle_shashkov",
        ]:
            raise ValueError(
                "Invalid mesh! Only quadrangle (uniform, kershaw, trapezoidal, random1, random2) and triangle (uniform, classic) meshes allowed!"
            )
        else:
            print("Mesh Checkout Pass!")

    # elif case == 9:
    #     if mesh != 'quadrangle_random2':
    #         raise ValueError('Invalid mesh! Only quadrangle_random2 mesh allowed!')
    #     else:
    #         print('Mesh Checkout Pass!')
    #
    # elif case == 10:
    #     if mesh not in ('triangle_random_half', 'quadrangle_random_half',
    #                     'triangle_kershaw_half', 'quadrangle_kershaw_half'):
    #         raise ValueError('Invalid mesh! Only triangle_random/kershaw_half & quadrangle_random/kershaw_half mesh allowed!')
    #     else:
    #         print('Mesh Checkout Pass!')

    else:
        print("Mesh Checkout Pass!")

    print("=" * 40)
    print("")


if __name__ == "__main__":
    v = np.array([-1, 1])
    print(normal(v))

    a = np.array([0, 0])
    b = np.array([2, 0])
    c = np.array([0, 1])
    print(area(a, b, c))
    print(dist(a, b))
    print(np.array([1, 2]))
    print(abs(b))
