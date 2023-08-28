#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
   vector<vector<int>> threeSum(vector<int>& nums) {
      sort(nums.begin(), nums.end());
      int n = nums.size();
      vector<vector<int>> result;
      for(int i = 0; i < n; ++i) {
         if(i > 0 && nums[i] == nums[i - 1]) {
            continue;
         }
         int lPtr = i + 1, rPtr = n - 1;
         while(lPtr < rPtr) {
            int sum = nums[lPtr] + nums[rPtr] + nums[i];
            if(sum == 0) {
               result.push_back(vector<int> {nums[i], nums[lPtr], nums[rPtr]});
            }
            if(sum > 0) {
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

      return result;
   }
};

int main() {
   Solution solution;
   vector<int> nums{-1, 0, 1, 2, -1, -4};
   auto ans = solution.threeSum(nums);

   for(auto vec : ans) {
      for(auto n : vec) {
         cout << n << " ";
      }

      cout << endl;
   }
}
