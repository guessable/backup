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
   vector<vector<int>> result;
   vector<vector<int>> pathSum(TreeNode* root, int target) {
      vector<int> track;
      dfs(track, root, target);
      return result;
   }

   void dfs(vector<int>& track, TreeNode* root, int target) {
      if(!root) {
         return ;
      }

      if(!root->left && !root->right && root->val == target) {
         track.push_back(root->val);
         result.push_back(track);
         track.pop_back();
         return ;
      }

      track.push_back(root->val);
      dfs(track, root->left, target - root->val);
      track.pop_back();

      track.push_back(root->val);
      dfs(track, root->right, target - root->val);
      track.pop_back();
   }
};
