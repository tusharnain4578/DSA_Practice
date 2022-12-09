#include <iostream>
#include <vector>
using namespace std;
// practice --> https://leetcode.com/problems/construct-binary-search-tree-from-preorder-traversal/
//   Definition for a binary tree node.
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

TreeNode *buildBst(vector<int> &pre, int n, int &i, int l, int r)
{
    // reference ---> https://www.youtube.com/watch?v=Bexswo4pqZQ
    if (i >= n || pre[i] > r || pre[i] < l)
        return NULL;

    TreeNode *root = new TreeNode(pre[i++]);
    root->left = buildBst(pre, n, i, l, root->val);
    root->right = buildBst(pre, n, i, root->val, r);

    return root;
}

TreeNode *bstFromPreorder(vector<int> &preorder)
{
    int n = preorder.size();
    int i = 0; // index-  pass it by reference
    return buildBst(preorder, n, i, INT_MIN, INT_MAX);
}