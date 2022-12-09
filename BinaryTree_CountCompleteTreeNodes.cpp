#include <iostream>
using namespace std;

// You can also just use iterative preorder to count nodes, ig that is more efficient

// practice --> https://leetcode.com/problems/count-complete-tree-nodes/
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

int getLeftHeight(TreeNode *root)
{
    int lh = 0;
    while (root)
    {
        lh++;
        root = root->left;
    }
    return lh;
}

int getRightHeight(TreeNode *root)
{
    int rh = 0;
    while (root)
    {
        rh++;
        root = root->right;
    }
    return rh;
}

int countNodes(TreeNode *root)
{
    if (!root)
        return 0;

    int lh = getLeftHeight(root);
    int rh = getRightHeight(root);

    if (lh == rh)
        return (1 << lh) - 1; // n^2 - 1

    return 1 + countNodes(root->left) + countNodes(root->right);
}