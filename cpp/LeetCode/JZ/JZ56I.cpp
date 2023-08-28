#include <iostream>
#include <vector>

using namespace std;
class Solution {
public:
   vector<int> singleNumbers(vector<int>& nums) {
      int result = 0;
      for(int num : nums) {
         result ^= num;
      }
      int diff = 1;
      while((diff & result) == 0) {
         diff <<= 1;
      }

      int a = 0, b = 0;
      for(int num : nums) {
         if((num & diff) == 0) {
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
   vector<int> nums{1, 2, 10, 4, 1, 4, 3, 3};
   vector<int> ans = solution.singleNumbers(nums);
   cout << ans[0] << " " << ans[1] << endl;
}
