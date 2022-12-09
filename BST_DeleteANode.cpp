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

// inorder predecessor
Node *inPred(Node *root)
{
    root = root->left;
    while (root->right)
    {
        root = root->right;
    }
    return root;
}

// Function to delete a node from BST.
Node *deleteNode(Node *root, int x)
{
    // your code goes here
    if (root->data == x)
    {
        // if root has 0 child
        if (!root->left and !root->right)
        {
            delete root;
            return NULL;
        }

        // if root has 1 child, either left or right
        if (root->left and !root->right) // only left child exists
        {
            Node *temp = root->left;
            delete root;
            return temp;
        }

        if (!root->left and root->right) // only right child exists
        {
            Node *temp = root->right;
            delete root;
            return temp;
        }

        // if both child exists
        if (root->left and root->right)
        {
            int in_pre = inPred(root)->data;
            root->data = in_pre;
            root->left = deleteNode(root->left, in_pre);
            return root;
        }
    }
    else if (x < root->data)
    {
        if (root->left)
            root->left = deleteNode(root->left, x);
    }
    else
    {
        if (root->right)
            root->right = deleteNode(root->right, x);
    }

    return root;
}