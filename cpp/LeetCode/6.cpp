#include <iostream>
#include <vector>
#include <string>
#include <map>

using namespace std;

class Solution {
public:
   string convert(string s, int numRows) {
      map<int, string> tab;
      int index = 1, direct = 1;
      int len = s.size();

      if(numRows == 1) {
         return s;
      }

      for(int i = 0; i < len; i++) {
         if(index == numRows) {
            direct = -1;
         } else if(index == 1) {
            direct = 1;
         }

         tab[index] += s[i];
         index = index + direct;
      }

      string result = "";

      for(int i = 1; i <= numRows; i++) {
         result += tab[i];
      }

      return result;

   }
};

int main() {
   Solution solution;
   string ans = solution.convert("PAYPALISHIRING", 4);
   cout << ans << endl;
}
