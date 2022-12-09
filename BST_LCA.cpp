#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;

    Node(int val)
    {
        data = val;
        left = right = NULL;
    }
};

Node *LCA(Node *root, int n1, int n2)
{
    if (!root)
        return NULL;

    int curr = root->data;

    if (n1 < curr and n2 < curr)
        return LCA(root->left, n1, n2);

    if (n1 > curr and n2 > curr)
        return LCA(root->right, n1, n2);

    return root;
}