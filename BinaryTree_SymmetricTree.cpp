#include <iostream>
using namespace std;

// practice --> https://practice.geeksforgeeks.org/problems/symmetric-tree/1/
struct Node
{
    int data;
    Node *left;
    Node *right;
};

bool isSym(Node *x, Node *y)
{
    if (x == NULL or y == NULL)
        return x == y;

    return (x->data == y->data) and isSym(x->left, y->right) and isSym(x->right, y->left);
}

bool isSymmetric(struct Node *root)
{
    if (!root)
        return true;

    return isSym(root->left, root->right);
}