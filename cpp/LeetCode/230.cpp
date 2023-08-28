#include <iostream>
#include <vector>

using namespace std;

struct TreeNode {
  int val;
  TreeNode* left;
  TreeNode* right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode* left, TreeNode* right)
      : val(x), left(left), right(right) {}
};

class Solution {
 public:
  int kthSmallest(TreeNode* root, int k) {
    vector<int> ans;
    travse(root, ans);
    return ans[k - 1];
  }

  void travse(TreeNode* root, vector<int>& nums) {
    if (root == nullptr) {
      return;
    }
    travse(root->left, nums);
    nums.push_back(root->val);
    travse(root->right, nums);
  }
};