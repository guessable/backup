#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
   bool isValid(vector<vector<int>>& board, int row, int col) {
      for(int i = 0; i < len; i++) {
         if(board[i][col] == 1 && i != row) {
            return false;
         }
      }

      for(int j = 0; j < len; j++) {
         if(board[row][j] == 1 && j != col) {
            return false;
         }
      }

      for(int i = row, j = col; i < len && j < len; i++, j++) {
         if(board[i][j] == 1 && i != row && j != col) {
            return false;
         }
      }

      for(int i = row, j = col; i < len && j >= 0; i++, j--) {
         if(board[i][j] == 1 && i != row && j != col) {
            return false;
         }
      }

      for(int i = row, j = col; i >= 0 && j < len; i--, j++) {
         if(board[i][j] == 1 && i != row && j != col) {
            return false;
         }
      }

      for(int i = row, j = col; i >= 0 && j >= 0; i--, j--) {
         if(board[i][j] == 1 && i != row && j != col) {
            return false;
         }
      }

      return true;
   };

   int len = 0;
   int count = 0;
   int totalNQueens(int n) {
      len = n;
      vector<vector<int>> board(len, vector<int>(len, 0));
      backTrack(board, 0, 0);
      return count;
   }

   void backTrack(vector<vector<int>>& board, int i, int j) {
      if(i >= len) {
         count++;
         return ;
      }

      for(int j = 0; j < len; j++) {
         board[i][j] = 1;

         if(isValid(board, i, j)) {
            backTrack(board, i + 1, j);
         }

         board[i][j] = 0;
      }
   }
};

int main() {
   Solution solution;
   int ans = solution.totalNQueens(4);
   cout << ans << endl;
}
