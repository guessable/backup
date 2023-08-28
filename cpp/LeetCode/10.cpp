#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;
class Solution {
public:
  unordered_map<string, int> memo;
  int m = 0, n = 0;
  bool isMatch(string s, string p) {
    m = s.size(), n = p.size();
    return dp(s, p, 0, 0);
  }

  bool dp(string s, string p, int i, int j) {
    if (j == n) {
      return i == m;
    }

    if (i == m) {
      if ((n - j) % 2 != 0) {
        return false;
      }
      for (; j + 1 < n; j += 2) {
        if (p[j + 1] != '*') {
          return false;
        }
      }
      return true;
    }

    string key = to_string(i) + '_' + to_string(j);
    if (memo.count(key)) {
      return memo[key];
    }

    bool res = false;

    if (s[i] == p[j] || p[j] == '.') {
      if (j < n - 1 && p[j + 1] == '*') {
        res = dp(s, p, i, j + 2) || dp(s, p, i + 1, j);
      } else {
        res = dp(s, p, i + 1, j + 1);
      }
    } else {
      if (j < n - 1 && p[j + 1] == '*') {
        res = dp(s, p, i, j + 2);
      } else {
        return false;
      }
    }

    memo[key] = res;
    return res;
  }
};
