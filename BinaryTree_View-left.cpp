#include <iostream>
#include <vector>

using namespace std;

// practice --> https://practice.geeksforgeeks.org/problems/left-view-of-binary-tree/1
struct Node
{
    int data;
    Node *left;
    Node *right;
};

void preorder(Node *root, int level, vector<int> &ans)
{
    if (!root)
        return;

    if (ans.size() == level)
        ans.push_back(root->data);

    preorder(root->left, level + 1, ans);
    preorder(root->right, level + 1, ans);
}

vector<int> leftView(Node *root)
{
    vector<int> ans;
    preorder(root, 0, ans);
    return ans;
}