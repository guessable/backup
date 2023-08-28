#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
   vector<int> largestDivisibleSubset(vector<int>& nums) {
      int n = nums.size();
      sort(nums.begin(), nums.end());
      vector<vector<int>> dp(n, vector<int> {});
      vector<int> ans{nums[0]};
      dp[0] = ans;

      for(int i = 1; i < n; i++) {
         for(int j = 0; j < i; j++) {
            if(nums[i] % nums[j] == 0) {

               int len1 = dp[i].size();
               int len2 = dp[j].size();

               if(len2 >= len1) {
                  dp[i] = dp[j];
               }

            }

         }

         dp[i].push_back(nums[i]);
         int len3 = dp[i].size();
         int len4 = ans.size();

         if(len3 >= len4) {
            ans = dp[i];
         }
      }

      return ans;
   }
};

int main() {
   Solution solution;
   vector<int> nums{3, 4, 16, 8};
   auto n = solution.largestDivisibleSubset(nums);

   for(int i : n) {
      cout << i << endl;
   }
}
