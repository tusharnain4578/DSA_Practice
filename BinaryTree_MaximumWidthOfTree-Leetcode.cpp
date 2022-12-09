#include <iostream>
#include <queue>
using namespace std;

// Definition for a binary tree node.
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

int widthOfBinaryTree(TreeNode *root)
{
    if (!root)
        return 0;

    queue<pair<TreeNode *, unsigned long long>> q;
    unsigned long long max_width = 0;
    q.push(make_pair(root, 0));

    while (!q.empty())
    {
        int size = q.size();
        unsigned long long first_index, last_index;
        for (int i = 0; i < size; i++)
        {
            TreeNode *node = q.front().first;
            unsigned long long index = q.front().second;
            q.pop();

            if (i == 0)
                first_index = index;
            if (i == size - 1)
                last_index = index;

            if (node->left)
                q.push(make_pair(node->left, 2 * index));
            if (node->right)
                q.push(make_pair(node->right, 2 * index + 1));
        }
        max_width = max(max_width, last_index - first_index + 1);
    }
    return max_width;
}