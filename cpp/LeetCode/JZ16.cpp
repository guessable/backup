#include <iostream>
#include <vector>

using namespace std;
class Solution {
public:
   double myPow(double x, long n) {
      if (!n) {
         return 1;
      }
      if (n < 0) {
         n = -n, x = 1 / x;
      }
      return n & 1 ? x * myPow(x * x, n >> 1) : myPow(x * x, n >> 1);
   }
};

int main() {
   int a = 5;
   a >>= 1;
   cout << a << endl;
}
