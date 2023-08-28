/*
 * 数组前k个高频元素
 */
#include <iostream>
#include <vector>
#include <map>

using namespace std;

/*
 * 基于快排的思想 平均O(n),最坏O(n^2)
 */

void quick(vector<pair<int, int>>& freq, int n, int i,
           int j, int k) {
   if(i >= j) {
      return ;
   }
   int lPtr = i, rPtr = j;
   pair<int, int> temp = freq[i];
   int base = freq[i].second;

   while(lPtr < rPtr) {
      while(lPtr < rPtr && freq[rPtr].second > base) {
         --rPtr;
      }
      while(lPtr < rPtr && freq[lPtr].second <= base) {
         ++lPtr;
      }
      if(lPtr < rPtr) {
         swap(freq[lPtr], freq[rPtr]);
      }
   }
   freq[i] = freq[lPtr];
   freq[lPtr] = temp;

   if(lPtr == n - k) {
      return ;
   } else if(lPtr > n - k) {
      quick(freq, n, i, lPtr - 1, k);
   } else {
      quick(freq, n, lPtr + 1, j, k);
   }
}

vector<int> topKQuick(vector<int>& nums, int k) {
   map<int, int> tab;
   for(int num : nums) {
      ++tab[num];
   }
   vector<pair<int, int>> freq;
   for(auto pairs : tab) {
      freq.push_back(pairs);
   }
   int n = freq.size();
   quick(freq, n, 0, n - 1, k);
   vector<pair<int, int>> ans(freq.begin() + n - k, freq.end());

   vector<int> ret;
   for(auto pairs : ans) {
      ret.push_back(pairs.first);
   }
   return ret;
}

int main() {
   vector<int> nums{1, 2, 2, 3, 3, 3, 4, 4, 4, 4, 5, 5, 5, 5, 5};
   auto ans = topKQuick(nums, 2);
   for(int num : ans) {
      cout << num << " ";
   }
}
