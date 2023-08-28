#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
   void heapify(vector<int>& arr, int k, int i) {
      if(i > k) {
         return ;
      }
      int minIndex = i;
      int c1 = 2 * i + 1, c2 = c1 + 1;

      if(c1 < k && arr[c1] < arr[minIndex]) {
         minIndex = c1;
      }
      if(c2 < k && arr[c2] < arr[minIndex]) {
         minIndex = c2;
      }

      if(minIndex != i) {
         swap(arr[minIndex], arr[i]);
         heapify(arr, k, minIndex);
      }
   }

   void build_heap(vector<int>& arr, int k) {
      int last_node = (k - 2) / 2;
      for(int i = last_node; i >= 0; --i) {
         heapify(arr, k, i);
      }
   }

   int findKthLargest(vector<int>& nums, int k) {
      int n = nums.size();
      vector<int> arr = vector<int>(nums.begin(), nums.begin() + k);
      build_heap(arr, k);

      for(int i = k; i < n; ++i) {
         if(nums[i] > arr[0]) {
            arr[0] = nums[i];
            heapify(arr, k, 0);
         }
      }
      return arr[0];
   }
};

int main() {
   Solution solution;
   vector<int> nums{3, 2, 1, 5, 6, 4};
   int ans = solution.findKthLargest(nums, 2);
   cout << ans << endl;
}
