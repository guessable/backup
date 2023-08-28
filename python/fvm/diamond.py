#!/usr/bin/env python3
import numpy as np
from utils import normal, area, dist

class Diamond():
    def __init__(self, v, v_prev, v_next, K):
        """ initialization of class Diamond

        Params
        ======
        K:      (2,) ndarray
           center of the prime cell
        v:      (2, ) ndarray
            vertex corresponding to K
        v_prev: (2, ) ndarray
            previous vertex of v
        v_next: (2, ) ndarray
            next vertex of v
        hehs: list

        """
        self.K = K
        self.v = v
        self.v_prev = v_prev
        self.v_next = v_next
        self.sigma_prev = (v+v_prev)/2
        self.sigma_next = (v+v_next)/2
        self.center = (K+v+self.sigma_next+self.sigma_prev)/4     # center of the diamond
        self.norm1 = self._norm1()              # normal vector from K to v
        self.norm2 = self._norm2()              # normal vector from sigma_next to sigma_prev
        self.norm_prev = self._norm_prev()      # normal vector from K to sigma_prev (outside to diamond)
        self.norm_next = self._norm_next()      # normal vector from K to sigma_next (outside to diamond)
        self.norm2 = self._norm2()              # vector from sigma_next to sigma_prev
        self.dist1 = self._dist1()              # distance between K and v
        self.dist2 = self._dist2()              # distance between sigma_next and sigma_prev
        self.area_K = self._area_K()            # D_K
        self.area_v = self._area_v()            # D_v
        self.area = self._area()                # D_K,v
        
    def _norm1(self):
        """normal vector of K->v"""
        return normal(self.v-self.K)

    def _norm2(self):
        """normal vector of sigma_next->sigma_prev"""
        return normal(self.sigma_prev-self.sigma_next)

    def _dist1(self):
        """distance between K and v"""
        return dist(self.K, self.v)

    def _dist2(self):
        """distance between sigma_next and sigma_prev"""
        return dist(self.sigma_prev, self.sigma_next)

    def _norm_prev(self):
        """normal vector of K->sigma_prev"""
        return normal(self.K-self.sigma_prev)

    def _norm_next(self):
        """normal vector of K->sigma_next"""
        return normal(self.sigma_next-self.K)
    
    def _area_K(self):
        return area(self.sigma_next, self.K, self.sigma_prev)

    def _area_v(self):
        return area(self.sigma_prev, self.v, self.sigma_next)

    def _area(self):
        return self._area_K() + self._area_v()
    
    def __str__(self):
        return '\n**********************************************************************\n' \
            + f'K={self.K}\n' \
            + f'v=({self.v[0]:.3f}, {self.v[1]:.3f}), ' \
            + f'v_prev=({self.v_prev[0]:.3f}, {self.v_prev[1]:.3f}), ' \
            + f'v_next=({self.v_next[0]:.3f}, {self.v_next[1]:.3f})\n' \
            + f'center=({self.center[0]:.3f}, {self.center[1]:.3f})\n' \
            + f'norm1=({self.norm1[0]:.3e}, {self.norm1[1]:.3e}), ' \
            + f'norm2=({self.norm2[0]:.3e}, {self.norm2[1]:.3e})\n' \
            + f'norm_prev=({self.norm_prev[0]:.3e}, {self.norm_prev[1]:.3e}), ' \
            + f'norm_next=({self.norm_next[0]:.3e}, {self.norm_next[1]:.3e})\n' \
            + f'dist1={self.dist1:.3e}, dist2={self.dist2:.3e}\n' \
            + f'area={self.area:.3e}, area_K={self.area_K:.3e}, area_v={self.area_v:.3e}'

    def __repr__(self):
        return self.__str__()


if __name__ == '__main__':
    K = np.array([0.5, 0.5])
    v = np.array([1, 1])
    v_prev = np.array([1, 0])
    v_next = np.array([0, 1])
    diamond = Diamond(v, v_prev, v_next, K)
    print(diamond)
