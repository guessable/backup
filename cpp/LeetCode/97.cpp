#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
   bool isInterleave(string s1, string s2, string s3) {
      int len1 = s1.size();
      int len2 = s2.size();
      int len3 = s3.size();

      if(len1 + len2 != len3) {
         return false;
      }

      if(s1.empty() || s2.empty() || s3.empty()) {
         return s3 == s1 + s2;
      }

      vector<vector<bool>> dp(len1 + 1, vector<bool>(len2 + 1, false));

      for(int i = 0; i < len1 + 1; i++) {
         if(s1.substr(0, i) == s3.substr(0, i)) {
            dp[i][0] = true;
         }
      }

      for(int j = 0; j < len2 + 1; j++) {
         if(s2.substr(0, j) == s3.substr(0, j)) {
            dp[0][j] = true;
         }
      }

      for(int i = 1; i < len1 + 1; i++) {
         for(int j = 1; j < len2 + 1; j++) {
            dp[i][j] = (dp[i][j - 1] && s2[j - 1] == s3[i + j - 1]) ||
                       (dp[i - 1][j] && s1[i - 1] == s3[i + j - 1]);
         }
      }

      return dp[len1][len2];
   }
};

int main() {
   Solution solution;
   int ans = solution.isInterleave("aa", "ab", "aaba");
   cout << ans << endl;
}
