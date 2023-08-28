#include <iostream>
#include <vector>

using namespace std;
class Solution {
public:
   void rotate(vector<int>& nums, int k) {
      int n = nums.size();
      k %= n;
      if(k == 0) {
         return ;
      }
      int lPtr = 0, rPtr = n - 1;
      while(lPtr < rPtr) {
         swap(nums[lPtr], nums[rPtr]);
         ++lPtr, --rPtr;
      }
      lPtr = 0, rPtr = n - 1;
      int rPtr1 = k - 1, lPtr1 = k;
      while(lPtr < rPtr1) {
         swap(nums[lPtr], nums[rPtr1]);
         ++lPtr, --rPtr1;
      }
      while(lPtr1 < rPtr) {
         swap(nums[lPtr1], nums[rPtr]);
         ++lPtr1, --rPtr;
      }
   }
};

int main() {
   Solution solution;
   vector<int> nums{1, 2, 3, 4, 5, 6, 7};
   solution.rotate(nums, 3);
   for(auto num : nums) {
      cout << num << " ";
   }
}
