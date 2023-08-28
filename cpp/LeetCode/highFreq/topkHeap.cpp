/*
 * 数组前k个高频元素
 */
#include <iostream>
#include <vector>
#include <map>

using namespace std;

/*
 * 基于堆 O(nlogk)
 */
void heapify(vector<pair<int, int>>& nums, int i) {
   int n = nums.size();
   if(i > n) {
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
      heapify(nums, minIndex);
   }
}

void buildHeap(vector<pair<int, int>>& nums, int n) {
   int laseNode = (n - 2) / 2;
   for(int i = laseNode; i >= 0; --i) {
      heapify(nums, i);
   }
}

vector<int> topKHeap(vector<int>& nums, int k) {
   map<int, int> tab;
   for(int num : nums) {
      ++tab[num];
   }
   vector<pair<int, int>> freq;
   for(auto pairs : tab) {
      freq.push_back(pairs);
   }
   int n = freq.size();
   vector<pair<int, int>> ans(freq.begin(), freq.begin() + k);
   buildHeap(ans, k);
   for(int i = k; i < n; ++i) {
      if(freq[i].second > ans[0].second) {
         ans[0] = freq[i];
         heapify(ans, 0);
      }
   }

   vector<int> ret;
   for(auto pairs : ans) {
      ret.push_back(pairs.first);
   }
   return ret;
}

int main() {
   vector<int> nums{1, 1, 2, 2, 2, 3, 3, 3, 3, 4, 4, 4, 4, 4};
   auto ans = topKHeap(nums, 1);
   for(int num : ans) {
      cout << num << " ";
   }
}
