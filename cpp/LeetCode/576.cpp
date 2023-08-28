#include <iostream>
#include <vector>

using namespace std;
class Solution {
public:
   int maxMove = 0, m = 0, n = 0;
   vector<vector<vector<int>>> memo;
   const int mod = 1e9 + 7;
   int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
      vector<vector<vector<int>>> memo(55, vector<vector<int>>
                                       (55, vector<int>(55, -1)));
      this->memo = memo;
      this->maxMove = maxMove;
      this->m = m;
      this->n = n;
      return dfs(startRow, startColumn, 0);
   }

   long dfs(int i, int j, int count) {
      if(count > maxMove) {
         return 0;
      }
      if(i < 0 || i >= m || j < 0 || j >= n) {
         return 1;
      }
      if(memo[i][j][count] != -1) {
         return memo[i][j][count];
      }
      memo[i][j][count] = (dfs(i + 1, j, count + 1) + dfs(i - 1, j, count + 1)
                           + dfs(i, j - 1, count + 1) +
                           dfs(i, j + 1, count + 1)) % mod;
      return memo[i][j][count];
   }

};
