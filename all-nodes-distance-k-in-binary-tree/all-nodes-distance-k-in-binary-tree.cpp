/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
map<TreeNode*, TreeNode*>mp;
vector<int>ans;
set<TreeNode*>vis;

void findpar(TreeNode* node){
    if(!node) return;
    if(node->left){
        mp[node->left]=node;
        findpar(node->left);
    }
    if(node->right){
        mp[node->right]=node;
        findpar(node->right);
    }
}

void dfs(TreeNode* node, int k){
  if(vis.find(node)!=vis.end()) return ;
  vis.insert(node);
  if(k==0){
      ans.push_back(node->val);
      return;
  }
  if(node->left) dfs(node->left,k-1);
  if(node->right) dfs(node->right,k-1);
  TreeNode*p= mp[node];
  if(p) dfs(p,k-1);
}

    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        if(!root) return {};
        findpar(root);
        dfs(target,k);
        return ans;
       

    }
};