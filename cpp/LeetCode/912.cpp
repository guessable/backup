#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
   void heapify(vector<int>& nums, int n, int i) {
      if(i >= n) {
         return ;
      }
      int maxIndex = i, c1 = 2 * i + 1, c2 = c1 + 1;
      if(c1 < n && nums[c1] > nums[maxIndex]) {
         maxIndex = c1;
      }
      if(c2 < n && nums[c2] > nums[maxIndex]) {
         maxIndex = c2;
      }
      if(maxIndex != i) {
         swap(nums[maxIndex], nums[i]);
         heapify(nums, n, maxIndex);
      }
   }
   vector<int> sortArray(vector<int>& nums) {
      int n = nums.size();
      for(int i = (n - 2) / 2; i >= 0; --i) {
         heapify(nums, n, i);
      }
      for(int i = n - 1; i >= 0; --i) {
         swap(nums[0], nums[i]);
         heapify(nums, i, 0);
      }
      return nums;
   }
};

int main() {
   Solution solution;
   vector<int> nums{5, 2, 3, 1};
   auto ans = solution.sortArray(nums);
   for(int num : ans) {
      cout << num << " ";
   }
}
