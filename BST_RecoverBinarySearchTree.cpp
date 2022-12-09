#include <iostream>
using namespace std;

// practice --> https://leetcode.com/problems/recover-binary-search-tree/
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

void check(TreeNode *root, TreeNode *&prev, TreeNode *&first, TreeNode *&middle, TreeNode *&last)
{
    if (root->val < prev->val)
    {
        if (first == NULL)
        {
            first = prev;
            middle = root;
        }
        else
        {
            last = root;
        }
    }
    prev = root;
}
// using morris inorder
void recoverTree(TreeNode *root)
{
    if (!root)
        return;

    TreeNode *first, *middle, *last, *prev;
    first = middle = last = NULL;
    prev = new TreeNode(INT_MIN);

    TreeNode *curr = root;

    while (curr)
    {
        if (curr->left == NULL)
        {
            check(curr, prev, first, middle, last); // inorder data
            curr = curr->right;
        }
        else
        {
            TreeNode *pred = curr->left;

            while (pred->right and pred->right != curr)
                pred = pred->right;

            if (pred->right == NULL)
            {
                pred->right = curr;
                curr = curr->left;
            }
            else
            {
                pred->right = NULL;

                check(curr, prev, first, middle, last); // inorder data

                curr = curr->right;
            }
        }
    }

    if (first and last)
        swap(first->val, last->val);
    else if (first and middle)
        swap(first->val, middle->val);
}