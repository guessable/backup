#include <iostream>
#include <vector>

using namespace std;
class Solution {
public:
   int candy(vector<int>& ratings) {
      int n = ratings.size();
      vector<int> leftVal(n, 1);
      for(int i = 0; i < n; ++i) {
         if(i > 0 && ratings[i] > ratings[i - 1]) {
            leftVal[i] = leftVal[i - 1] + 1;
         }
      }
      int rightVal = 1, ret = 0;
      for(int i = n - 1; i >= 0; --i) {
         if(i < n - 1 && ratings[i] > ratings[i + 1]) {
            ++rightVal;
         } else {
            rightVal = 1;
         }
         ret += max(rightVal, leftVal[i]);
      }
      return ret;
   }
};

int main() {
   Solution solution;
   vector<int> nums{1, 2, 87, 87, 87, 2, 1};
   int ans = solution.candy(nums);
   cout << ans << endl;
}
