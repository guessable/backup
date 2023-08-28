#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
class Solution {
public:
   int minPairSum(vector<int>& nums) {
      sort(nums.begin(), nums.end());
      int n = nums.size(), ans = 0;
      for(int i = 0, j = n - 1; j > i; ++i, --j) {
         ans = max(ans, nums[i] + nums[j]);
      }
      return ans;
   }
};
