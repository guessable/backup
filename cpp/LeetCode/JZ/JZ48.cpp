#include <vector>
#include <iostream>
#include <string>
#include <map>

using namespace std;

class Solution {
public:
   int lengthOfLongestSubstring(string s) {
      int len = s.size();

      if(len == 0) {
         return 0;
      }

      int left = 0;
      int right = 1;
      int maxLen = 1;
      map<char, int> tab;
      tab[s[0]] = 1;

      while(right < len) {
         tab[s[right]]++;

         while(tab[s[right]] >= 2) {
            tab[s[left]]--;
            left++;
         }

         maxLen = max(right - left + 1, maxLen);
         right++;
      }

      return maxLen;
   }
};

int main() {
   Solution solution;
   int ans = solution.lengthOfLongestSubstring("abcabcbb");
   cout << ans << endl;
}
