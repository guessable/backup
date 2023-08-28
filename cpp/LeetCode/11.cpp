#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
  int maxArea(vector<int>& height) {
    int n = height.size();
    int l = 0, r = n - 1;
    int ans = (r - l) * min(height[l], height[r]);

    while (l < r) {
      if (height[l] >= height[r]) {
        --r;
      } else {
        ++l;
      }

      ans = max(ans, (r - l) * min(height[l], height[r]));
    }

    return ans;
  }
};

int main() {
  Solution solution;
  vector<int> height{1, 8, 6, 2, 5, 4, 8, 3, 7};
  int ans = solution.maxArea(height);
  cout << ans << endl;
}
