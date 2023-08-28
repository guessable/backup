#include <iostream>
#include <vector>
#include <map>

using namespace std;

class Solution {
   map<vector<int>, int> memo;
public:
   int shoppingOffers(vector<int>& price, vector<vector<int>>& special,
                      vector<int>& needs) {
      return dfs(price, special, needs);
   }

   int dfs(vector<int>& price, vector<vector<int>>& special,
           vector<int>& need) {
      if(memo.count(need)) {
         return memo[need];
      }

      int ans = 0, n = need.size();
      for(int i = 0; i < n; ++i) {
         ans += price[i] * need[i];
      }

      for(auto spec : special) {
         vector<int> curNeed(n, 0);
         int flag = 0;
         for(int i = 0; i < n; ++i) {
            curNeed[i] = need[i] - spec[i];
            if(curNeed[i] < 0) {
               flag = 1;
               break;
            }
         }
         if(flag == 0) {
            ans = min(ans, spec[n] + dfs(price, special, curNeed));
         }
      }
      memo[need] = ans;

      return ans;
   }
};
int main() {
   Solution solution;
   vector<int> p{4, 3, 2, 9, 8, 8};
   vector<int> n{6, 5, 5, 6, 4, 1};
   vector<vector<int>> s{{1, 5, 5, 1, 4, 0, 18}, {3, 3, 6, 6, 4, 2, 32}};
   int ans = solution.shoppingOffers(p, s, n);
   cout << ans << endl;
}
