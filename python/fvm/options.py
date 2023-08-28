#!/usr/bin/env python
import argparse


class Options(object):
    def __init__(self):
        parser = argparse.ArgumentParser()

        parser.add_argument(
            "--mesh", type=str, default="triangle_uniform", help="mesh type"
        )
        #                         'triangle_uniform', 'triangle_classic', 'triangle_kershaw',
        #                         'quadrangle_uniform', 'quadrangle_kershaw', 'quadrangle_trapezoidal',
        #                         'quadrangle_random1', 'quadrangle_random2', 'quadrangle_shashkov'
        parser.add_argument(
            "--verbose", type=bool, default=False, help="If True, print the detail."
        )
        parser.add_argument("--case", type=int, default=9, help="problem case")
        self.parser = parser

    def parse(self):
        args = self.parser.parse_args()
        return args


if __name__ == "__main__":
    args = Options().parse()
    print(args)
