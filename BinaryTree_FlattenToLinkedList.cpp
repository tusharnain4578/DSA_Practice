#include <iostream>
using namespace std;
// practice ---> https://practice.geeksforgeeks.org/problems/flatten-binary-tree-to-linked-list/1
struct Node
{
    int key;
    Node *left, *right;
};

// By Morris Preorder Traversal - Space Complexity O(1)
void flatten1(Node *root)
{
    // reference ---> https://www.youtube.com/watch?v=2BdY9fixMrM
    Node *curr = root;

    while (curr)
    {
        if (curr->left)
        {
            Node *pred = curr->left;

            while (pred->right)
                pred = pred->right;

            pred->right = curr->right;
            curr->right = curr->left;
            curr->left = NULL;
        }
        curr = curr->right;
    }
}

// By recursive Preorder traversal
void flatten2(Node *root)
{
    Node *curr = root;

    if (curr)
    {
        if (curr->left)
        {
            Node *pred = curr->left;
            while (pred->right)
                pred = pred->right;
            pred->right = curr->right;
            curr->right = curr->left;
            curr->left = NULL;
        }
        flatten2(curr->right);
    }
}