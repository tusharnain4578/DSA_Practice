#include <iostream>
using namespace std;

// practice --> https://practice.geeksforgeeks.org/problems/children-sum-parent/1
struct Node
{
    int data;
    struct Node *left;
    struct Node *right;

    Node(int x)
    {
        data = x;
        left = right = NULL;
    }
};

int isSumProperty(Node *root)
{
    if (!root or (!root->left and !root->right))
        return 1;

    int total = 0;
    if (root->left)
        total += root->left->data;

    if (root->right)
        total += root->right->data;

    if (total == root->data and isSumProperty(root->left) and isSumProperty(root->right))
        return 1;

    return 0;
}