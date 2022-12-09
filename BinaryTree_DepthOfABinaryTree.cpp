#include <iostream>
using namespace std;

// practice --> https://leetcode.com/problems/maximum-depth-of-binary-tree/
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

// height
int maxDepth(TreeNode *root)
{
    if (!root)
        return 0;
    int lh = maxDepth(root->left);
    int rh = maxDepth(root->right);

    return max(lh, rh) + 1;
}

int main()
{
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right = new TreeNode(3);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(7);

    cout << maxDepth(root) << endl;

    return 0;
}