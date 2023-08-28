#!/bin/sh
./vertex_centered_diamond.py --case 1 --mesh triangle_classic       | tee -a results/diamond.txt
./vertex_centered_diamond.py --case 1 --mesh triangle_random        | tee -a results/diamond.txt
./vertex_centered_diamond.py --case 1 --mesh triangle_uniform       | tee -a results/diamond.txt
./vertex_centered_diamond.py --case 1 --mesh triangle_kershaw       | tee -a results/diamond.txt
./vertex_centered_diamond.py --case 1 --mesh quadrangle_uniform     | tee -a results/diamond.txt
./vertex_centered_diamond.py --case 1 --mesh quadrangle_random      | tee -a results/diamond.txt
./vertex_centered_diamond.py --case 1 --mesh quadrangle_kershaw     | tee -a results/diamond.txt

./vertex_centered_diamond.py --case 2 --mesh triangle_classic       | tee -a results/diamond.txt
./vertex_centered_diamond.py --case 2 --mesh triangle_random	      | tee -a results/diamond.txt
./vertex_centered_diamond.py --case 2 --mesh triangle_uniform	      | tee -a results/diamond.txt
./vertex_centered_diamond.py --case 2 --mesh triangle_kershaw	      | tee -a results/diamond.txt
./vertex_centered_diamond.py --case 2 --mesh quadrangle_uniform     | tee -a results/diamond.txt
./vertex_centered_diamond.py --case 2 --mesh quadrangle_random      | tee -a results/diamond.txt
./vertex_centered_diamond.py --case 2 --mesh quadrangle_kershaw     | tee -a results/diamond.txt

./vertex_centered_diamond.py --case 3 --mesh triangle_classic       | tee -a results/diamond.txt
./vertex_centered_diamond.py --case 3 --mesh triangle_random	      | tee -a results/diamond.txt
./vertex_centered_diamond.py --case 3 --mesh triangle_uniform	      | tee -a results/diamond.txt
./vertex_centered_diamond.py --case 3 --mesh triangle_kershaw	      | tee -a results/diamond.txt
./vertex_centered_diamond.py --case 3 --mesh quadrangle_uniform     | tee -a results/diamond.txt
./vertex_centered_diamond.py --case 3 --mesh quadrangle_random      | tee -a results/diamond.txt
./vertex_centered_diamond.py --case 3 --mesh quadrangle_kershaw     | tee -a results/diamond.txt

./vertex_centered_diamond.py --case 4 --mesh triangle_classic      | tee -a results/diamond.txt
./vertex_centered_diamond.py --case 4 --mesh triangle_random	     | tee -a results/diamond.txt
./vertex_centered_diamond.py --case 4 --mesh triangle_uniform	     | tee -a results/diamond.txt
./vertex_centered_diamond.py --case 4 --mesh triangle_kershaw	     | tee -a results/diamond.txt
./vertex_centered_diamond.py --case 4 --mesh quadrangle_uniform    | tee -a results/diamond.txt
./vertex_centered_diamond.py --case 4 --mesh quadrangle_random     | tee -a results/diamond.txt
./vertex_centered_diamond.py --case 4 --mesh quadrangle_kershaw    | tee -a results/diamond.txt

./vertex_centered_diamond.py --case 5 --mesh triangle_classic      | tee -a results/diamond.txt
./vertex_centered_diamond.py --case 5 --mesh triangle_random	     | tee -a results/diamond.txt
./vertex_centered_diamond.py --case 5 --mesh triangle_uniform	     | tee -a results/diamond.txt
./vertex_centered_diamond.py --case 5 --mesh triangle_kershaw	     | tee -a results/diamond.txt
./vertex_centered_diamond.py --case 5 --mesh quadrangle_uniform    | tee -a results/diamond.txt
./vertex_centered_diamond.py --case 5 --mesh quadrangle_random     | tee -a results/diamond.txt
./vertex_centered_diamond.py --case 5 --mesh quadrangle_kershaw    | tee -a results/diamond.txt

./vertex_centered_diamond.py --case 6 --mesh triangle_classic     | tee -a results/diamond.txt
./vertex_centered_diamond.py --case 6 --mesh triangle_uniform	    | tee -a results/diamond.txt
./vertex_centered_diamond.py --case 6 --mesh triangle_kershaw	    | tee -a results/diamond.txt
./vertex_centered_diamond.py --case 6 --mesh quadrangle_uniform   | tee -a results/diamond.txt
./vertex_centered_diamond.py --case 6 --mesh quadrangle_random2   | tee -a results/diamond.txt
./vertex_centered_diamond.py --case 6 --mesh quadrangle_kershaw   | tee -a results/diamond.txt
								    
./vertex_centered_diamond.py --case 7 --mesh triangle_classic     | tee -a results/diamond.txt
./vertex_centered_diamond.py --case 7 --mesh triangle_uniform	    | tee -a results/diamond.txt
./vertex_centered_diamond.py --case 7 --mesh triangle_kershaw	    | tee -a results/diamond.txt
./vertex_centered_diamond.py --case 7 --mesh quadrangle_uniform   | tee -a results/diamond.txt
./vertex_centered_diamond.py --case 7 --mesh quadrangle_random2   | tee -a results/diamond.txt
./vertex_centered_diamond.py --case 7 --mesh quadrangle_kershaw   | tee -a results/diamond.txt
								    
./vertex_centered_diamond.py --case 8 --mesh triangle_classic     | tee -a results/diamond.txt
./vertex_centered_diamond.py --case 8 --mesh triangle_uniform	    | tee -a results/diamond.txt
./vertex_centered_diamond.py --case 8 --mesh triangle_kershaw	    | tee -a results/diamond.txt
./vertex_centered_diamond.py --case 8 --mesh quadrangle_uniform   | tee -a results/diamond.txt
./vertex_centered_diamond.py --case 8 --mesh quadrangle_random2   | tee -a results/diamond.txt
./vertex_centered_diamond.py --case 8 --mesh quadrangle_kershaw   | tee -a results/diamond.txt
								    
./vertex_centered_diamond.py --case 9 --mesh triangle_uniform       | tee -a results/diamond.txt
./vertex_centered_diamond.py --case 9 --mesh triangle_classic	      | tee -a results/diamond.txt
./vertex_centered_diamond.py --case 9 --mesh quadrangle_uniform     | tee -a results/diamond.txt
./vertex_centered_diamond.py --case 9 --mesh quadrangle_random2     | tee -a results/diamond.txt
								      
./vertex_centered_diamond.py --case 10 --mesh triangle_uniform       | tee -a results/diamond.txt
./vertex_centered_diamond.py --case 10 --mesh triangle_classic       | tee -a results/diamond.txt
./vertex_centered_diamond.py --case 10 --mesh quadrangle_uniform     | tee -a results/diamond.txt
./vertex_centered_diamond.py --case 10 --mesh quadrangle_trapezoidal | tee -a results/diamond.txt 
