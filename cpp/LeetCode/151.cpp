#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
class Solution {
public:
   string reverseWords(string s) {
      reverse(s.begin(), s.end());
      int index = 0, n = s.size(), count = 0;

      for(int i = 0; i < n; ++i) {
         count = 0;
         if(s[i] != ' ') {
            while(i < n && s[i] != ' ') {
               ++i;
               ++count;
            }
            reverse(s.begin() + index, s.begin() + i);
            index = index + count + 1;
         }
      }

      while(s.back() == ' ') {
         s.pop_back();
      }
      return s;
   }
};

int main() {
   Solution solution;
   string s = solution.reverseWords("  Bob    Loves  Alice.     ");
   cout << s << endl;
}
