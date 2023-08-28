#!/usr/bin/env python3
# _*_ coding:utf-8 _*_

import math
import torch
import torch.nn as nn
import torch.nn.init as init
import scipy

PI = math.pi
xmax = 1
xmin = -1
tmin = 0
tmax = 1


class Net(nn.Module):
    def __init__(self):
        super().__init__()
        self.layer1 = nn.Sequential(nn.Linear(2, 20),
                                    nn.Tanh())
        self.init_weight(self.layer1[0])
        self.layer2 = nn.Sequential(nn.Linear(20, 20),
                                    nn.Tanh())
        self.init_weight(self.layer2[0])
        self.layer3 = nn.Sequential(nn.Linear(20, 20),
                                    nn.Tanh())
        self.init_weight(self.layer3[0])
        self.layer4 = nn.Sequential(nn.Linear(20, 20),
                                    nn.Tanh())
        self.init_weight(self.layer4[0])
        self.layer5 = nn.Sequential(nn.Linear(20, 20),
                                    nn.Tanh())
        self.init_weight(self.layer5[0])
        self.layer6 = nn.Sequential(nn.Linear(20, 20),
                                    nn.Tanh())
        self.init_weight(self.layer6[0])
        self.layer7 = nn.Sequential(nn.Linear(20, 20),
                                    nn.Tanh())
        self.init_weight(self.layer7[0])
        self.layer8 = nn.Sequential(nn.Linear(20, 20),
                                    nn.Tanh())
        self.init_weight(self.layer8[0])
        self.layer9 = nn.Sequential(nn.Linear(20, 20),
                                    nn.Tanh())
        self.init_weight(self.layer9[0])
        self.layer10 = nn.Linear(20, 1)

    def init_weight(self, layer):
        init.xavier_normal_(layer.weight)
        init.constant_(layer.bias, 0.01)

    def forward(self, X):
        '''
        X: point (x,t)

        '''

        # Normilized
        X_max = torch.tensor([xmax, tmax])
        X_min = torch.tensor([xmin, tmin])
        X = (X-X_min)/X_max

        # forward
        out1 = self.layer1(X)
        out2 = self.layer2(out1)
        out3 = self.layer3(out2)
        out4 = self.layer4(out3)
        out5 = self.layer5(out4)
        out6 = self.layer6(out5)
        out7 = self.layer7(out6)
        out8 = self.layer8(out7)
        out9 = self.layer8(out8)
        out10 = self.layer10(out9)

        return out10


class PINN(nn.Module):
    def __init__(self, net):
        super().__init__()
        self.net = net

    def forward(self, X, X_ic, X_bc):
        '''
        X: point in X x T
        X_ic : which t=0
        X_bc : which x=1 0r -1
        '''

        X.requires_grad_(True)

        u = self.net(X)
        u_ic_pred = self.net(X_ic)
        u_ic_true = -1*torch.sin(PI*X_ic[:, 0:1])

        u_bc = self.net(X_bc)

        # grad
        u_x = torch.autograd.grad(
            u, X, grad_outputs=torch.ones_like(u), create_graph=True)[0][:, 0:1]
        u_t = torch.autograd.grad(
            u, X, grad_outputs=torch.ones_like(u), create_graph=True)[0][:, 1:2]
        u_xx = torch.autograd.grad(u_x, X, grad_outputs=torch.ones_like(
            u_x), allow_unused=True, create_graph=True)[0][:, 0:1]

        # res
        f_u = u_t + u*u_x - (0.01/PI)*u_xx
        f_ic = u_ic_pred - u_ic_true
        f_bc = u_bc - 0

        return f_u, f_ic, f_bc


if __name__ == '__main__':
    net = Net()
    pinn = PINN(net)
    for para in pinn.parameters():
        print(para)

