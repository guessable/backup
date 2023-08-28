#!/bin/sh

./fvem_Q1.py --case 1 --mesh quadrangle_uniform | tee -a results/Q1.txt
./fvem_Q1.py --case 1 --mesh quadrangle_random  | tee -a results/Q1.txt
./fvem_Q1.py --case 1 --mesh quadrangle_kershaw | tee -a results/Q1.txt

./fvem_Q1.py --case 2 --mesh quadrangle_uniform | tee -a results/Q1.txt
./fvem_Q1.py --case 2 --mesh quadrangle_random	| tee -a results/Q1.txt
./fvem_Q1.py --case 2 --mesh quadrangle_kershaw	| tee -a results/Q1.txt


./fvem_Q1.py --case 3 --mesh quadrangle_uniform | tee -a results/Q1.txt
./fvem_Q1.py --case 3 --mesh quadrangle_random	| tee -a results/Q1.txt
./fvem_Q1.py --case 3 --mesh quadrangle_kershaw	| tee -a results/Q1.txt

./fvem_Q1.py --case 4 --mesh quadrangle_uniform | tee -a results/Q1.txt
./fvem_Q1.py --case 4 --mesh quadrangle_random	| tee -a results/Q1.txt
./fvem_Q1.py --case 4 --mesh quadrangle_kershaw	| tee -a results/Q1.txt


./fvem_Q1.py --case 5 --mesh quadrangle_uniform | tee -a results/Q1.txt
./fvem_Q1.py --case 5 --mesh quadrangle_random	| tee -a results/Q1.txt
./fvem_Q1.py --case 5 --mesh quadrangle_kershaw	| tee -a results/Q1.txt

./fvem_Q1.py --case 6 --mesh quadrangle_uniform | tee -a results/Q1.txt
./fvem_Q1.py --case 6 --mesh quadrangle_random2	| tee -a results/Q1.txt
./fvem_Q1.py --case 6 --mesh quadrangle_kershaw	| tee -a results/Q1.txt

./fvem_Q1.py --case 7 --mesh quadrangle_uniform | tee -a results/Q1.txt
./fvem_Q1.py --case 7 --mesh quadrangle_random2	| tee -a results/Q1.txt
./fvem_Q1.py --case 7 --mesh quadrangle_kershaw	| tee -a results/Q1.txt


./fvem_Q1.py --case 8 --mesh quadrangle_uniform | tee -a results/Q1.txt
./fvem_Q1.py --case 8 --mesh quadrangle_random2	| tee -a results/Q1.txt
./fvem_Q1.py --case 8 --mesh quadrangle_kershaw	| tee -a results/Q1.txt

./fvem_Q1.py --case 9 --mesh quadrangle_uniform | tee -a results/Q1.txt
./fvem_Q1.py --case 9 --mesh quadrangle_random2	| tee -a results/Q1.txt

./fvem_Q1.py --case 10 --mesh quadrangle_uniform     | tee -a results/Q1.txt
./fvem_Q1.py --case 10 --mesh quadrangle_trapezoidal | tee -a results/Q1.txt


