#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
  vector<vector<int>> result;
  vector<int> value;
  int maxCoins(vector<int> &nums) {
    int n = nums.size();

    for (int i = 0; i < n + 2; i++) {
      if (i == 0 || i == n + 1) {
        value.push_back(1);
      } else {
        value.push_back(nums[i - 1]);
      }
    }

    result.resize(n + 2, vector<int>(n + 2, 0));

    return memory(value, 0, n + 1);
  }

  int memory(vector<int> &value, int l, int r) {
    if (l >= r - 1) {
      return 0;
    }

    if (result[l][r] != 0) {
      return result[l][r];
    }

    for (int i = l + 1; i < r; i++) {
      int count = value[l] * value[i] * value[r] +
                  (memory(value, l, i) + memory(value, i, r));
      result[l][r] = max(count, result[l][r]);
    }

    return result[l][r];
  }
};

int main() {
  vector<int> nums{8, 2, 6, 8, 9, 8, 1, 4, 1, 5, 3, 0, 7, 7, 0, 4, 2};
  Solution solution;
  int ans = solution.maxCoins(nums);
  cout << ans << endl;
}
