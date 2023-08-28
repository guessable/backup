#include <iostream>
#include <vector>
#include <map>

using namespace std;
class Solution {
public:
   vector<int> restoreArray(vector<vector<int>>& adjacentPairs) {
      int n = adjacentPairs.size();
      map<int, vector<int>> tab;
      for(auto& adj : adjacentPairs) {
         tab[adj[0]].push_back(adj[1]);
         tab[adj[1]].push_back(adj[0]);
      }
      vector<int> ans(n + 1, 0);
      for(auto pairs : tab) {
         int len = pairs.second.size();
         if(len == 1) {
            ans[0] = pairs.first;
            break;
         }
      }
      ans[1] = tab[ans[0]][0];
      for(int i = 2; i < n + 1; ++i) {
         auto adj = tab[ans[i - 1]];
         ans[i] = ans[i - 2] == adj[0] ? adj[1] : adj[0];
      }

      return ans;

   }
};

int main() {
   Solution solution;
   vector<vector<int>> adj{{2, 1}, {3, 4}, {3, 2}};
   auto nums = solution.restoreArray(adj);
   for(int num : nums) {
      cout << num << " ";
   }
}
