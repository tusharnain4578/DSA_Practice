#include <iostream>
using namespace std;

// practice --> https://leetcode.com/problems/binary-tree-maximum-path-sum/
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

int height(TreeNode *root, int &maxsum)
{
    if (!root)
        return 0;

    int lh = max(0, height(root->left, maxsum));
    int rh = max(0, height(root->right, maxsum));

    maxsum = max(maxsum, lh + rh + root->val);

    return root->val + max(lh, rh);
}

int maxPathSum(TreeNode *root)
{
    int maxsum = INT_MIN;

    height(root, maxsum);

    return maxsum;
}