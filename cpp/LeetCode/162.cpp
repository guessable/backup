#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
   int findPeakElement(vector<int>& nums) {
      int n = nums.size();
      int l = 0, r = n - 1;

      while(l <= r) {
         int mid = (l + r) / 2;
         int lval = 0, rval = 0;
         mid <= 0  ? lval = INT32_MIN : lval = nums[mid - 1];
         mid >= n - 1  ? rval = INT32_MIN : rval = nums[mid + 1];

         if(nums[mid] >= lval && nums[mid] >= rval) {
            return mid;
         } else if(lval > nums[mid]) {
            r = mid - 1;
         } else if(rval > nums[mid]) {
            l = mid + 1;
         }
      }

      return -1;
   }
};

int main() {
   Solution solution;
   vector<int> nums{-2147483648};
   int ans = solution.findPeakElement(nums);
   cout << ans << endl;
}
