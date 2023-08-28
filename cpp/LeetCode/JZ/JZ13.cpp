#include <iostream>
#include <vector>
#include <vector>

using namespace std;

class Solution {
public:
   int sum(int n) {
      string s = to_string(n);
      int len = s.size();
      int result = 0;

      for(int i = 0; i < len; i++) {
         result += s[i] - '0';
      }

      return result;
   }

   vector<int> dx{0, 1, -1, 0};
   vector<int> dy{1, 0, 0, -1};
   int count = 1;
   int movingCount(int m, int n, int k) {
      vector<vector<int>> visited(m, vector<int>(n, 0));
      visited[0][0] = 1;
      dfs(visited, m, n, k, 0, 0);
      return count;
   }

   void dfs(vector<vector<int>>& visited, int m, int n, int k, int i, int j) {

      for(int d = 0; d < 4; d++) {
         int newX = i + dx[d];
         int newY = j + dy[d];

         if(newX >= 0 && newX <= m - 1 && newY >= 0 && newY <= n - 1
               && visited[newX][newY] == 0 && sum(newX) + sum(newY) <= k) {
            visited[newX][newY] = 1;
            count++;
            dfs(visited, m, n, k, newX, newY);
         }
      }
   }
};

int main() {
   Solution solution;
   int ans = solution.movingCount(38, 15, 9);
   cout << ans << endl;
}
