#include <iostream>
#include <vector>

using namespace std;
class Solution {
public:
   int translateNum(int num) {
      string str = to_string(num);
      int n = str.size();
      vector<int> dp(n + 1, 0);
      dp[0] = 1, dp[1] = 1;


      for(int i = 2; i <= n; ++i) {
         dp[i] += dp[i - 1];

         if(str[i - 2] != '0' && 10 * (str[i - 2] - '0') +
               (str[i - 1] - '0') < 26 &&
               10 * (str[i - 2] - '0') + (str[i - 1] - '0') > 0) {
            dp[i] += dp[i - 2];
         }
      }

      return dp[n];

   }
};

int main() {
   Solution solution;
   int ans = solution.translateNum(506);
   cout << ans << endl;
}
