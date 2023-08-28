#include <iostream>
#include <vector>

using namespace std;

/*
 * 时间复杂度：最好O(n^2),最坏O(n^2),平均O(n^2)
 * 空间复杂度: O(1)
 */

void selectSort(vector<int>& nums) {
   int n = nums.size();
   for(int i = n - 1; i >= 0; --i) {
      int maxIndex = i;
      for(int j = 0; j <= i; ++j) {
         if(nums[j] >= nums[maxIndex]) {
            maxIndex = j;
         }
      }
      if(maxIndex != i) {
         swap(nums[maxIndex], nums[i]);
      }
   }
}

int main() {
   vector<int> nums{9, 1, 5, 3, 8, 5, 0, 2, 9, 5, 1, 4, 8};
   selectSort(nums);
   for(int num : nums) {
      cout << num << " ";
   }
}
