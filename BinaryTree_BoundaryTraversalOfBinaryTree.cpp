#include <iostream>
#include <vector>
using namespace std;

struct Node
{
    int data;
    Node *left, *right;
};

bool isLeaf(Node *root)
{
    return !root->left and !root->right;
}

void addLeftBoundary(Node *root, vector<int> &boundary)
{
    Node *curr = root->left;

    while (curr)
    {
        if (!isLeaf(curr))
            boundary.push_back(curr->data);
        if (curr->left)
            curr = curr->left;
        else
            curr = curr->right;
    }
}

void addRightBoundary(Node *root, vector<int> &boundary)
{
    Node *curr = root->right;
    vector<int> temp;
    while (curr)
    {
        if (!isLeaf(curr))
            temp.push_back(curr->data);
        if (curr->right)
            curr = curr->right;
        else
            curr = curr->left;
    }

    for (int i = 0; i < temp.size(); i++)
        boundary.push_back(temp[temp.size() - 1 - i]);
}

void addLeafNodes(Node *root, vector<int> &boundary)
{
    if (isLeaf(root))
    {
        boundary.push_back(root->data);
        return;
    }

    if (root->left)
        addLeafNodes(root->left, boundary);

    if (root->right)
        addLeafNodes(root->right, boundary);
}

vector<int> boundary(Node *root)
{
    vector<int> boundary_traversal;

    if (!root)
        return boundary_traversal;

    if (!isLeaf(root))
        boundary_traversal.push_back(root->data);

    addLeftBoundary(root, boundary_traversal);
    addLeafNodes(root, boundary_traversal);
    addRightBoundary(root, boundary_traversal);

    return boundary_traversal;
}