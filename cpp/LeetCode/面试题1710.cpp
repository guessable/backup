#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
   int majorityElement(vector<int>& nums) {
      int k = 0, n = nums.size(), cand = 0;

      for(int i = 0; i < n; i++) {
         if(k == 0) {
            cand = nums[i];
            ++k;
         } else {
            if(cand == nums[i]) {
               ++k;
            } else {
               --k;
            }
         }
      }

      k = 0;

      for(int i = 0; i < n; i++) {
         if(cand == nums[i]) {
            ++k;
         }
      }

      return k > n / 2 ? cand : -1;
   }
};

int main() {
   Solution solution;
   vector<int> nums{1, 2, 3, 4, 5, 1, 1, 1, 1, 1};
   int ans = solution.majorityElement(nums);
   cout << ans << endl;
}
