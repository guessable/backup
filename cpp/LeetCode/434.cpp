#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
 public:
  int countSegments(string s) {
    int len = s.size(), ans = 0;

    for (int i = 0; i < len; ++i) {
      if (i < len && s[i] != ' ') {
        while (i < len && s[i] != ' ') {
          ++i;
        }
        ++ans;
      }
    }

    return ans;
  }
};

int main() {
  Solution solution;
  string s = "Hello, my name is John";
  int ans = solution.countSegments(s);
  cout << ans << endl;
}