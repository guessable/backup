#include <iostream>
#include <vector>

using namespace std;
class Solution {
public:
   int myAtoi(string s) {
      int n = s.size(), num = 0;

      for(int i = 0; i < n; ++i) {
         if(s[i] != ' ') {
            if(s[i] == '-') {
               int start = i + 1;
               while(start < n && s[start] - '0' >= 0
                     && s[start] - '0' <= 9) {
                  num = 10 * num + (s[start] - '0');
                  ++start;
               }
               return -num;
            } else if(s[i] == '+' || (s[i] - '0' >= 0 && s[i] - '0' <= 9)) {
               int start = 0;
               s[i] == '+' ? start = i + 1 : start = i;
               while(start < n && s[start] - '0' >= 0
                     && s[start] - '0' <= 9) {
                  num = 10 * num + (s[start] - '0');
                  ++start;
               }

               return num;
            } else {
               break;
            }
         }
      }
      return num;
   }
};

int main() {
   Solution solution;
   int ans = solution.myAtoi("-91283472332");
   cout << ans << endl;
}
