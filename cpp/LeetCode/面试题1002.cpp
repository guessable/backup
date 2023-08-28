#include <iostream>
#include <vector>
#include <map>

using namespace std;
class Solution {
public:
   vector<vector<string>> groupAnagrams(vector<string>& strs) {
      vector<vector<string>> ans;
      map<vector<int>, vector<string>> tab;

      for(string str : strs) {
         vector<int> key(26, 0);
         for(char ch : str) {
            ++key[ch - 'a'];
         }
         if(tab.count(key)) {
            tab[key].push_back(str);
         } else {
            tab[key] = vector<string> {str};
         }
      }

      for(auto pairs : tab) {
         ans.push_back(pairs.second);
      }

      return ans;
   }
};

int main() {
   Solution solution;
   vector<string> strs{"eat", "tea", "tan", "ate", "nat", "bat"};
   auto ans = solution.groupAnagrams(strs);
   for(auto str : ans) {
      for(auto s : str) {
         cout << s << " ";
      }
      cout << endl;
   }
}
