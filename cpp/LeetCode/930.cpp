#include <iostream>
#include <vector>
#include <map>

using namespace std;

class Solution {
public:
   int numSubarraysWithSum(vector<int>& nums, int goal) {
      int n = nums.size(), count = 0;
      map<int, int> tab;
      vector<int> pre(n, nums[0]);

      for(int i = 1; i < n; i++) {
         pre[i] = pre[i - 1] + nums[i];
      }

      for(int i = 0; i < n; i++) {
         if(pre[i] == goal) {
            count++;
         }

         count += tab[pre[i] - goal];
         tab[pre[i]]++;

      }

      return count;
   }
};

int main() {
   Solution solution;
   vector<int> nums{1};
   int ans = solution.numSubarraysWithSum(nums, 1);
   cout << ans << endl;
}
