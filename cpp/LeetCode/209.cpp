#include <iostream>
#include <vector>
#include <map>

using namespace std;

class Solution {
public:
   int minSubArrayLen(int target, vector<int>& nums) {
      int n = nums.size(), l = 0, r = 0, sum = 0, result = INT32_MAX;

      while(r < n) {
         sum += nums[r];

         while(sum >= target) {
            result = min(result, r - l + 1);
            sum -= nums[l];
            l++;
         }

         r++;
      }

      return result == INT32_MAX ? 0 : result;

   }
};

int main() {
   Solution solution;
   vector<int> nums{1, 1, 1, 1, 1, 1, 1};
   int ans = solution.minSubArrayLen(11, nums);
   cout << ans << endl;
}
