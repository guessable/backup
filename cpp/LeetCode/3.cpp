#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

class Solution {
public:
   int lengthOfLongestSubstring(string s) {
      int n = s.size();

      if(n == 1 || n == 0) {
         return n;
      }

      int l = 0, r = 0, res = 0;
      unordered_map<char, int> hashTab;
      hashTab[s[0]] = 1;

      while(r < n - 1) {
         ++r;
         ++hashTab[s[r]];

         while(hashTab[s[r]] == 2) {
            --hashTab[s[l]];
            ++l;
         }

         res = max(res, r - l + 1);
      }

      return res;
   }
};

int main() {
   Solution solution;
   int ans = solution.lengthOfLongestSubstring("pwwkew");
   cout << ans << endl;
}
