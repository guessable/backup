#include <iostream>
#include <vector>
#include <map>

using namespace std;

class Solution {
public:
   int findNumberOfLIS(vector<int>& nums) {
      int n = nums.size();
      int result = 1;
      vector<int> dp(n, 1);

      for(int i = 1; i < n; i++) {
         for(int j = 0; j < i; j++) {
            if(nums[i] > nums[j]) {
               dp[i] = max(dp[j] + 1, dp[i]);
            }
         }

         result = max(result, dp[i]);
      }

      vector<int> dp2(n, 0);
      dp2[0] = 1;

      for(int i = 1; i < n; i++) {
         for(int j = 0; j < i; j++) {
            if(nums[i] > nums[j] && dp[j] == (dp[i] - 1)) {
               dp2[i] += dp2[j];
            }
         }

         if(dp2[i] == 0) {
            dp2[i] = 1;
         }
      }

      int count = 0;

      for(int i = 0; i < n; i++) {
         if(dp[i] == result) {
            count += dp2[i];
         }
      }

      return count;

   }
};

int main() {
   Solution solution;
   vector<int> test{2, 2, 2, 2, 2};
   int ans = solution.findNumberOfLIS(test);
   cout << ans << endl;
}
