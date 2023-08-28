#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
   int findLength(vector<int>& nums1, vector<int>& nums2) {
      int m = nums1.size(), n = nums2.size(), result = 0;
      vector<vector<int>> dp(m, vector<int>(n, 0));

      for(int i = 0; i < m; i++) {
         if(nums1[i] == nums2[0]) {
            dp[i][0] = 1;
            result = 1;
         }
      }

      for(int j = 0; j < n; j++) {
         if(nums1[0] == nums2[j]) {
            dp[0][j] = 1;
            result = 1;
         }
      }

      for(int i = 1; i < m; i++) {
         for(int j = 1; j < n; j++) {
            if(nums1[i] == nums2[j]) {
               dp[i][j] = dp[i - 1][j - 1] + 1;
            } else {
               dp[i][j] = 0;
            }

            result = max(result, dp[i][j]);
         }
      }

      return result;
   }
};

int main() {
   Solution solution;
   vector<int> nums1{1, 4, 4, 4, 7};
   vector<int> nums2{3, 2, 1, 4, 4, 4, 7};
   int ans = solution.findLength(nums1, nums2);
   cout << ans << endl;
}
