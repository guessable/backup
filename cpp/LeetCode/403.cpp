#include <iostream>
#include <vector>
#include <map>

using namespace std;

class Solution {
public:
   map<vector<int>, int> flag;
   map<int, int> stone;
   int n = 0;
   bool result = false;
   bool canCross(vector<int>& stones) {
      n = stones.size();

      if(stones[1] != 1) {
         return false;
      }

      for(int i = 1; i < n; i++) {
         stone[stones[i]] = i;
      }

      dfs(flag, stones, 1, 1);

      return result;

   }

   void dfs(map<vector<int>, int>& flag, vector<int>& stones, int i, int k) {

      if(result || flag[vector<int> {i, k}]) {
         return ;
      }

      if(i == n - 1) {
         result = true;
      }

      flag[vector<int> {i, k}] = 1;

      for(int j = -1; j < 2; j++) {
         if(stone[stones[i] + k + j] && k + j > 0) {
            dfs(flag, stones, stone[stones[i] + k + j], k + j);
         }
      }

   }
};

int main() {
   Solution solution;
   vector<int> stones{0, 1};
   int ans = solution.canCross(stones);
   cout << ans << endl;
}
