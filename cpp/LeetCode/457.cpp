#include <iostream>
#include <vector>

using namespace std;
class Solution {
public:
   bool circularArrayLoop(vector<int>& nums) {
      int n = nums.size();

      for(int i = 0; i < n; ++i) {
         if(nums[i] < 0) {
            continue;
         }
         if(nums[i] > 0) {
            int temp = i;
            while(temp > i) {
               temp = (nums[temp] + temp) % n;
               if(nums[temp] < 0) {
                  return false;
               }
            }

            if(temp == i) {
               return true;
            }
         }
      }
   }
};
