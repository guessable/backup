#!/usr/bin/env python3
# _*_ coding:utf-8 _*_

import torch
import matplotlib.pyplot as plt
import numpy as np
import matplotlib.ticker as ticker
import matplotlib
import scipy.io
from options import Options
from model import Net, PINN
from dataset import Test_data


data = scipy.io.loadmat('./burgers_shock.mat')
t = data['t'].flatten()
x = data['x'].flatten()
Exact = np.real(data['usol'])


class Test():
    def __init__(self, args):
        test_data = Test_data(args.tt)
        self.test_data = test_data()
        self.x = self.test_data.detach().numpy()[:, 0:1]

        # model para
        self.net = Net()
        self.pinn = PINN(self.net)
        model_para = torch.load(
            './checkpoints/BugersEquation/checkpoint.pth.tar')
        self.pinn.load_state_dict(model_para['state'])

        # pred
        pred = self.net(self.test_data)
        self.pred = pred.detach().numpy()

    def plot(self):

        plt.figure()

        plt.rcParams['xtick.direction'] = 'in'
        plt.rcParams['ytick.direction'] = 'in'

        ax1 = plt.subplot(111)

        plt.plot(self.x, self.pred, color='#2b4750',
                 linestyle='--', label='pred', alpha=0.75)
        # ax1.xaxis.set_major_locator(ticker.NullLocator())
        ax1.yaxis.set_major_locator(ticker.MultipleLocator(0.5))
        ax1.yaxis.set_minor_locator(ticker.MultipleLocator(0.1))

        # ax1.spines['top'].set_color('None')
        # ax1.spines['right'].set_color('None')
        ax1.spines['top'].set_alpha(0.25)
        ax1.spines['right'].set_alpha(0.25)

        ax1.tick_params(which='major', width=1.00)
        ax1.tick_params(which='major', length=2)
        ax1.tick_params(which='minor', width=0.5)
        ax1.tick_params(which='minor', length=1.25)
        ax1.patch.set_alpha(0.0)

        # plt.tight_layout()
        ax1.grid(which='major', axis="both",
                 linewidth=0.75, linestyle='-', alpha=0.5)
        ax1.grid(which='minor', axis="both",
                 linewidth=0.25, linestyle='-.', alpha=0.5)

        plt.plot(x, Exact[:, int(args.tt*99/1):int(args.tt*99/1)+1], 'r',
                 label='Exact', alpha=0.75)
        plt.title(f'$t={args.tt}$', fontsize=16)
        plt.legend(fontsize=12, framealpha=0.25)
        plt.xlabel('$x$', fontsize=16)
        plt.ylabel('$u(x,t)$', fontsize=18)
        plt.show()

    def hot_img(self):
        x = np.linspace(-1, 1, 50)
        t = np.linspace(0, 1, 25)
        X, T = np.meshgrid(x, t)
        X1 = X.reshape(-1)
        T1 = T.reshape(-1)
        points = np.c_[X1, T1]
        points = torch.from_numpy(points).float()
        pred = self.net(points)
        pred = pred.detach().numpy()
        pred = pred.reshape(25, 50)
        plt.figure(figsize=(12, 4))
        plt.imshow(pred.T, extent=[0, 1, 1, -1], cmap='coolwarm',
                   interpolation='bilinear', aspect='auto', origin='lower')
        plt.xticks([0, 1])
        plt.yticks([-1, 0, 1])
        plt.colorbar()
        plt.show()


if __name__ == '__main__':
    args = Options().parse()
    test = Test(args)
    test.plot()
    # test.hot_img()
