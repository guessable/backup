#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
   void sortColors(vector<int>& nums) {
      int n = nums.size();
      int l = 0, r = n - 1;

      for(int i = 0; i <= r; i++) {
         while(i <= r && nums[i] == 2) {
            swap(nums[i], nums[r]);
            --r;
         }

         if(nums[i] == 0) {
            swap(nums[i], nums[l]);
            l++;
         }
      }
   }
};

int main() {
   Solution solution;
   vector<int> nums{2, 2};
   solution.sortColors(nums);

   for(int num : nums) {
      cout << num << " ";
   }
}
