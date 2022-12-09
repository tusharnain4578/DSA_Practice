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

// using Morris Inorder in reverse fashion
//(Our little secret -> basically i just replaced left and right from the genera Morris Inorder to get the inorder in descending order)
int kthLargest(Node *root, int k)
{
    Node *curr = root;
    int ans;
    while (curr)
    {
        if (curr->right == NULL)
        {
            ans = curr->data;
            k--;
            if (k == 0)
                break;
            curr = curr->left;
        }
        else
        {
            Node *pred = curr->right;
            while (pred->left and pred->left != curr)
                pred = pred->left;

            if (pred->left == NULL)
            {
                pred->left = curr;
                curr = curr->right;
            }
            else
            {
                pred->left = NULL;
                ans = curr->data;
                k--;
                if (k == 0)
                    break;
                curr = curr->left;
            }
        }
    }
    if (k != 0) // if k is greater then all elements count
        return -1;
    return ans;
}