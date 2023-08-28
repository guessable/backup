#include <iostream>
#include <vector>

using namespace std;
class Solution {
public:
  int titleToNumber(string columnTitle) {
    int n = columnTitle.size();
    int ans = 0;
    for (int i = 0; i < n; ++i) {
      ans = 26 * ans + (columnTitle[i] - 'A' + 1);
    }
    return ans;
  }
};

int main() {
  Solution solution;
  int ans = solution.titleToNumber("FXSHRXW");
  cout << ans << endl;
}
