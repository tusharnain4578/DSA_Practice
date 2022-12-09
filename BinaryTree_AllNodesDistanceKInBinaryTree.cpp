#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
using namespace std;

//   Definition for a binary tree node.
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

void markParents(TreeNode *root, unordered_map<TreeNode *, TreeNode *> &parent)
{
    queue<TreeNode *> q;
    q.push(root);

    while (!q.empty())
    {
        TreeNode *this_node = q.front();
        q.pop();

        if (this_node->left)
        {
            parent[this_node->left] = this_node;
            q.push(this_node->left);
        }
        if (this_node->right)
        {
            parent[this_node->right] = this_node;
            q.push(this_node->right);
        }
    }
}

vector<int> distanceK(TreeNode *root, TreeNode *target, int k)
{
    unordered_map<TreeNode *, TreeNode *> parent; // for parents of node
    markParents(root, parent);                    // getting parents
    unordered_map<TreeNode *, bool> visited;      // for visited nodes
    vector<int> ans;

    queue<TreeNode *> q;
    q.push(target);
    visited[target] = true;

    while (!q.empty())
    {
        int size = q.size();
        if (k-- == 0)
            break;
        for (int i = 0; i < size; i++)
        {
            TreeNode *this_node = q.front();
            q.pop();

            if (this_node->left and !visited[this_node->left])
            {
                q.push(this_node->left);
                visited[this_node->left] = true;
            }
            if (this_node->right and !visited[this_node->right])
            {
                q.push(this_node->right);
                visited[this_node->right] = true;
            }
            if (parent[this_node] and !visited[parent[this_node]])
            {
                q.push(parent[this_node]);
                visited[parent[this_node]] = true;
            }
        }
    }

    while (!q.empty())
    {
        ans.push_back(q.front()->val);
        q.pop();
    }
    return ans;
}