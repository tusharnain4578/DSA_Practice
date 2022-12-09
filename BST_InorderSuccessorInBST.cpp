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

// returns the inorder successor of the Node x in BST (rooted at 'root')
Node *inOrderSuccessor(Node *root, Node *x)
{
    // remember i did this on my own without any tutorial
    Node *ans = new Node(INT_MAX);

    Node *curr = root;

    while (curr)
    {
        if (curr->data > x->data and curr->data < ans->data)
        {
            ans = curr;
        }

        if (x->data < curr->data) // in case of less // please please do a hard dry run
        {
            curr = curr->left;
        }
        else
        { // in case of high
            curr = curr->right;
        }
    }
    if (ans->data == INT_MAX)
        ans->data = -1;
    return ans;
}