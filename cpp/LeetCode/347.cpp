#include <iostream>
#include <vector>
#include <queue>
#include <map>

using namespace std;

class Heap {
public:
   vector<pair<int, int>> nums;
   int len = 0;
   void heapifyDown(vector<pair<int, int>>& nums, int n, int i) {
      if(i >= n) {
         return ;
      }
      int minIndex = i, c1 = 2 * i + 1, c2 = c1 + 1;
      if(c1 < n && nums[c1].second < nums[minIndex].second) {
         minIndex = c1;
      }
      if(c2 < n && nums[c2].second < nums[minIndex].second) {
         minIndex = c2;
      }
      if(minIndex != i) {
         swap(nums[i], nums[minIndex]);
         heapifyDown(nums, n, minIndex);
      }
   }
   void heapUp(vector<pair<int, int>>& nums, int i) {
      if(i <= 0) {
         return ;
      }
      int parent = (i - 1) / 2;
      if(nums[parent].second > nums[i].second) {
         swap(nums[parent], nums[i]);
         heapUp(nums, parent);
      }
   }
   void push(pair<int, int> pa) {
      this->nums.push_back(pa);
      ++this->len;
      heapUp(this->nums, this->len - 1);
   }
   pair<int, int> pop() {
      swap(this->nums[0], this->nums[this->len - 1]);
      auto temp = nums[this->len - 1];
      this->nums.pop_back();
      --this->len;
      heapifyDown(this->nums, this->len, 0);
      return temp;
   }
   int size() {
      return this->len;
   }
   bool empty() {
      return len == 0 ? true : false;
   }
};

class Solution {
public:
   vector<int> topKFrequent(vector<int>& nums, int k) {
      Heap heap;
      map<int, int> tab;
      for(int num : nums) {
         ++tab[num];
      }
      for(auto pairs : tab) {
         heap.push(pairs);
         if(heap.size() > k) {
            heap.pop();
         }
      }
      vector<int> ans;
      while(!heap.empty()) {
         auto temp = heap.pop();
         ans.push_back(temp.first);
      }
      return ans;
   }
};

int main() {
   Solution solution;
   vector<int> nums{5, 2, 5, 3, 5, 3, 1, 1, 3};
   auto ans = solution.topKFrequent(nums, 2);

   for(int num : ans) {
      cout << num << " ";
   }
}
