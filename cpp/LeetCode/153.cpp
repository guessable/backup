#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
  int findMin(vector<int> &nums) {
    int n = nums.size();
    int left = 0, right = n - 1;

    while (left <= right) {
      int mid = left - ((left - right) / 2);

      if (nums[left] == nums[right]) {
        return nums[left];
      } else if (nums[mid] > nums[right]) {
        left = mid + 1;

      } else if (nums[mid] < nums[right]) {
        right = mid;
      }
    }

    return -1;
  }
};

int main() {
  Solution solution;
  vector<int> test{3, 0, 1};
  int ans = solution.findMin(test);
  cout << ans << endl;
}
