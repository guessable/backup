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
   int countNodes(TreeNode* root) {
      if(root == nullptr) {
         return 0;
      }

      TreeNode* leftTree = root->left;
      TreeNode* rightTree = root->right;

      int leftDepth = 0, rightDepth = 0;
      while(leftTree) {
         leftTree = leftTree->left;
         ++leftDepth;
      }
      while(rightTree) {
         rightTree = rightTree->right;
         ++rightDepth;
      }

      if(leftDepth == rightDepth) {
         return (2 << rightDepth) - 1;
      }
      return countNodes(root->left) + countNodes(root->right) + 1;
   }
};
