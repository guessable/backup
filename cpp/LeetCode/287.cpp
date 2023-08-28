#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
   int findDuplicate(vector<int>& nums) {
      int n = nums.size();
      int l = 0, r = n - 1;
      while(l < r) {
         int mid = (l + r) / 2;
         int count = 0;
         for(int num : nums) {
            if(num <= mid) {
               count++;
            }
         }

         if(count > mid) {
            r = mid;
         } else {
            l = mid + 1;
         }
      }

      return l;
   }
};

int main() {
   Solution solution;
   vector<int> nums{4, 5, 6, 3, 2, 1, 1};
   int ans = solution.findDuplicate(nums);
   cout << ans << endl;
}
