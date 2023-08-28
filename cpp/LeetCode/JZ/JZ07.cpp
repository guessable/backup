#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct TreeNode {
   int val;
   TreeNode* left;
   TreeNode* right;
   TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
   TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
      if(preorder.empty()) {
         return nullptr;
      }

      TreeNode* root = new TreeNode(preorder[0]);

      auto it = find(inorder.begin(), inorder.end(), preorder[0]);
      vector<int> leftIn(inorder.begin(), it);
      vector<int> rightIn(it + 1, inorder.end());

      int leftLen = leftIn.size();

      vector<int> leftPre(preorder.begin() + 1,
                          preorder.begin() + 1 + leftLen);
      vector<int> rightPre(preorder.begin() + 1 + leftLen,
                           preorder.end());
      root->left = buildTree(leftPre, leftIn);
      root->right = buildTree(rightPre, rightIn);
      return root;
   }
};
