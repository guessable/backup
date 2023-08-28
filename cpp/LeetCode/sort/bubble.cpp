/*
 * 冒泡排序
 */
#include <iostream>
#include <vector>

using namespace std;

/*
 * 时间复杂度：最好O(n),最坏O(n^2),平均O(n^2)
 * 空间复杂度: O(1)
 */
void bubbleSort(vector<int>& nums) {
   int n = nums.size();
   for(int i = n - 1; i >= 0; --i) {
      for(int j = 0; j < i; ++j) {
         if(nums[j + 1] < nums[j]) {
            swap(nums[j], nums[j + 1]);
         }
      }
   }
}

int main() {
   vector<int> nums{5, 1, 2, 7, 5, 2, 1, 9, 6, 0, 5};
   bubbleSort(nums);
   for(int num : nums) {
      cout << num << " ";
   }
}
