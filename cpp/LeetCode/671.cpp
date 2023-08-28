#include <iostream>
#include <vector>

using namespace std;

struct TreeNode {
   int val;
   TreeNode* left;
   TreeNode* right;
   TreeNode() : val(0), left(nullptr), right(nullptr) {}
   TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
   TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};
class Solution {
public:
   int findSecondMinimumValue(TreeNode* root) {
      return dfs(root, root->val);
   }

   int dfs(TreeNode* node, int value) {
      if(node == nullptr) {
         return -1;
      }
      if(node->val > value) {
         return node->val;
      }
      int lval = dfs(node->left, node->val);
      int rval = dfs(node->right, node->val);

      if(lval > value && rval > value) {
         return min(lval, rval);
      }

      return max(lval, rval);
   }
};
