#include <iostream>
using namespace std;

// practice --> https://leetcode.com/problems/same-tree/
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

bool isSameTree(TreeNode *p, TreeNode *q)
{
    // below if statement can also be written as
    // if(p==NULL || q == NULL)
    // return (p==q);
    if (p == NULL || q == NULL)
    {
        if (p == q)
            return true;
        else
            return false;
    }

    if (p->val == q->val && isSameTree(p->right, q->right) && isSameTree(p->left, q->left))
        return true;

    return false;
}