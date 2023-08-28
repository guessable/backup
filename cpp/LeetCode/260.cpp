#include <iostream>
#include <vector>

using namespace std;
class Solution {
public:
   vector<int> singleNumber(vector<int>& nums) {
      int XOR = 0;
      for(int num : nums) {
         XOR ^= num;
      }

      int temp = 1;
      while((temp & XOR) == 0) {
         temp <<= 1;
      }

      int a = 0, b = 0;
      for(int num : nums) {
         if(temp & num) {
            a ^= num;
         } else {
            b ^= num;
         }
      }

      return vector<int> {a, b};
   }
};

int main() {
   Solution solution;
   vector<int> nums{0, 1, 2, 2};
   vector<int> ans = solution.singleNumber(nums);
   cout << ans[0] << " " << ans[1] << endl;
}
