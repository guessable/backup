#include <iostream>
#include <vector>

using namespace std;
class Solution {
public:
   bool isValidSudoku(vector<vector<char>>& board) {
      vector<vector<int>> row(9, vector<int>(9, 0));
      vector<vector<int>> col(9, vector<int>(9, 0));
      vector<vector<int>> three(9, vector<int>(9, 0));

      for(int i = 0; i < 9; ++i) {
         for(int j = 0; j < 9; ++j) {
            if(board[i][j] == '.') {
               continue;
            }
            int cur = board[i][j] - '1';
            int index = 3 * (i / 3) + j / 3;
            if(row[i][cur] == 1 || col[cur][j] == 1 ||
                  three[index][cur] == 1) {
               return false;
            }
            row[i][cur] = 1;
            col[cur][j] = 1;
            three[index][cur] = 1;
         }
      }
      return true;
   }
};
