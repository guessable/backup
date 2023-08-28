/*
 * 堆类 (heap)
 */

#include <iostream>
#include <vector>

using namespace std;

class Heap {
public:
   vector<int> nums;
   void heapifyDown(vector<int>& nums, int i) {
      int n = nums.size();
      if(i >= n) {
         return ;
      }
      int c1 = 2 * i + 1, c2 = c1 + 1, maxIndex = i;
      if(c1 < n && nums[c1] > nums[maxIndex]) {
         maxIndex = c1;
      }
      if(c2 < n && nums[c2] > nums[maxIndex]) {
         maxIndex = c2;
      }
      if(maxIndex != i) {
         swap(nums[i], nums[maxIndex]);
         heapifyDown(nums, maxIndex);
      }
   }

   void heapifyUp(vector<int>& nums, int i) {
      if(i < 0) {
         return ;
      }
      int parent = (i - 1) / 2;
      if(nums[i] > nums[parent]) {
         swap(nums[i], nums[parent]);
         heapifyUp(nums, parent);
      }
   }

   void push(int i) {
      this->nums.push_back(i);
      int n = this->nums.size();
      heapifyUp(this->nums, n - 1);
   }

   int pop() {
      int temp = this->nums[0];
      int n = this->nums.size();
      swap(this->nums[0], this->nums[n - 1]);
      this->nums.pop_back();
      heapifyDown(this->nums, 0);
      return temp;
   }

   int size() {
      int n = this->nums.size();
      return n;
   }
};

vector<int> topK(vector<int>& nums, int k) {
   int n = nums.size();
   Heap heap;
   for(int i = 0; i < n; ++i) {
      heap.push(nums[i]);

      if(heap.size() > k) {
         heap.pop();
      }
   }
   return heap.nums;
}

int main() {
   vector<int> nums{4, 2, 5, 7, 11};
   auto ans = topK(nums, 2);

   for(int num : ans) {
      cout << num << " ";
   }
}
