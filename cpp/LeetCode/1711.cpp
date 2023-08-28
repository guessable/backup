#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

class Solution {
public:
   long mod = 10e9 + 7;
   int countPairs(vector<int>& deliciousness) {
      map<int, int> tab;
      int n = deliciousness.size(), count = 0;

      int maxEle = *max_element(deliciousness.begin(), deliciousness.end());
      int maxSum = 2 * maxEle;

      for(int i = 0; i < n; i++) {
         for(int j = 1; j <= maxSum; ) {
            if(tab[j - deliciousness[i]] != 0) {
               count = (count + tab[j - deliciousness[i]]) % mod;
            }

            j *= 2;
         }

         tab[deliciousness[i]]++;
      }

      return count;
   }
};

int main() {
   Solution solution;
   vector<int> nums{1};
   int ans = solution.countPairs(nums);
   cout << ans << endl;
}
