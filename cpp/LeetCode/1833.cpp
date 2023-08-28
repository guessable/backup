#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
   int maxIceCream(vector<int>& costs, int coins) {
      sort(costs.begin(), costs.end());
      int count = 0;
      int sum = 0;

      for(int cost : costs) {
         sum += cost;

         if(sum <= coins) {
            count++;
         } else {
            break;
         }
      }

      return count;
   }
};

int main() {
   Solution solution;
   vector<int> costs{10, 6, 8, 7, 7, 8};
   int ans = solution.maxIceCream(costs, 5);
   cout << ans << endl;
}
