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

bool getPath(Node *root, vector<int> &path, int target)
{
    if (!root)
        return false;

    path.push_back(root->data);

    if (root->data == target)
        return true;

    if (getPath(root->left, path, target) or getPath(root->right, path, target))
        return true;

    path.pop_back();
    return false;
}

vector<int> rootToNode(Node *root, int target)
{
    vector<int> path;
    getPath(root, path, target);

    return path;
}