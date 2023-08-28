#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
   bool searchMatrix(vector<vector<int>>& matrix, int target) {
      int m = matrix.size(), n = matrix[0].size();
      int left = 0, right = m - 1;

      while(left < right) {
         int mid = (left + right) / 2;

         if(matrix[mid][n - 1] == target) {
            return true;
         } else if(matrix[mid][n - 1] < target) {
            left = mid + 1;
         } else if(matrix[mid][n - 1] > target) {
            right = mid;
         }
      }

      if(left != right) {
         return false;
      }

      int leftPtr = 0, rightPtr = n - 1;

      while(leftPtr <= rightPtr) {
         int mid = (leftPtr + rightPtr) / 2;

         if(matrix[left][mid] == target) {
            return true;
         } else if(matrix[left][mid] > target) {
            rightPtr = mid - 1;
         } else if(matrix[left][mid] < target) {
            leftPtr = mid + 1;
         }
      }

      return false;
   }
};

int main() {
   Solution solution;
   vector<vector<int>> matrix{{1, 3, 5, 7}};
   int ans = solution.searchMatrix(matrix, 3);
   cout << ans << endl;
}
