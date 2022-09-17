/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution
{
    public:
        Node* connect(Node *root)
        {
            if (root == NULL) return NULL;
            Node *cur = root;
            while (cur->left != NULL)
            {
                Node *temp = cur;
                while (cur != NULL)
                {
                    cur->left->next = cur->right;
                    cur->right->next = cur->next == NULL ? NULL : cur->next->left;
                    cur = cur->next;
                }
                cur = temp->left;
            }
            return root;
        }
};