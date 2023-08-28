#!/usr/bin/env python3
import numpy as np

import vcds
from mesh import *
from problem import Problem
from utils import show_errors, check_mesh
from options import Options

# import time
# from scipy.sparse.linalg import LinearOperator, spilu


args = Options().parse()

if args.case in (10, 11):
    problem = Problem(case=args.case, eps=1e-3)
else:
    problem = Problem(case=args.case)

checkout(args.case, args.mesh)


print("=" * 40)
print(f"case: {args.case}, mesh_type: {args.mesh}")
print("=" * 40)
# print('')

n_levels = 5
hmeshes = []
errors_max = []
errors_l2 = []
errors_h1 = []

for i in range(0, n_levels):
    fname = f"meshes/{args.mesh}_{i+1}.obj"
    mesh = readmesh(fname)

    #######################################
    # diamond scheme
    #######################################

    A = vcds.assemble_stiffness_matrix(problem, mesh)

    b = vcds.assemble_source_term(problem, mesh)

    A, b = vcds.treat_boundary_condition(problem, mesh, A, b)
    ua, info = gmres(A, b, tol=1e-13, maxiter=5000)
    if info > 0:
        print(f"Convergence to tolerance not achieved! (#it = {info})")
    elif info < 0:
        print("Illegal input or breakdown!")

    hmesh, error_max, error_l2, error_h1 = vcds.compute_errors(problem, mesh, ua)
    hmeshes.append(hmesh)
    errors_max.append(error_max)
    errors_l2.append(error_l2)
    errors_h1.append(error_h1)


show_errors(hmeshes, errors_max, errors_l2, errors_h1)
