#include <iostream>
#include <queue>
#include <sstream>
using namespace std;
// practice --> https://leetcode.com/problems/serialize-and-deserialize-binary-tree/

// Definition for a binary tree node.
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

string serialize(TreeNode *root)
{
    if (!root)
        return "";

    string sr = "";

    queue<TreeNode *> q;
    q.push(root);

    while (!q.empty())
    {
        TreeNode *node = q.front();
        q.pop();

        if (node == NULL)
            sr.append("#,");
        else
            sr.append(to_string(node->val) + ",");

        if (node != NULL)
        {
            q.push(node->left);
            q.push(node->right);
        }
    }
    return sr;
}

// Decodes your encoded data to tree.
TreeNode *deserialize(string data)
{
    if (data.size() == 0)
        return NULL;

    stringstream s(data);
    string str;

    getline(s, str, ',');

    TreeNode *root = new TreeNode(stoi(str));

    queue<TreeNode *> q;
    q.push(root);

    while (!q.empty())
    {
        TreeNode *node = q.front();
        q.pop();

        getline(s, str, ',');

        if (str == "#")
            node->left = NULL;
        else
        {
            node->left = new TreeNode(stoi(str));
            q.push(node->left);
        }

        getline(s, str, ',');

        if (str == "#")
            node->right = NULL;
        else
        {
            node->right = new TreeNode(stoi(str));
            q.push(node->right);
        }
    }
    return root;
}
