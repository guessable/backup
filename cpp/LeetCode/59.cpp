#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
   vector<vector<int>> generateMatrix(int n) {
      vector<vector<int>> result(n, vector<int>(n, 0));
      vector<vector<int>> direct{{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
      int cur = 1, size = n * n;
      int row = 0, col = 0;
      int dirIndex = 0;

      while(cur <= size) {
         result[row][col] = cur;
         cur++;
         int nextRow = row + direct[dirIndex][0],
             nextCol = col + direct[dirIndex][1];

         if(nextRow < 0 || nextRow >= n || nextCol < 0 || nextCol >= n ||
               result[nextRow][nextCol] != 0) {
            dirIndex = (dirIndex + 1) % 4;
         }

         row = row + direct[dirIndex][0];
         col = col + direct[dirIndex][1];
      }

      return result;
   }
};
int main() {
   Solution solution;
   auto ans = solution.generateMatrix(3);

   for(auto nums : ans) {
      for(auto num : nums) {
         cout << num << " ";
      }

      cout << endl;
   }
}
