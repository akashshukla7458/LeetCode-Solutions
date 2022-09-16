/**
 *Definition for a binary tree node.
 *struct TreeNode {
 *    int val;
 *    TreeNode * left;
 *    TreeNode * right;
 *    TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 *};
 */
class Solution
{
    public:
        int maxPath_Util(TreeNode *root, int &res)
        {
            if (root == NULL)
            {
                return 0;
            }
            int l =max(0,maxPath_Util(root->left, res)) ;
            int r = max(0,maxPath_Util(root->right, res));
            res = max(res, (l + r) + root->val);

            return (max(l, r) + root->val);
            }
            int maxPathSum(TreeNode *root)
            {
                if (root == NULL)
                {
                    return 0;
                }
                int res = INT_MIN;
                maxPath_Util(root, res);
                return res;
            }
        };