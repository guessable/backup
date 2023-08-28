#include <iostream>
#include <vector>

using namespace std;
class Solution {
public:
   int search(vector<int>& nums, int target) {
      int n = nums.size();
      int lptr = 0, rptr = n - 1;
      int rBound = 0, lBound = 1;

      while(lptr <= rptr) {
         int mid = (lptr + rptr) / 2;
         if(nums[mid] < target) {
            lptr = mid + 1;
         } else if(nums[mid] > target) {
            rptr = mid - 1;
         } else if(nums[mid] == target) {
            rBound = mid;
            lptr = mid + 1;
         }
      }

      lptr = 0, rptr = n - 1;
      while(lptr <= rptr) {
         int mid = (lptr + rptr) / 2;
         if(nums[mid] < target) {
            lptr = mid + 1;
         } else if(nums[mid] > target) {
            rptr = mid - 1;
         } else if(nums[mid] == target) {
            lBound = mid;
            rptr = mid - 1;
         }
      }

      return rBound - lBound + 1;
   }
};

int main() {
   Solution solution;
   vector<int> nums{};
   int ans = solution.search(nums, 10);
   cout << ans << endl;
}
