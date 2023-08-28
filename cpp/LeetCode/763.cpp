#include <iostream>
#include <vector>
#include <map>

using namespace std;
class Solution {
public:
   vector<int> partitionLabels(string s) {
      map<char, int> tab;
      vector<int> ans;
      int n = s.size();
      for(int i = n - 1; i >= 0; --i) {
         if(!tab.count(s[i])) {
            tab[s[i]] = i;
         }
      }

      int end = 0, start = 0;
      for(int i = 0; i < n; ++i) {
         end = max(end, tab[s[i]]);
         if(i == end) {
            ans.push_back(end - start + 1);
            start = end + 1;
         }
      }

      return ans;
   }
};

int main() {
   Solution solution;
   vector<int> ans = solution.partitionLabels("abacabcd");
   for(int num : ans) {
      cout << num << " ";
   }
}
