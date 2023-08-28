#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

struct TreeNode {
   int val;
   TreeNode* left;
   TreeNode* right;
   TreeNode(int x) : val(x), left(NULL), right(NULL) {}
   TreeNode(int x, TreeNode* left, TreeNode* right): val(x), left(left), right(right) {}
};

class Solution {
public:
   unordered_map<int, TreeNode*> par;
   vector<int> ans;
   void findPar(TreeNode* root) {
      if(root->left != nullptr) {
         par[root->left->val] = root;
         findPar(root->left);
      }
      if(root->right != nullptr) {
         par[root->right->val] = root;
         findPar(root->right);
      }
   }

   void dfs(TreeNode* node, TreeNode* from, int depth, int k) {
      if(node == nullptr) {
         return ;
      }
      if(depth == k) {
         ans.push_back(node->val);
         return ;
      }

      if(node->left != from) {
         dfs(node->left, node, depth + 1, k);
      }
      if(node->right != from) {
         dfs(node->right, node, depth + 1, k);
      }
      if(par[node->val] != from) {
         dfs(par[node->val], node, depth + 1, k);
      }
   }

   vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
      findPar(root);
      dfs(target, nullptr, 0, k);
      return ans;
   }
};
