#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
   vector<int> maxSlidingWindow(vector<int>& nums, int k) {
      int n = nums.size();
      vector<int> result;
      deque<int> qu;

      for(int i = 0; i < k; i++) {
         while(!qu.empty()) {
            if(qu.back() < nums[i]) {
               qu.pop_back();
            } else {
               break;
            }
         }

         qu.push_back(nums[i]);
      }

      result.push_back(qu.front());

      int l = 0, r = k - 1;

      for(int i = r; i < n - 1; i++) {
         if(qu.front() == nums[l]) {
            qu.pop_front();
         }

         while(!qu.empty()) {
            if(qu.back() < nums[r + 1]) {
               qu.pop_back();
            } else {
               break;
            }
         }

         qu.push_back(nums[r + 1]);
         result.push_back(qu.front());
         l++, r++;
      }

      return result;
   }
};

int main() {
   Solution solution;
   vector<int> nums{3, 1, 3, 3, 4, 5, 3, 2, 1};
   auto ans = solution.maxSlidingWindow(nums, 2);

   for(int num : ans) {
      cout << num << endl;
   }
}
