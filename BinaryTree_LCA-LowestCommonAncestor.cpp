#include <iostream>
using namespace std;

// Structure of Node
struct Node
{
    int data;
    Node *left;
    Node *right;
};

Node *lca(Node *root, int n1, int n2)
{
    if (!root)
        return NULL;

    if (root->data == n1 || root->data == n2)
        return root;

    Node *left = lca(root->left, n1, n2);
    Node *right = lca(root->right, n1, n2);

    if (left != NULL and right != NULL)
        return root;
    else if (left == NULL and right != NULL)
        return right;
    else if (left != NULL and right == NULL)
        return left;
    else
        return NULL;
}