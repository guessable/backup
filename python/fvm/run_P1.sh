#!/bin/sh
./fvem_P1.py --case 1 --mesh triangle_classic | tee -a results/P1.txt
./fvem_P1.py --case 1 --mesh triangle_random  | tee -a results/P1.txt
./fvem_P1.py --case 1 --mesh triangle_uniform | tee -a results/P1.txt
./fvem_P1.py --case 1 --mesh triangle_kershaw | tee -a results/P1.txt

./fvem_P1.py --case 2 --mesh triangle_classic | tee -a results/P1.txt
./fvem_P1.py --case 2 --mesh triangle_random  | tee -a results/P1.txt
./fvem_P1.py --case 2 --mesh triangle_uniform | tee -a results/P1.txt
./fvem_P1.py --case 2 --mesh triangle_kershaw | tee -a results/P1.txt

./fvem_P1.py --case 3 --mesh triangle_classic | tee -a results/P1.txt
./fvem_P1.py --case 3 --mesh triangle_random  | tee -a results/P1.txt
./fvem_P1.py --case 3 --mesh triangle_uniform | tee -a results/P1.txt
./fvem_P1.py --case 3 --mesh triangle_kershaw | tee -a results/P1.txt

./fvem_P1.py --case 4 --mesh triangle_classic | tee -a results/P1.txt
./fvem_P1.py --case 4 --mesh triangle_random  | tee -a results/P1.txt
./fvem_P1.py --case 4 --mesh triangle_uniform | tee -a results/P1.txt
./fvem_P1.py --case 4 --mesh triangle_kershaw | tee -a results/P1.txt

./fvem_P1.py --case 5 --mesh triangle_classic | tee -a results/P1.txt
./fvem_P1.py --case 5 --mesh triangle_random  | tee -a results/P1.txt
./fvem_P1.py --case 5 --mesh triangle_uniform | tee -a results/P1.txt
./fvem_P1.py --case 5 --mesh triangle_kershaw | tee -a results/P1.txt

./fvem_P1.py --case 6 --mesh triangle_classic | tee -a results/P1.txt
./fvem_P1.py --case 6 --mesh triangle_uniform | tee -a results/P1.txt
./fvem_P1.py --case 6 --mesh triangle_kershaw | tee -a results/P1.txt
						
./fvem_P1.py --case 7 --mesh triangle_classic | tee -a results/P1.txt
./fvem_P1.py --case 7 --mesh triangle_uniform | tee -a results/P1.txt
./fvem_P1.py --case 7 --mesh triangle_kershaw | tee -a results/P1.txt

./fvem_P1.py --case 8 --mesh triangle_classic | tee -a results/P1.txt
./fvem_P1.py --case 8 --mesh triangle_uniform | tee -a results/P1.txt
./fvem_P1.py --case 8 --mesh triangle_kershaw | tee -a results/P1.txt

./fvem_P1.py --case 9 --mesh triangle_uniform | tee -a results/P1.txt
./fvem_P1.py --case 9 --mesh triangle_classic | tee -a results/P1.txt

./fvem_P1.py --case 10 --mesh triangle_uniform | tee -a results/P1.txt
./fvem_P1.py --case 10 --mesh triangle_classic | tee -a results/P1.txt
