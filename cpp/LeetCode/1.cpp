/************************
     "
   '':''
  ___:____      |\/|
,'        `.    \  /
|  O        \___/  |
~^~^~^~^~^~^~^~^~^~^~^~^~
*************************/

#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;
class Solution {
public:
  vector<int> twoSum(vector<int> &nums, int target) {
    unordered_map<int, int> mp;
    int n = nums.size();
    for (int i = 0; i < n; ++i) {
      if (mp.count(target - nums[i])) {
        return vector<int>{mp[target - nums[i]], i};
      } else {
        mp[nums[i]] = i;
      }
    }
    return vector<int>{};
  }
};

int main() {
  Solution solution;
  vector<int> nums{3, 2, 4};
  auto ans = solution.twoSum(nums, 7);
  for (int num : ans) {
    cout << num << " ";
  }
}
