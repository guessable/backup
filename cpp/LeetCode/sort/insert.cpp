#include <iostream>
#include <vector>

using namespace std;

/*
 * 时间复杂度：最好O(n),最坏O(n^2),平均O(n^2)
 * 空间复杂度: O(1)
 */
void inserSort(vector<int>& nums) {
   int n = nums.size();
   for(int i = 0; i < n; ++i) {
      int index = i, cur = nums[i];
      while(index > 0 && nums[index - 1] > cur) {
         nums[index] = nums[index - 1];
         --index;
      }
      nums[index] = cur;
   }
}

int main() {
   vector<int> nums{3, 5, 1, 7, 3, 9, 4, 0, 6, 3, 8};
   inserSort(nums);
   for(int num : nums) {
      cout << num << " ";
   }
}
