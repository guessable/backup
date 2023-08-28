#include <iostream>
#include <vector>

using namespace std;
class Solution {
public:
   int lengthOfLastWord(string s) {
      int n = s.size(), ans = 0;
      bool flag = true;
      for(int i = n - 1; i >= 0; --i) {
         if(s[i] != ' ') {
            ++ans;
            flag = false;
         } else if(s[i] == ' ' && !flag) {
            break;
         }
      }
      return ans;
   }
};

int main() {
   string s = "a a";
   Solution solution;
   int ans = solution.lengthOfLastWord(s);
   cout << ans << endl;
}
