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

vector<int> preOrder(Node *root)
{
    Node *curr = root;
    vector<int> pre;

    while (curr)
    {

        if (curr->left == NULL)
        {
            pre.push_back(curr->data);
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
                pre.push_back(curr->data);
                curr = curr->left;
            }
            else
            {
                thread->right = NULL;
                curr = curr->right;
            }
        }
    }
    return pre;
}