#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
   vector<vector<int>> ans;
   vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
      vector<int> track;
      backTrack(candidates, track, 0, target, 0);
      return ans;
   }

   void backTrack(vector<int>& candidates,
                  vector<int>& track, int sum, int target, int startIndex) {
      if(sum >= target) {
         if(sum == target) {
            ans.push_back(track);
         }

         return ;
      }

      int n = candidates.size();

      for(int i = startIndex; i < n; ++i) {
         sum += candidates[i];
         track.push_back(candidates[i]);
         backTrack(candidates, track, sum, target, i);
         sum -= candidates[i];
         track.pop_back();
      }
   }
};

int main() {
   Solution solution;
   vector<int> nums{2, 3, 5};
   auto ans = solution.combinationSum(nums, 8);

   for(auto vec : ans) {
      for(auto num : vec) {
         cout << num << " ";
      }

      cout << endl;
   }
}
