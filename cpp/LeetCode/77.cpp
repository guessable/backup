#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
   vector<vector<int>> ans;
   vector<vector<int>> combine(int n, int k) {
      vector<int> track;
      backTrack(n, k, 0, track);
      return ans;
   }

   void backTrack(int n, int k, int startIndex, vector<int>& track) {
      int size = track.size();

      if(size == k) {
         ans.push_back(track);
      }

      for(int i = startIndex; i < n; ++i) {
         track.push_back(i + 1);
         backTrack(n, k, i + 1, track);
         track.pop_back();
      }

   }
};

int main() {
   Solution solution;
   auto ans = solution.combine(4, 3);

   for(auto vec : ans) {
      for(int num : vec) {
         cout << num << " ";
      }

      cout << endl;
   }
}
