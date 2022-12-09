#include <iostream>
#include <vector>
using namespace std;

// Structure of Node
struct Node
{
    int data;
    Node *left;
    Node *right;
};

void getPath(Node *root, vector<int> &path, vector<vector<int>> &res)
{
    if (!root)
        return;

    path.push_back(root->data);

    if (!root->left and !root->right)
    {
        res.push_back(path);
    }

    getPath(root->left, path, res);
    getPath(root->right, path, res);

    path.pop_back();
}

vector<vector<int>> Paths(Node *root)
{
    vector<int> path;
    vector<vector<int>> res;
    getPath(root, path, res);
    return res;
}