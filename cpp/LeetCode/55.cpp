#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	bool canJump(vector<int>& nums) {
		int maxJum = 0,n = nums.size();

		for(int i = 0;i<n;i++){
			if(i <= maxJum){
				maxJum = max(maxJum,i+nums[i]);
			}

			if(maxJum >= n - 1){
				return true;
			}
		}

		return false;
	}
};

int main(){
	Solution solution;
	vector<int> nums{3,2,1,0,4};
	int ans = solution.canJump(nums);
	cout << ans << endl;
}
