#include <iostream>
#include <random>
#include <vector>

using namespace std;

/*
 * 时间复杂度：最好O(nlogn),最坏O(n^2),平均O(nlogn)
 * 空间复杂度: O(lgn)
 */
void quickSort(int left, int right, vector<int>& nums) {
  if (left >= right) {
    return;
  }

  // rand() % n 生成[0,n)内的一个伪随机数(C style)
  // int randIndex = rand() % (right - left + 1) + left;

  // C++ 11
  default_random_engine e(time(0));
  uniform_int_distribution<int> u(left, right);  // 范围[left,right];
  int randIndex = u(e);

  swap(nums[randIndex], nums[left]);
  int lPtr = left, rPtr = right;
  int pivot = nums[left];

  while (lPtr < rPtr) {
    while (nums[rPtr] > pivot && lPtr < rPtr) {
      --rPtr;
    }

    while (nums[lPtr] <= pivot && lPtr < rPtr) {
      ++lPtr;
    }

    if (lPtr < rPtr) {
      swap(nums[lPtr], nums[rPtr]);
    }
  }

  nums[left] = nums[lPtr];
  nums[lPtr] = pivot;

  quickSort(left, lPtr - 1, nums);
  quickSort(lPtr + 1, right, nums);
}

int main() {
  vector<int> nums{11, 7, 2, 9, 13, 1, 4, 7, 24, 9, 1, 8, 3, 6, 1, 0, 4};
  int n = nums.size();
  quickSort(0, n - 1, nums);
  for (int num : nums) {
    cout << num << " ";
  }
}
