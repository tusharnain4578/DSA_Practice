#include <iostream>
#include <stack>
using namespace std;

// practice --> https://leetcode.com/problems/two-sum-iv-input-is-a-bst/
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

// BST Iterator Class
class bstIterator
{
    // private members
    stack<TreeNode *> st;
    bool reverse;

    void pushAll(TreeNode *root)
    {
        while (root)
        {
            st.push(root);

            if (reverse)
                root = root->right;
            else
                root = root->left;
        }
    }

    // public members
public:
    bstIterator(TreeNode *root, bool reverse = false) : reverse(reverse)
    {
        pushAll(root);
    }

    int next()
    {
        TreeNode *temp = st.top();
        st.pop();

        if (reverse)
            pushAll(temp->left);
        else
            pushAll(temp->right);

        return temp->val;
    }
};

bool findTarget(TreeNode *root, int k)
{
    if (!root)
        return false;

    // true for reverse
    bstIterator l(root), r(root, true);

    // Genera 2 Sum logic for sorted series
    int i = l.next(), j = r.next();

    while (i < j)
    {
        if (i + j == k)
            return true;
        else if (i + j > k)
            j = r.next();
        else
            i = l.next();
    }

    return false;
}