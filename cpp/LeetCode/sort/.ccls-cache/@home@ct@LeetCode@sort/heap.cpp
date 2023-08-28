#include <iostream>
#include <vector>

using namespace std;

/*
 * 子树已经是堆，堆化
 */
void heapifyDown(vector<int>& nums, int n, int i) {
   if(i >= n) {
      return ;
   }

   int max = i;
   int c1 = 2 * i + 1, c2 = 2 * i + 2;
   if(c1 < n && nums[c1] > nums[max]) {
      max = c1;
   }

   if(c2 < n && nums[c2] > nums[max]) {
      max = c2;
   }

   if(i != max) {
      swap(nums[max], nums[i]);
      heapifyDown(nums, n, max);
   }
}

/*
 * 最后一个非叶节点开始堆化,即最后一个节点的父节点
 * 编号为i的父节点为(i - 1) / 2
 */
void build_heap(vector<int>& nums, int n) {
   int lastNode = (n - 2) / 2;

   for(int i = lastNode; i >= 0; --i) {
      heapifyDown(nums, n, i);
   }
}

/*
 * 建堆后每次把根节点与最后一个节点交换,数组长度减一，
 * 且需要对根节点堆化即可.
 */
void heap_sort(vector<int>& nums) {
   int n = nums.size();
   build_heap(nums, n);

   for(int i = n - 1; i >= 0; --i) {
      swap(nums[0], nums[i]);
      heapifyDown(nums, i, 0);
   }
}

int main() {
   vector<int> nums{5, 1, 1, 2, 0, 0};
   heap_sort(nums);
   for(auto num : nums) {
      cout << num << " ";
   }
}
