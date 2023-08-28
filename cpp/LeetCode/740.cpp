#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
   int rob(vector<int>& nums) {
      int n = nums.size();

      if(n == 1) {
         return nums[0];
      }

      if(n == 2) {
         return max(nums[0], nums[1]);
      }

      vector<int> dp(n, 0);
      int dp0 = nums[0], dp1 = max(nums[0], nums[1]);

      for(int i = 2; i < n; i++) {
         int temp = dp1;
         dp1 = max(dp0 + nums[i], dp1);
         dp0 = temp;
      }

      return dp1;
   }
   int deleteAndEarn(vector<int>& nums) {
      int maxEle = *max_element(nums.begin(), nums.end());
      vector<int> value(maxEle + 1, 0);

      for(int num : nums) {
         value[num] += num;
      }

      return rob(value);
   }
};

int main() {
   Solution solution;
   vector<int> nums{2};
   int ans = solution.deleteAndEarn(nums);
   cout << ans << endl;
}
