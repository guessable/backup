#!/usr/bin/env python3
# _*_ coding:utf-8 _*_

import math
import torch
import numpy as np
import matplotlib.pyplot as plt
from pyDOE import lhs

PI = math.pi
xmax = 1
xmin = -1
tmax = 1
tmin = 0


class Train_data():
    """
    N_train: number of train point
    ic_points: which t=0
    bc_points: which x=1 or -1
    """

    def __init__(self, N_train):
        self.N_train = N_train
        X_max = np.array([xmax, tmax])
        X_min = np.array([xmin, tmin])
        self.res_points = X_min+(X_max-X_min)*lhs(2, self.N_train)

        x_ic = np.linspace(-1, 1, 100)
        t0 = np.zeros_like(x_ic)
        self.ic_points = np.c_[x_ic, t0]
        self.u_ic = -1*np.sin(PI*x_ic)

        x_bc = np.random.choice([-1, 1], 100, replace=True)
        t_bc = np.linspace(0, 1, 100)
        self.bc_points = np.c_[x_bc, t_bc]

    def __call__(self, mode='res'):
        if mode == 'res':
            res_points = torch.from_numpy(self.res_points).float()
            return res_points
        elif mode == 'ic':
            ic_points = torch.from_numpy(self.ic_points).float()
            return ic_points
        elif mode == 'bc':
            bc_points = torch.from_numpy(self.bc_points).float()
            return bc_points
        else:
            print('error')


class Valid_data():
    def __init__(self):
        x = np.linspace(-1, 1, 40)
        t = np.linspace(0, 1, 20)
        X, T = np.meshgrid(x, t)
        X = X.reshape(-1)
        T = T.reshape(-1)
        self.valid_points = np.c_[X, T]

    def __call__(self):
        valid_points = torch.from_numpy(self.valid_points).float()
        return valid_points


class Test_data():
    """
    tt: points which t=tt
    """

    def __init__(self, tt):
        self.tt = tt
        x = np.linspace(-1, 1, 500)
        t = self.tt*np.ones_like(x)
        self.test_points = np.c_[x, t]

    def __call__(self):
        test_points = torch.from_numpy(self.test_points).float()
        return test_points


if __name__ == '__main__':
    traindata = Train_data(5000)
    x = traindata.res_points[:, 0:1]
    t = traindata.res_points[:, 1:2]
    plt.scatter(t, x)
    plt.show()
    # valid = Valid_data()
    # print(valid())
    # test = Test_data(0.5)
    # print(test())
    # print(traindata('bc'))
