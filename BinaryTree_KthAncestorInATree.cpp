#include <iostream>
using namespace std;

// Structure of Node
struct Node
{
    int data;
    Node *left;
    Node *right;
};
// reference ---> https://www.youtube.com/watch?v=QG0hE0R_ng4&t=2271s
Node *solve(Node *root, int &k, int node)
{
    if (!root)
        return NULL;

    if (root->data == node)
        return root;

    Node *left = solve(root->left, k, node);
    Node *right = solve(root->right, k, node);

    if (left == NULL and right != NULL)
    {
        k--;
        if (k <= 0) // stress here
        {
            k = INT_MAX; // locking the root
            return root;
        }
        return right;
    }
    else if (left != NULL and right == NULL)
    {
        k--;
        if (k <= 0)
        {
            k = INT_MAX; // locking the root
            return root;
        }
        return left;
    }
    return NULL;
}

int kthAncestor(Node *root, int k, int node)
{
    Node *ans = solve(root, k, node);

    if (!ans || ans->data == node)
        return -1;

    return ans->data;
}