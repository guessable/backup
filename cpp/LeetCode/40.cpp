#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
   vector<vector<int>> ans;
   vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
      sort(candidates.begin(), candidates.end());
      vector<int> track;
      int n = candidates.size();
      vector<int> used(n, 0);
      backTrack(candidates, track, used, 0, target, 0);
      return ans;
   }

   void backTrack(vector<int>& candidates, vector<int>& track,
                  vector<int>& used, int sum, int target, int startIndex) {
      if(sum >= target) {
         if(sum == target) {
            ans.push_back(track);
         }

         return ;
      }

      int n = candidates.size();

      for(int i = startIndex; i < n; ++i) {
         if(i > 0 && candidates[i] == candidates[i - 1] && used[i - 1] == 0) {
            continue;
         }

         used[i] = 1;
         sum += candidates[i];
         track.push_back(candidates[i]);
         backTrack(candidates, track, used, sum, target, i + 1);
         track.pop_back();
         sum -= candidates[i];
         used[i] = 0;
      }
   }
};

int main() {
   Solution solution;
   vector<int> nums{2, 5, 2, 1, 2};
   auto ans = solution.combinationSum2(nums, 5);

   for(auto vec : ans) {
      for(auto num : vec) {
         cout << num << " ";
      }

      cout << endl;
   }
}
