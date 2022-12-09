#include <iostream>
#include <vector>
using namespace std;

// practice --> https://practice.geeksforgeeks.org/problems/right-view-of-binary-tree/1/
struct Node
{
    int data;
    Node *left;
    Node *right;
};

void reversePreorder(Node *root, int level, vector<int> &ans)
{
    if (!root)
        return;

    if (ans.size() == level)
        ans.push_back(root->data);

    reversePreorder(root->right, level + 1, ans);
    reversePreorder(root->left, level + 1, ans);
}

vector<int> rightView(Node *root)
{
    vector<int> ans;
    reversePreorder(root, 0, ans);
    return ans;
}