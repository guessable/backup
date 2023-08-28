#include <iostream>
#include <vector>

using namespace std;
class Solution {
public:
   double myPow(double x, int n) {
      int pow = abs(n);
      double ans = 1.0;
      for(int i = 0; i < pow; ++i) {
         ans *= x;
      }

      return n > 0 ? ans : 1 / ans;
   }
};

int main() {
   Solution solution;
   double ans = solution.myPow(0.00001, 2147483647);
   cout << ans << endl;
}
