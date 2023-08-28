#!/usr/bin/env python3
# _*_ coding:utf-8 _*_

import os
import torch
import shutil
import matplotlib.pyplot as plt
import numpy as np


def valid_image(x, t, pred):
    x = x.detach().numpy()
    t = t.detach().numpy()
    pred = pred.detach().numpy()
    fig = plt.figure()
    ax = fig.add_subplot(111, projection='3d')
    ax.plot_surface(t, x, pred, cmap='coolwarm')
    return fig


def save_checkpoints(state, is_best=None,
                     base_dir='checkpoints',
                     save_dir=None):
    if save_dir:
        save_dir = os.path.join(base_dir, save_dir)
        if not os.path.exists(save_dir):
            os.makedirs(save_dir)

    checkpoint = os.path.join(save_dir, 'checkpoint.pth.tar')
    torch.save(state, checkpoint)
    if is_best:
        best_model = os.path.join(save_dir, 'best_model.pth.tar')
        shutil.copyfile(checkpoint, best_model)
