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
    void solve(TreeNode* root, map<int,vector<pair<int,int>>> &mp, int row, int col){
        if(root == nullptr) 
            return;
        
        mp[col].push_back({row, root->val});
        
        solve(root->left, mp, row+1, col-1);
        solve(root->right, mp, row+1, col+1);
    }
        
    
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        map<int,vector<pair<int,int>>> mp;
        vector<vector<int>> ds;      
        
        solve(root, mp, 0, 0);
        
        for(auto it:mp) {
            
            sort(it.second.begin(), it.second.end());
            vector<int> temp;
            
            for(auto i:it.second) {
                temp.push_back(i.second);
            }
            
            ds.push_back(temp);
        }        
        return ds;
    }
};