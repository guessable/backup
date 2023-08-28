#!/usr/bin/env python3
# _*_ coding:utf-8 _*_

import argparse

import torch
import torch.nn as nn


class Options():

    def __init__(self):
        parser = argparse.ArgumentParser()

        parser.add_argument('--no_cuda',
                            action='store_true',
                            default=False,
                            help='Disables cuda training')
        parser.add_argument('--N_train',
                            type=int,
                            default=3000,
                            help='Number of train data')
        parser.add_argument('--lr',
                            type=float,
                            default=0.001,
                            help='learning rate')
        parser.add_argument('--epochs_Adam',
                            type=int,
                            default=2000,
                            help='epochs for Adam')
        parser.add_argument('--epochs_LBFGS',
                        type=int,
                            default=200,
                            help='epochs for LBFGS')
        parser.add_argument('--tt',
                            type=float,
                            default=0,
                            help='test points which t=tt')
        parser.add_argument('--resume',
                            type=str,
                            default=None,
                            help='put the path to resuming file if needed')
        self.parser = parser

    def parse(self):
        args = self.parser.parse_args()
        args.cuda = not args.no_cuda and torch.cuda.is_available()
        if args.cuda:
            args.device = 'cuda'
        else:
            args.device = 'cpu'

        return args


if __name__ == '__main__':
    args = Options().parse()
    print(args.lr)
