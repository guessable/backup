#include <iostream>
#include <vector>
#include <map>

using namespace std;

class Solution {
public:
   int numWays(int n, vector<vector<int>>& relation, int k) {
      vector<vector<int>> dp(n, vector<int>(k + 1, 0));

      for(int i = 1; i < k + 1; i++) {
         for(auto nums : relation) {
            if(i == 1 && nums[0] == 0) {
               dp[nums[1]][1] += 1;
            } else {
               dp[nums[1]][i] += dp[nums[0]][i - 1];
            }
         }
      }

      return dp[n - 1][k];
   }
};

int main() {
   Solution solution;
   vector<vector<int>> test{{0, 2}, {2, 1}, {3, 4}, {2, 3}, {1, 4}, {2, 0}, {0, 4}};
   int ans = solution.numWays(5, test, 3);
   cout << ans << endl;
}
