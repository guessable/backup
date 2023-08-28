#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
class Solution {
public:
   string minNumber(vector<int>& nums) {
      auto cmp = [](string a, string b) {
         return a + b < b + a;
      };
      vector<string> str;
      for(int num : nums) {
         str.push_back(to_string(num));
      }
      sort(str.begin(), str.end(), cmp);

      string ans = "";
      for(string s : str) {
         ans += s;
      }

      return ans;
   }
};

int main() {
   vector<int> nums{3, 30, 34, 5, 9};
   Solution solution;
   string s = solution.minNumber(nums);
   cout << s << endl;
}
