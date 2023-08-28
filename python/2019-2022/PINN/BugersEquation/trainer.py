#!/usr/bin/env python3
# _*_ coding:utf-8 _*_

import math
import time
import torch
import torch.nn as nn
import torch.optim as optim

from torch.utils.tensorboard import SummaryWriter
from model import Net, PINN
from dataset import Train_data, Valid_data
from utils import save_checkpoints, valid_image
from options import Options

PI = math.pi
xmax = 1
xmin = -1
tmax = 1
tmin = 0


class Trainer:
    def __init__(self, args):
        self.lr = args.lr
        self.epochs_Adam = args.epochs_Adam
        self.epochs_LBFGS = args.epochs_LBFGS
        self.device = args.device
        self.N_train = args.N_train

        # Network
        self.net = Net()
        self.pinn = PINN(self.net)

        # Criterion
        self.criterion = nn.MSELoss()

        # optimizer
        self.optim_adam = optim.Adam(self.pinn.parameters(), lr=self.lr)
        self.optim_lbfgs = optim.LBFGS(self.pinn.parameters(), lr=self.lr)
        self.lr_scheduler = optim.lr_scheduler.StepLR(
            self.optim_adam, step_size=2000, gamma=0.5
        )

        # dataset
        self.train_data = Train_data(self.N_train)
        self.valid_data = Valid_data()

        self.res_points = self.train_data("res")
        self.ic_points = self.train_data("ic")
        self.bc_points = self.train_data("bc")

        self.valid_points = self.valid_data()

    def train(self):
        tt = time.time()
        step = 0
        best_loss = 10e-4
        self.pinn.to(self.device)
        self.net.to(self.device)
        self.writer = SummaryWriter(comment="BugersEquation")

        print("-------Start Training-------")
        for epoch in range(self.epochs_Adam):
            train_loss = self._train_adam(epoch)

            if (epoch + 1) % 50 == 0:
                print(
                    f"Adam--",
                    f"epoch:{epoch+1}/{self.epochs_Adam+self.epochs_LBFGS}",
                    f"train loss:{train_loss:.4e}",
                    f"lr:{self.lr_scheduler.get_lr()[0]:.2e}",
                    f"ellapsed:{time.time()-tt}",
                )
            tt = time.time()

            if (epoch + 1) % 100 == 0:
                step += 1
                valid_loss = self._valid(step)
                is_best = valid_loss < best_loss

                print(f"Adam--", f"valid_loss:{valid_loss:.4e}")

                state = {
                    "epoch": epoch,
                    "state": self.pinn.state_dict(),
                    "best_loss": valid_loss,
                }
                save_checkpoints(state, is_best, save_dir="BugersEquation")

        for epoch in range(self.epochs_Adam, self.epochs_Adam + self.epochs_LBFGS):
            train_loss = self._train_lbfgs(epoch)

            if (epoch + 1) % 5 == 0:
                print(
                    f"LBFGS---",
                    f"epoch:{epoch+1}/{self.epochs_Adam+self.epochs_LBFGS}",
                    f"train_loss:{train_loss:.4e}",
                    f"lr:{self.lr_scheduler.get_lr()[0]:.2e}",
                    f"ellapsed:{time.time()-tt}",
                )
                tt = time.time()

            if (epoch + 1) % 10 == 0:
                step += 1
                valid_loss = self._valid(step)
                is_best = valid_loss < best_loss

                print(f"LBFGS---", f"valid_loss:{valid_loss:.4e}")

                state = {
                    "epoch": epoch,
                    "state": self.pinn.state_dict(),
                    "best_loss": valid_loss,
                }
                save_checkpoints(state, is_best, save_dir="BugersEquation")
        self.writer.close()
        print("-------Train Complete-------")

    def _train_adam(self, epoch):
        self.net.train()
        self.pinn.train()
        self.res_points.to(self.device)
        self.ic_points.to(self.device)
        self.bc_points.to(self.device)

        self.optim_adam.zero_grad()

        # forward
        f_u, f_ic, f_bc = self.pinn(self.res_points, self.ic_points, self.bc_points)
        # loss
        loss1 = self.criterion(f_u, torch.zeros_like(f_u))
        loss2 = self.criterion(f_ic, torch.zeros_like(f_ic))
        loss3 = self.criterion(f_bc, torch.zeros_like(f_bc))

        loss = loss1 + loss2 + loss3

        # backward
        loss.backward()
        self.optim_adam.step()
        self.lr_scheduler.step()

        train_loss = loss.item()
        self.writer.add_scalar("train loss", train_loss, epoch)
        return train_loss

    def _train_lbfgs(self, epoch):
        self.net.train()
        self.pinn.train()
        self.res_points.to(self.device)
        self.ic_points.to(self.device)
        self.bc_points.to(self.device)

        def closure():
            self.optim_lbfgs.zero_grad()

            # forward
            f_u, f_ic, f_bc = self.pinn(self.res_points, self.ic_points, self.bc_points)
            # loss
            loss1 = self.criterion(f_u, torch.zeros_like(f_u))
            loss2 = self.criterion(f_ic, torch.zeros_like(f_ic))
            loss3 = self.criterion(f_bc, torch.zeros_like(f_bc))

            loss = loss1 + loss2 + loss3

            loss.backward()
            return loss

        # backward
        self.optim_lbfgs.step(closure)
        train_loss = closure().item()

        self.writer.add_scalar("train loss", train_loss, epoch)

        return train_loss

    def _valid(self, step):
        self.pinn.eval()
        self.net.eval()

        self.valid_points.requires_grad_(True)
        u = self.net(self.valid_points)

        u_x = torch.autograd.grad(
            u, self.valid_points, grad_outputs=torch.ones_like(u), create_graph=True
        )[0][:, 0:1]
        u_t = torch.autograd.grad(
            u, self.valid_points, grad_outputs=torch.ones_like(u), create_graph=True
        )[0][:, 1:2]
        u_xx = torch.autograd.grad(
            u_x,
            self.valid_points,
            grad_outputs=torch.ones_like(u_x),
            allow_unused=True,
            create_graph=True,
        )[0][:, 0:1]

        f_u = u_t + u * u_x - (0.01 / PI) * u_xx

        loss = self.criterion(f_u, torch.zeros_like(f_u))

        valid_loss = loss.item()
        self.writer.add_scalar("valid loss", valid_loss, step)

        # image
        x = self.valid_points[:, 0:1].view(20, 40)
        t = self.valid_points[:, 1:2].view(20, 40)
        u = u.view(20, 40)
        fig = valid_image(x, t, u)
        self.writer.add_figure("Pred", fig, global_step=step)

        return valid_loss


if __name__ == "__main__":
    args = Options().parse()
    trainer = Trainer(args)
    trainer.train()
