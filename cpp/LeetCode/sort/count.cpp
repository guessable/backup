#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/*
 * 时间复杂度:O(n+k)
 * 空间复杂度:O(n+k)
 */
void count_sort(vector<int>& nums) {
   int n = nums.size();
   int maxEle = *max_element(nums.begin(), nums.end());
   int minEle = *min_element(nums.begin(), nums.end());

   vector<int> count(maxEle - minEle + 1, 0);

   for(int i = 0; i < n; i++) {
      count[nums[i] - minEle]++;
   }


   int index = 0;

   for(int i = 0; i < maxEle - minEle + 1; i++) {
      while(count[i] != 0) {
         nums[index++] = i + minEle;
         count[i]--;
      }
   }

}

int main() {
   vector<int> nums{3, 2, 1, 4, 1, 7, 3};
   count_sort(nums);

   for(int num : nums) {
      cout << num << " ";
   }
}
