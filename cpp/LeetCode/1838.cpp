#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;
class Solution {
 public:
  int maxFrequency(vector<int>& nums, int k) {
    sort(nums.begin(), nums.end());
    int n = nums.size();
    vector<int> pre(n, 0);
    pre[0] = nums[0];

    for (int i = 1; i < n; ++i) {
      pre[i] = pre[i - 1] + nums[i];
    }
  }
};