#include <iostream>
#include <vector>
#include <map>

using namespace std;

class Solution {
public:
   vector<int> findAnagrams(string s, string p) {
      int n = s.size();
      int k = p.size();
      int flag = 0;
      vector<int> result;

      if(n < k) {
         return result;
      }

      vector<int> count(26, 0);

      for(int i = 0; i < k; i++) {
         count[s[i] - 'a']++;
         count[p[i] - 'a']--;
      }

      for(int i = 0; i < 26; i++) {
         if(count[i] != 0) {
            flag = 1;
            break;
         }
      }

      if(flag == 0) {
         result.push_back(0);
      }

      int l = 0, r = k - 1;

      while(r < n - 1) {
         count[s[l] - 'a']--;
         count[s[r + 1] - 'a']++;
         r++, l++;
         flag = 0;

         for(int i = 0; i < 26; i++) {
            if(count[i] != 0) {
               flag = 1;
               break;
            }
         }

         if(flag == 0) {
            result.push_back(l);
         }
      }

      return result;

   }
};

int main() {
   Solution solution;
   auto nums = solution.findAnagrams("baa", "aa");

   for(auto num : nums) {
      cout << num << endl;
   }
}
