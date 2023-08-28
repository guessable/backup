#include <iostream>
#include <vector>

using namespace std;
class Solution {
public:
   void setZeroes(vector<vector<int>>& matrix) {
      int m = matrix.size(), n = matrix[0].size();
      bool flagRow = false, flagCol = false;
      for(int i = 0; i < m; ++i) {
         if(!matrix[i][0]) {
            flagRow = true;
            break;
         }
      }
      for(int j = 0; j < n; ++j) {
         if(!matrix[0][j]) {
            flagCol = true;
            break;
         }
      }

      for(int i = 1; i < m; ++i) {
         for(int j = 1; j < n; ++j) {
            if(!matrix[i][j]) {
               matrix[i][0] = 0;
               matrix[0][j] = 0;
            }
         }
      }

      for(int i = 1; i < m; ++i) {
         for(int j = 1; j < n; ++j) {
            if(!matrix[i][0] || !matrix[0][j]) {
               matrix[i][j] = 0;
            }
         }
      }

      for(int i = 0; i < m; ++i) {
         if(flagRow) {
            matrix[i][0] = 0;
         }
      }

      for(int j = 0; j < n; ++j) {
         if(flagCol) {
            matrix[0][j] = 0;
         }
      }
   }
};
