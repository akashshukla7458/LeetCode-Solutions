class Solution
{
    public:

        int kthElement = 0;

    void sol(TreeNode *root, int &k)
    {

        if (root == NULL || k == 0)
        {
            return;
        }

        sol(root->left, k);

        if (k > 0)
        {

            kthElement = root->val;
            k--;
        }

        sol(root->right, k);
    }

    int kthSmallest(TreeNode *root, int k)
    {

        sol(root, k);
        return kthElement;
    }
};