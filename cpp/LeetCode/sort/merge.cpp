#include <iostream>
#include <vector>

using namespace std;

/*
 * 时间复杂度：最好O(nlogn),最坏O(nlogn),平均O(nlogn)
 * 空间复杂度: O(n)
 */
vector<int> temp;
void merge(vector<int>& nums, int start, int end) {
   int mid = (start + end) / 2;
   if(end <= start) {
      return ;
   }
   merge(nums, start, mid);
   merge(nums, mid + 1, end);

   int lPtr = start, rPtr = mid + 1, index = start;
   while(lPtr <= mid && rPtr <= end) {
      if(nums[lPtr] < nums[rPtr]) {
         temp[index++] = nums[lPtr++];
      } else {
         temp[index++] = nums[rPtr++];
      }
   }
   while(lPtr <= mid) {
      temp[index++] = nums[lPtr++];
   }
   while(rPtr <= end) {
      temp[index++] = nums[rPtr++];
   }
   for(int i = start; i <= end; ++i) {
      nums[i] = temp[i];
   }
}

int main() {
   vector<int> nums{11, 7, 2, 9, 13, 1, 4, 7, 24, 9, 1, 8, 3, 6, 1, 0, 4};
   int n = nums.size();
   temp.resize(n);
   merge(nums, 0, n - 1);
   for(int num : nums) {
      cout << num << " ";
   }
}
