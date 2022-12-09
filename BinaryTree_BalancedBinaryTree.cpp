#include <iostream>
using namespace std;

// practice --> https://leetcode.com/problems/balanced-binary-tree/
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

int depth(TreeNode *root)
{
    if (!root)
        return 0;

    int lh = depth(root->left);
    int rh = depth(root->right);

    if (lh == -1 || rh == -1)
        return -1;

    int bf = abs(lh - rh);
    if (bf > 1)
    {
        return -1;
    }

    return max(lh, rh) + 1;
}

bool isBalanced(TreeNode *root)
{
    if (depth(root) != -1)
        return true;

    return false;
}