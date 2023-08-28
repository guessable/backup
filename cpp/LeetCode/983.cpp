#include <iostream>
#include <vector>
#include <map>

using namespace std;

class Solution {
   int max = INT32_MAX;
public:
   int mincostTickets(vector<int>& days, vector<int>& costs) {
      int n = days.size();
      vector<int> dp(days[n - 1] + 1, 0);
      map<int, int> tab;

      for(int day : days) {
         tab[day] = 1;
      }


      for(int i = 1; i < days[n - 1] + 1; i++) {
         if(tab[i] == 0) {
            dp[i] = dp[i - 1];
         } else {
            int temp1 = 0;
            int temp2 = 0;
            int temp3 = 0;
            i < 1 ? temp1 = 0 : temp1 = dp[i - 1];
            i < 7 ? temp2 = 0 : temp2 = dp[i - 7];
            i < 30 ? temp3 = 0 : temp3 = dp[i - 30];

            dp[i] = min(temp1 + costs[0], min(temp2 + costs[1],
                                              temp3 + costs[2]));
         }
      }

      return dp[days[n - 1]];
   }
};

int main() {
   Solution solution;
   vector<int> days{1, 2, 3, 4, 5, 7, 8, 9, 10, 11, 12};
   vector<int> costs{2, 7, 15};
   int ans = solution.mincostTickets(days, costs);
   cout << ans << endl;
}
