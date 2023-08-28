#include <iostream>
#include <vector>

using namespace std;
class Solution {
public:
   bool checkRecord(string s) {
      int n = s.size();
      int count = 0;
      for(int i = 0; i < n; ++i) {
         if(s[i] == 'A') {
            ++count;
         }
         if(count >= 2) {
            return false;
         }
         if(i < n - 2 && s[i] == 'L') {
            if(s[i + 1] == 'L' && s[i + 2] == 'L') {
               return false;
            }
         }
      }
      return true;
   }
};
