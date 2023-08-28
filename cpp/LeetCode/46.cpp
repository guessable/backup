#include <iostream>
#include <vector>

using namespace std;
class Solution {
public:
   vector<vector<int>> ans;
   int n = 0;
   vector<vector<int>> permute(vector<int>& nums) {
      this->n = nums.size();
      vector<int> visited(n, 0);
      vector<int> track;
      dfs(nums, track, visited);
      return ans;
   }
   void dfs(vector<int>& nums, vector<int>& track, vector<int>& visited) {
      int len = track.size();
      if(n == len) {
         ans.push_back(track);
         return ;
      }
      for(int i = 0; i < n; ++i) {
         if(!visited[i]) {
            visited[i] = 1;
            track.push_back(nums[i]);
            dfs(nums, track, visited);
            visited[i] = 0;
            track.pop_back();
         }
      }
   }

};
