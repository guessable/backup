/*
 * 前，中，后序迭代遍历二叉树
 */
#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;
struct TreeNode {
   int val;
   TreeNode* left;
   TreeNode* right;
   TreeNode(): val(0), left(nullptr), right(nullptr) {};
   TreeNode(int val, TreeNode* left, TreeNode* right):
      val(val), left(left), right(right) {};
};

/*
 * 前序
 */
vector<int> preOrder(TreeNode* root) {
   vector<int> ans;
   if(root == nullptr) {
      return ans;
   }

   stack<TreeNode*> stk;
   stk.push(root);
   while(!stk.empty()) {
      TreeNode* cur = stk.top();
      stk.pop();
      ans.push_back(cur->val);
      if(root->right != nullptr) {
         stk.push(root->right);
      }
      if(root->left != nullptr) {
         stk.push(root->left);
      }
   }
   return ans;
}

/*
 * 中序
 */
vector<int> inOrder(TreeNode* root) {
   vector<int> ans;
   if(root == nullptr) {
      return ans;
   }
   stack<TreeNode*> stk;
   TreeNode* cur = root;

   while(!stk.empty() || cur != nullptr) {
      if(cur != nullptr) {
         stk.push(cur);
         cur = cur->left;
      } else {
         cur = stk.top();
         stk.pop();
         ans.push_back(cur->val);
         cur = cur->right;
      }
   }
   return ans;
}

/*
 * 后序
 */
vector<int> postOrder(TreeNode* root) {
   vector<int> ans;
   if(root == nullptr) {
      return ans;
   }

   stack<TreeNode*> stk;
   stk.push(root);
   while(!stk.empty()) {
      TreeNode* cur = stk.top();
      stk.pop();
      ans.push_back(cur->val);
      if(root->left != nullptr) {
         stk.push(root->left);
      }
      if(root->right != nullptr) {
         stk.push(root->right);
      }
   }
   reverse(ans.begin(), ans.end());
   return ans;
}

int main() {
   return 0;
}
