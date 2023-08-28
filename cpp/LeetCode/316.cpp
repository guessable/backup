#include <algorithm>
#include <iostream>
#include <map>
#include <stack>
#include <string>
#include <vector>

using namespace std;
class Solution {
 public:
  string removeDuplicateLetters(string s) {
    int n = s.size();
    map<char, int> mp1, mp2;
    for (char ch : s) {
      mp1[ch]++;
    }
    stack<char> stk;

    for (int i = 0; i < n; ++i) {
      if (mp2[s[i]] == 0) {
        while (!stk.empty() && s[i] <= stk.top() && mp1[stk.top()] >= 1) {
          mp2[stk.top()]--;
          stk.pop();
        }
        stk.push(s[i]);
        mp1[stk.top()]--;
        mp2[s[i]]++;
      } else {
        mp1[s[i]]--;
      }
    }

    string str = "";
    while (!stk.empty()) {
      str += stk.top();
      stk.pop();
    }

    reverse(str.begin(), str.end());
    return str;
  }
};

int main() {
  Solution solution;
  string str = solution.removeDuplicateLetters("cbacdcbc");
  cout << str << endl;
}
