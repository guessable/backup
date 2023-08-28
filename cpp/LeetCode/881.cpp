#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
class Solution {
public:
   int numRescueBoats(vector<int>& people, int limit) {
      sort(people.begin(), people.end());
      int n = people.size(), lPtr = 0, rPtr = n - 1;
      int ans = 0;
      while(lPtr <= rPtr) {
         if(people[rPtr] + people[lPtr] > limit) {
            ++ans;
            --rPtr;
         } else {
            ++ans;
            ++lPtr;
            --rPtr;
         }
      }
      return ans;
   }
};

int main() {
   Solution solution;
   vector<int> people{3, 5, 3, 4};
   int ans = solution.numRescueBoats(people, 5);
   cout << ans << endl;
}
