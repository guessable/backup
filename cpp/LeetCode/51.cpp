#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
   bool isValid(vector<string>& board, int row, int col) {
      for(int i = 0; i < len; i++) {
         if(board[i][col] == 'Q' && i != row) {
            return false;
         }
      }

      for(int j = 0; j < len; j++) {
         if(board[row][j] == 'Q' && j != col) {
            return false;
         }
      }

      for(int i = row, j = col; i < len && j < len; i++, j++) {
         if(board[i][j] == 'Q' && i != row && j != col) {
            return false;
         }
      }

      for(int i = row, j = col; i >= 0 && j >= 0; i--, j--) {
         if(board[i][j] == 'Q' && i != row && j != col) {
            return false;
         }
      }

      for(int i = row, j = col; i < len && j >= 0; i++, j--) {
         if(board[i][j] == 'Q' && i != row && j != col) {
            return false;
         }
      }

      for(int i = row, j = col; i >= 0 && j < len; i--, j++) {
         if(board[i][j] == 'Q' && i != row && j != col) {
            return false;
         }
      }

      return true;
   }
   vector<vector<string>> result;
   int len = 0;
   vector<vector<string>> solveNQueens(int n) {
      len = n;
      vector<string> board(n, string(n, '.'));
      backTrack(board, 0, 0);
      return result;
   }

   void backTrack(vector<string>& board, int i, int j) {

      if(i >= len) {
         result.push_back(board);
         return ;
      }

      for(int j = 0; j < len; j++) {
         board[i][j] = 'Q';

         if(isValid(board, i, j)) {
            backTrack(board, i + 1, j);
         }

         board[i][j] = '.';

      }
   }
};

int main() {
   Solution solution;
   auto ans = solution.solveNQueens(4);

   for(auto board : ans) {
      for(string s : board) {
         cout << s << " ";
      }

      cout << endl;
   }
}
