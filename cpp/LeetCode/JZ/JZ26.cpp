#include <iostream>
#include <vector>

using namespace std;

struct TreeNode {
   int val;
   TreeNode* left;
   TreeNode* right;
   TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
class Solution {
public:
   bool isSubStructure(TreeNode* A, TreeNode* B) {
      if(!A || !B) {
         return false;
      }
      return dfs(A, B);
   }

   bool check(TreeNode* A, TreeNode* B) {
      if(!B) {
         return true;
      }

      if((!A && B) || (!B && A) || (A->val != B->val)) {
         return false;
      }

      return check(A->left, B->left) || check(A->right, B->right);
   }

   bool dfs(TreeNode* A, TreeNode* B) {
      if(!A) {
         return false;
      }

      return check(A, B) || dfs(A->left, B) || dfs(A->right, B);
   }
};
