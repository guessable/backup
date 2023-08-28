#include <iostream>
#include <vector>

using namespace std;
class Solution {
public:
   int longestSubstring(string s, int k) {
      vector<int> count(26, 0);
      int n = s.size();

      if(k > n) {
         return 0;
      }
      for(char ch : s) {
         count[ch - 'a']++;
      }

      int split = -1;
      for(int i = 0; i < n; ++i) {
         if(count[s[i] - 'a'] > 0 && count[s[i] - 'a'] < k) {
            split = i;
            break;
         }
      }

      if(split == -1) {
         return n;
      }

      return max(longestSubstring(s.substr(0, split), k),
                 longestSubstring(s.substr(split + 1, n - split - 1), k));

   }
};

int main() {
   Solution solution;
   int ans = solution.longestSubstring("ababbc", 2);
   cout << ans << endl;
}
