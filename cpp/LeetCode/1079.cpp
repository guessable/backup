#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
class Solution {
public:
   int count = 0, n = 0;
   string str = "";
   int numTilePossibilities(string tiles) {
      sort(tiles.begin(), tiles.end());
      n = tiles.size();
      str = tiles;
      vector<int> used(n, 0);
      dfs(used, 0);
      return count;
   }

   void dfs(vector<int>& used, int index) {
      if(index == n) {
         return ;
      }

      for(int i = 0; i < n; ++i) {
         if(i > 0 && str[i] == str[i - 1] && used[i - 1] == 0) {
            continue;;
         }

         if(!used[i]) {
            ++index, ++count;
            used[i] = 1;
            dfs(used, index);
            used[i] = 0;
            --index;
         }
      }
   }
};

int main() {
   Solution solution;
   int ret = solution.numTilePossibilities("AAABBC");
   cout << ret << endl;
}
