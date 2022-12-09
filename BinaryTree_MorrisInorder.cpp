#include <iostream>
#include <vector>
using namespace std;

// Tree Node
struct Node
{
    int data;
    Node *left;
    Node *right;
};

vector<int> inOrder(Node *root)
{
    Node *curr = root;
    vector<int> in;

    while (curr)
    {
        if (curr->left == NULL)
        {
            in.push_back(curr->data);
            curr = curr->right;
        }
        else
        {
            Node *thread = curr->left;
            while (thread->right and thread->right != curr)
                thread = thread->right;

            if (thread->right == NULL)
            {
                thread->right = curr;
                curr = curr->left;
            }
            else
            {
                thread->right = NULL;
                in.push_back(curr->data);
                curr = curr->right;
            }
        }
    }
    return in;
}