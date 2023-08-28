#include <iostream>
#include <vector>
#include <string>

using namespace std;
class Solution {
public:
   int numDecodings(string s) {
      int n = s.size();
      vector<int> dp(n + 1, 1);
      s[0] != '0' ? dp[1] = 1 : dp[1] = 0;

      for(int i = 2; i <= n; ++i) {
         if(s[i - 1] == '0') {
            if(s[i - 2] == '1' || s[i - 2] == '2') {
               dp[i] = dp[i - 2];
            } else {
               dp[i] = 0;
            }
         } else {
            if(s[i - 2] != '0' &&
                  10 * (s[i - 2] - '0') + (s[i - 1] - '0') <= 26) {
               dp[i] = dp[i - 1] + dp[i - 2];
            } else {
               dp[i] = dp[i - 1];
            }
         }

      }

      return dp[n];
   }
};

int main() {
   Solution solution;
   int ans = solution.numDecodings("2611055971756562");
   cout << ans << endl;
}
