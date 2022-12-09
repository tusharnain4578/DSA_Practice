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
// using Morris Inorder
int KthSmallestElement(Node *root, int k)
{
    Node *curr = root;
    int ans;
    while (curr)
    {
        if (curr->left == NULL)
        {
            ans = curr->data;
            k--;
            if (k == 0)
                break;
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
                ans = curr->data;
                k--;
                if (k == 0)
                    break;
                curr = curr->right;
            }
        }
    }
    if (k != 0) // if k is greater then all elements count
        return -1;
    return ans;
}