#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
   bool result = false;
   vector<vector<char>> board_;
   string word_;
   int m, n, len;
   bool exist(vector<vector<char>>& board, string word) {
      len = word.size();
      m = board.size();
      n = board[0].size();
      board_ = board;
      word_ = word;

      vector<vector<int>> used(m, vector<int>(n, 0));

      for(int i = 0; i < m; i++) {
         for(int j = 0; j < n; j++) {
            if(board[i][j] == word[0]) {
               used[i][j] = 1;
               dfs(used, i, j, 0);

               if(result) {
                  return true;
               }

               used[i][j] = 0;
            }
         }
      }

      return false;
   }

   void dfs(vector<vector<int>>& used, int i, int j, int index) {
      if(result) {
         return ;
      }

      if(index == len - 1) {
         result = true;
         return ;
      }

      if(i + 1 < m && word_[index + 1] == board_[i + 1][j]
            && used[i + 1][j] == 0) {
         used[i + 1][j] = 1;
         dfs(used, i + 1, j, index + 1);
         used[i + 1][j] = 0;
      }

      if(i - 1 >= 0 && word_[index + 1] == board_[i - 1][j]
            && used[i - 1][j] == 0) {
         used[i - 1][j] = 1;
         dfs(used, i - 1, j, index + 1);
         used[i - 1][j] = 0;
      }

      if(j - 1 >= 0 && word_[index + 1] == board_[i][j - 1]
            && used[i][j - 1] == 0) {
         used[i][j - 1] = 1;
         dfs(used, i, j - 1, index + 1);
         used[i][j - 1] = 0;
      }

      if(j + 1 < n && word_[index + 1] == board_[i][j + 1]
            && used[i][j + 1] == 0) {
         used[i][j + 1] = 1;
         dfs(used, i, j + 1, index + 1);
         used[i][j + 1] = 0;
      }

   }
};

int main() {
   vector<vector<char>> test{{'A', 'B', 'C', 'E'}, {'S', 'F', 'C', 'S'},
      {'A', 'D', 'E', 'E'}};
   Solution solution;
   int ans = solution.exist(test, "ABCED");
   cout << ans << endl;
}
