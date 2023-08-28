#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
class Solution {
public:
   int pow(int n) {
      int ret = 1;
      for(int i = 0; i < n; ++i) {
         ret *= 2;
      }
      return ret;
   }
   vector<int> pathInZigZagTree(int label) {
      vector<int> ans;
      while(label != 1) {
         ans.push_back(label);
         label /= 2;
      }
      ans.push_back(1);
      reverse(ans.begin(), ans.end());

      int n = ans.size(), pre = ans[n - 1];
      for(int i = n - 2; i >= 0; --i) {
         pre = ans[i + 1] / 2;
         ans[i] = 3 * pow(i) - pre - 1;
      }

      return ans;
   }
};

int main() {
   Solution solution;
   vector<int> ans = solution.pathInZigZagTree(15);
   for(int num : ans) {
      cout << num << " ";
   }
}
