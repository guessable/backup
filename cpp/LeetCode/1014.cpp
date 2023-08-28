#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
  int maxScoreSightseeingPair(vector<int> &values) {
    int n = values.size(), dp = values[1] + values[0] - 1, ans = dp;

    for (int i = 2; i < n; i++) {
      dp = max(dp + values[i] - values[i - 1] - 1,
               values[i] + values[i - 1] - 1);
      ans = max(ans, dp);
    }

    return ans;
  }
};

int main() {
  Solution solution;
  vector<int> values{8, 1, 5, 2, 6};
  int ans = solution.maxScoreSightseeingPair(values);
  cout << ans << endl;
}
