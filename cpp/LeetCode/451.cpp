#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

class Solution {
public:
   string frequencySort(string s) {
      map<char, int> tab;
      map<int, string> count;
      string str = "";
      int maxFreq = 0;

      for(char ch : s) {
         tab[ch]++;
         maxFreq = max(maxFreq, tab[ch]);
      }

      for(auto pairs : tab) {
         int freq = pairs.second;
         count[freq].push_back(pairs.first);
      }

      for(int i = maxFreq; i >= 1; i--) {
         while(!count[i].empty()) {
            str += string(i, count[i].back());
            count[i].pop_back();
         }
      }

      return str;

   }
};

int main() {
   Solution solution;
   string str = solution.frequencySort("aac");
   cout << str << endl;
}
