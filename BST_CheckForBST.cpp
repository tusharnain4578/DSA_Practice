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

// using Morris Inorder algo, i am keeping a variable, every time of inorder if i get a value larger then the previous, if i get smaller than previous, then return false
bool isBST(Node *root)
{
    Node *curr = root;
    int num = INT_MIN;
    while (curr)
    {
        if (curr->left == NULL)
        {

            if (curr->data < num)
                return false;
            num = curr->data;

            curr = curr->right;
        }
        else
        {
            Node *pred = curr->left;

            while (pred->right and pred->right != curr)
                pred = pred->right;

            if (pred->right == NULL)
            {
                pred->right = curr;
                curr = curr->left;
            }
            else
            {
                pred->right = NULL;

                if (curr->data < num)
                    return false;
                num = curr->data;

                curr = curr->right;
            }
        }
    }
    return true;
}