#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
   vector<vector<int>> ans;
   vector<vector<int>> permuteUnique(vector<int>& nums) {
      int n = nums.size();
      sort(nums.begin(), nums.end());
      vector<int> used(n, 0);
      vector<int> track;
      backTrack(nums, track, used);
      return ans;
   }

   void backTrack(vector<int>& nums, vector<int>& track, vector<int>& used) {
      if(nums.size() == track.size()) {
         ans.push_back(track);
         return ;
      }

      int n = nums.size();

      for(int i = 0; i < n; ++i) {
         if(i > 0 && nums[i] == nums[i - 1] && used[i - 1] == 0) {
            continue;
         }

         if(used[i] == 0) {
            used[i] = 1;
            track.push_back(nums[i]);
            backTrack(nums, track, used);
            used[i] = 0;
            track.pop_back();
         }
      }

   }
};

int main() {
   Solution solution;
   vector<int> nums{1, 1, 1};
   auto ans = solution.permuteUnique(nums);

   for(auto vec : ans) {
      for(int num : vec) {
         cout << num << " ";
      }

      cout << endl;
   }
}
