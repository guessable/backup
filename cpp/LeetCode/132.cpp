#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
   int minCut(string s) {
      int n = s.size();
      vector<vector<bool>> f(n, vector<bool>(n, true));

      for(int i = n - 1; i >= 0; i--) {
         for(int j = i; j < n; j++) {
            if(i == j) {
               f[i][j] = true;
            } else if(s[i] == s[j]) {
               f[i][j] = f[i + 1][j - 1];
            } else if(s[i] != s[j]) {
               f[i][j] = false;
            }
         }
      }

      vector<int> dp(n, 0);

      for(int i = 0; i < n; i++) {
         f[0][i] ? dp[i] = 0 : dp[i] = i;
      }

      for(int i = 1; i < n; i++) {
         for(int j = 0; j < i; j++) {
            if(f[j + 1][i]) {
               dp[i] = min(dp[i], dp[j] + 1);
            }
         }
      }

      return dp[n - 1];
   }
};

int main() {
   Solution solution;
   int ans = solution.minCut("bcbabac");
   cout << ans << endl;
}
