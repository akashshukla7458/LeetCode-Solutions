int ans;

class sam
{
    public:
        bool bst;	// to check tree is bst or not
    int mx;	// max value in a tree
    int mn;	// min value in a tree
    int sum;	// current maximum sum       

    sam()
    {
        bst = true;
        mx = INT_MIN;
        mn = INT_MAX;
        sum = 0;
    }
};

class Solution
{
    public:
        int ans;

    sam solve(TreeNode *root)
    {
        if (root == NULL)
        {
            return sam();
        }

        sam p;

        sam l = solve(root->left);	// recursive call for left part
        sam r = solve(root->right);	// recursive call for right part

       	// this node include in BST
        if (l.bst == true and r.bst == true and l.mx < root->val and r.mn > root->val)
        {
            p.bst = true;
            p.mx = max(root->val, r.mx);
            p.mn = min(root->val, l.mn);
            p.sum = l.sum + r.sum + root->val;
        }
        else
        {
            p.bst = false;
            p.sum = max(l.sum, r.sum);
        }

        ans = max(ans, p.sum);
        return p;
    }

    int maxSumBST(TreeNode *root)
    {
        ans = 0;
        solve(root);
        return ans;
    }
};