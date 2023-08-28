#include <iostream>
#include <vector>

using namespace std;
class Solution {
public:
   int longestPalindromeSubseq(string s) {
      int n = s.size();
      vector<vector<int>> dp(n, vector<int>(n, 0));

      for(int i = n - 1; i >= 0; --i) {
         for(int j = i; j < n; ++j) {
            if(j == i) {
               dp[i][j] = 1;
               continue;
            }
            if(s[i] == s[j]) {
               dp[i][j] = dp[i + 1][j - 1] + 2;
            } else {
               dp[i][j] = max(dp[i + 1][j], max(dp[i][j - 1],
                                                dp[i + 1][j - 1]));
            }
         }
      }
      return dp[0][n - 1];
   }
};

int main() {
   Solution solution;
   int ans = solution.longestPalindromeSubseq("bbbab");
   cout << ans << endl;
}
