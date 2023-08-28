#include <iostream>
#include <vector>

using namespace std;
class Solution {
   int mod = 1337;
public:
   int superPow(int a, vector<int>& b) {
      if(b.empty()) {
         return 1;
      }
      int last = b.back();
      b.pop_back();
      int part1 = pow(a, last);
      int part2 = pow(superPow(a, b), 10);
      return (part1 * part2) % mod;
   }
   int pow(int a, int p) {
      if(p == 0) {
         return 1;
      }
      a %= mod;

      if(p % 2 == 1) {
         return (a * pow(a, p - 1)) % mod;
      } else {
         return (pow(a, p / 2) * pow(a, p / 2)) % mod;
      }
   }
};
