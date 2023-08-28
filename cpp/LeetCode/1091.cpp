#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
   vector<vector<int>> direct{{1, 0}, {-1, 0}, {0, 1}, {0, -1},
      {1, 1}, {1, -1}, {-1, 1}, {-1, -1}};
   int shortestPathBinaryMatrix(vector<vector<int>>& grid) {

      if(grid[0][0] == 1) {
         return -1;
      }

      int m = grid.size(), n = grid[0].size();
      int count = 1;
      queue<vector<int>> qe;
      vector<vector<int>> visited(m, vector<int>(n, 0));
      visited[0][0] = 1;
      qe.push(vector<int> {0, 0});

      while(!qe.empty()) {
         int size = qe.size();

         for(int i = 0; i < size; ++i) {
            vector<int> cur = qe.front();
            qe.pop();

            if(cur[0] == m - 1 && cur[1] == n - 1) {
               return count;
            }

            for(int j = 0; j < 8; ++j) {
               int dx = cur[0] + direct[j][0];
               int dy = cur[1] + direct[j][1];

               if(dx >= 0 && dx < m && dy >= 0 &&
                     dy < n && visited[dx][dy] == 0 && grid[dx][dy] == 0) {
                  qe.push(vector<int> {dx, dy});
                  visited[dx][dy] = 1;
               }
            }
         }

         ++count;
      }

      return -1;

   }
};

int main() {
   Solution solution;
   vector<vector<int>> nums{{1, 0, 0}, {1, 1, 0}, {1, 1, 0}};
   int ans = solution.shortestPathBinaryMatrix(nums);
   cout << ans << endl;
}
