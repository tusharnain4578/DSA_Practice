#include <iostream>
#include <vector>
#include <stack>
using namespace std;
// practice --> https://leetcode.com/problems/binary-tree-postorder-traversal/
//  This approach uses 2 stacks
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

vector<int> postorderTraversal(TreeNode *root)
{
    vector<int> ans;

    if (!root)
        return ans;

    stack<TreeNode *> st;

    TreeNode *curr = root;

    while (curr or !st.empty())
    {
        if (curr)
        {
            st.push(curr);
            curr = curr->left;
        }
        else
        {
            TreeNode *temp = st.top()->right;
            if (temp)
            { // if right node exist
                curr = temp;
            }
            else
            {
                // if right node doesn't exists
                temp = st.top();
                st.pop();

                ans.push_back(temp->val);

                while (!st.empty() and temp == st.top()->right)
                {
                    temp = st.top();
                    st.pop();
                    ans.push_back(temp->val);
                }
            }
        }
    }
    return ans;
}