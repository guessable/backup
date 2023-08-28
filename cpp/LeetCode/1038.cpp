#include <iostream>
#include <vector>

using namespace std;
struct TreeNode {
   int val;
   TreeNode* left;
   TreeNode* right;
   TreeNode(): val(0), left(nullptr), right(nullptr) {};
   TreeNode(int val): val(val), left(nullptr), right(nullptr) {};
   TreeNode(int val, TreeNode* left, TreeNode* right): val(val), left(left), right(right) {};
};

class Solution {
public:
   int sum = 0;
   TreeNode* bstToGst(TreeNode* root) {
      if(root == nullptr) {
         return nullptr;
      }

      trav(root);
      return root;
   }

   void trav(TreeNode* root) {
      if(root == nullptr) {
         return ;
      }

      trav(root->right);
      root->val = root->val + sum;
      sum = root->val;
      trav(root->left);
   }
};
