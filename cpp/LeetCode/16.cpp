#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
class Solution {
public:
   int threeSumClosest(vector<int>& nums, int target) {
      int n = nums.size();
      int best = INT32_MAX;
      sort(nums.begin(), nums.end());
      auto update = [&](int sum) {
         if(abs(sum - target) < abs(target - best)) {
            best = sum;
         }
      };
      for(int i = 0; i < n; ++i) {
         if(i > 0 && nums[i] == nums[i - 1]) {
            continue;
         }
         int lPtr = i + 1, rPtr = n - 1;
         while(lPtr < rPtr) {
            int sum = nums[i] + nums[lPtr] + nums[rPtr];
            if(sum == target) {
               return best;
            }
            update(sum);

            if(sum > target) {
               int temp = rPtr - 1;
               while(temp > lPtr && nums[temp] == nums[rPtr]) {
                  --temp;
               }
               rPtr = temp;
            } else {
               int temp = lPtr + 1;
               while(temp < rPtr && nums[temp] == nums[lPtr]) {
                  ++temp;
               }
               lPtr = temp;
            }
         }
      }

      return best;
   }
};
