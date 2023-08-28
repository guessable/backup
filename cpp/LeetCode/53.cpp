#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
   vector<vector<int>> direct{{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
   vector<int> ans;
   vector<int> spiralOrder(vector<vector<int>>& matrix) {
      int m = matrix.size(), n = matrix[0].size(), d = 0, count = 0;
      int row = 0, col = 0;

      while(count < m * n) {
         ++count;
         ans.push_back(matrix[row][col]);
         matrix[row][col] = 101;
         int newRow = row + direct[d][0];
         int newCol = col + direct[d][1];

         if(newRow > m - 1 || newRow < 0 || newCol > n - 1 || newCol < 0
               || matrix[newRow][newCol] == 101) {
            d = (d + 1) % 4;
         }

         row = row + direct[d][0];
         col = col + direct[d][1];
      }

      return ans;
   }
};

int main() {
   Solution solution;
   vector<vector<int>> matrix{{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}};
   auto nums = solution.spiralOrder(matrix);

   for(int num : nums) {
      cout << num << " ";
   }
}
