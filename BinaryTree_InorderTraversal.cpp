#include <iostream>
#include <vector>
#include <stack>
using namespace std;

// practice --> https://leetcode.com/problems/binary-tree-inorder-traversal/
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

vector<int> inorderTraversal(TreeNode *root)
{
    vector<int> ans;
    if (!root)
        return ans;

    stack<TreeNode *> st;

    TreeNode *curr = root;

    while (curr or !st.empty())
    {

        while (curr)
        {
            st.push(curr);
            curr = curr->left;
        }

        curr = st.top();
        st.pop();

        ans.push_back(curr->val);

        curr = curr->right;
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

    vector<int> pre = inorderTraversal(root);

    for (auto &i : pre)
        cout << i << " ";

    return 0;
}