#include <iostream>
#include <vector>
#include <stack>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

vector<vector<int>> allTraversal(TreeNode *root)
{
    vector<vector<int>> all_traversals;

    if (!root)
        return all_traversals;

    vector<int> pre, in, post;

    stack<pair<TreeNode *, int>> st;

    st.push(make_pair(root, 1));

    while (!st.empty())
    {
        pair<TreeNode *, int> p = st.top();
        st.pop();

        if (p.second == 1)
        {
            pre.push_back(p.first->val);

            p.second++;
            st.push(p);

            if (p.first->left)
                st.push(make_pair(p.first->left, 1));
        }
        else if (p.second == 2)
        {
            in.push_back(p.first->val);

            p.second++;
            st.push(p);

            if (p.first->right)
                st.push(make_pair(p.first->right, 1));
        }
        else
        {
            post.push_back(p.first->val);
        }
    }

    all_traversals.push_back(pre);
    all_traversals.push_back(in);
    all_traversals.push_back(post);

    return all_traversals;
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

    vector<vector<int>> all_traversals = allTraversal(root);

    cout << "Preorder -> ";
    for (auto &i : all_traversals[0])
        cout << i << " ";

    cout << endl
         << endl;

    cout << "Inorder -> ";
    for (auto &i : all_traversals[1])
        cout << i << " ";

    cout << endl
         << endl;

    cout << "Postorder -> ";
    for (auto &i : all_traversals[2])
        cout << i << " ";

    cout << endl;

    return 0;
}