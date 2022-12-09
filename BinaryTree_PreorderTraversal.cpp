#include <iostream>
#include <vector>
#include <stack>
using namespace std;
// practice --> https://leetcode.com/problems/binary-tree-preorder-traversal/
//    Definition for a binary tree node.
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

vector<int> preorderTraversal(TreeNode *root)
{
    // reference --> https://www.youtube.com/watch?v=Bfqd8BsPVuw
    //  Preorder -> Root Left Right

    vector<int> ans;
    if (root == NULL)
        return ans;

    stack<TreeNode *> st;
    st.push(root);

    while (!st.empty())
    {
        TreeNode *node = st.top();
        st.pop();
        ans.push_back(node->val);

        if (node->right)
            st.push(node->right);
        if (node->left)
            st.push(node->left);
    }
    return ans;
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

    vector<int> pre = preorderTraversal(root);

    for (auto &i : pre)
        cout << i << " ";

    return 0;
}