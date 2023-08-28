#include <iostream>
#include <vector>

using namespace std;
class Solution {
public:
   void rotate(vector<vector<int>>& matrix) {
      int n = matrix.size(), mid = n / 2;
      for(int i = 0; i < mid; ++i) {
         swap(matrix[i], matrix[n - i - 1]);
      }
      for(int i = n - 1; i >= 0; ++i) {
         for(int j = i; j < n; ++j) {
            swap(matrix[i][j], matrix[j][i]);
         }
      }
   }
};
