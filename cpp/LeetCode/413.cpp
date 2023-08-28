#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
   int numberOfArithmeticSlices(vector<int>& nums) {
      int n = nums.size();

      if(n < 3) {
         return 0;
      }

      vector<int> dp(n, 1);
      dp[1] = 2;

      for(int i = 2; i < n; i++) {
         if(nums[i] - nums[i - 1] == nums[i - 1] - nums[i - 2]) {
            dp[i] = dp[i - 1] + 1;
         } else {
            dp[i] = 2;
         }
      }

      int result = 0;

      for(int i = 0; i < n; i++) {
         if(dp[i] >= 3) {
            result += (dp[i] - 2);
         }
      }

      return result;
   }
};

int main() {
   Solution solution;
   vector<int> test{1};
   int ans = solution.numberOfArithmeticSlices(test);
   cout << ans << endl;
}
