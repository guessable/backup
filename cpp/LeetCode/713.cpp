#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
   int numSubarrayProductLessThanK(vector<int>& nums, int k) {
      int n = nums.size(), l = 0, r = 0, mul = 1, count = 0;

      if(k == 0) {
         return 0;
      }

      while(r < n) {
         mul *= nums[r];

         while(mul >= k && l <= r) {
            mul /= nums[l];
            l++;
         }

         int len = r - l + 1;
         count += len;
         r++;
      }

      return count;
   }
};

int main() {
   Solution solution;
   vector<int> nums{1, 1, 1, 1};
   int k = 2;
   int ans = solution.numSubarrayProductLessThanK(nums, k);
   cout << ans << endl;
}
