#include <iostream>
#include <vector>
#include <stack>

using namespace std;
class Solution {
public:
   int sumSubarrayMins(vector<int>& arr) {
      arr.push_back(0);
      int MOD = 1e9 + 7;
      int res = 0;
      int N = arr.size();
      stack<int> stk;
      stk.push(0);
      for (int i = 1; i < N; i++) {
         while(!stk.empty() && arr[i] < arr[stk.top()]) {
            int index = stk.top();
            stk.pop();
            int leftLen = (stk.empty() ? index : index - stk.top() - 1);
            int rightLen = i - index - 1;
            res += (long)(arr[index]) * (leftLen + 1) * (rightLen + 1) % MOD;
            res %= MOD;
         }
         stk.push(i);
      }
      return res;
   }
};

int main() {
   Solution solution;
   vector<int> nums{1, 2};
   int ans = solution.sumSubarrayMins(nums);
   cout << ans << endl;
}
