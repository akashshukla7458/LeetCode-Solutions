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
        TreeNode* constructBST(vector<int> &preorder, int prestart, int preend, vector<int> &inorder, int instart, int inend, map< int, int> &mp)
        {
            if (instart > inend || prestart > preend) return NULL;
            TreeNode *root = new TreeNode(preorder[prestart]);
            int elem = mp[root->val];
            int nelem = elem - instart;	// nodes in left subtree

            root->left = constructBST(preorder, prestart + 1, prestart + nelem, inorder, instart, elem - 1, mp);
            root->right = constructBST(preorder, prestart + nelem + 1, preend, inorder, elem + 1, inend, mp);

            return root;
        }

    TreeNode* buildTree(vector<int> &preorder, vector<int> &inorder)
    {
        int prestart = 0, preend = preorder.size() - 1;
        int instart = 0, inend = inorder.size() - 1;

        map<int, int> mp;
        for (int i =instart; i<=inend;i++)
        {
            mp[inorder[i]] = i;
        }
        return constructBST(preorder, prestart, preend, inorder, instart, inend, mp);
    }
};