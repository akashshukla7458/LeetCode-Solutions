/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
vector<TreeNode*>subtree(int s, int e){
   vector<TreeNode*>res;
    if(s>e) {
        res.push_back(NULL);
        return res;
    }

    for(int i=s;i<=e;i++){
        vector<TreeNode*>leftsubtree= subtree(s,i-1);
        vector<TreeNode*>rightsubtree= subtree(i+1,e);

        for(TreeNode* left: leftsubtree){
            for(TreeNode* right: rightsubtree){
                TreeNode* root= new TreeNode(i);
                root->left= left;
                root->right= right;
                res.push_back(root);
            }
        }
    }
    return res;
}
    vector<TreeNode*> generateTrees(int n) {
       return subtree(1,n);
    }
};