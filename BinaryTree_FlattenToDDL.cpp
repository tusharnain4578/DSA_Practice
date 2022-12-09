#include <iostream>
using namespace std;
// Binary Tree to DDL using inorder morris, you can use recursion also
struct Node
{
    int data;
    struct Node *left;
    struct Node *right;

    Node(int x)
    {
        data = x;
        left = NULL;
        right = NULL;
    }
};

void makeList(Node *&node, Node *newnode)
{
    node->right = newnode;
    newnode->left = node;
    node = node->right;
}

Node *bToDLL(Node *root)
{
    Node *head = NULL, *tail = NULL;
    Node *curr = root;
    bool first_time_flag = 0;
    while (curr)
    {
        if (curr->left == NULL)
        {
            if (first_time_flag == 0)
            {
                head = tail = curr;
                first_time_flag = 1;
            }
            else
            {
                makeList(tail, curr);
            }

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

                if (first_time_flag == 0)
                {
                    head = tail = curr;
                    first_time_flag = 1;
                }
                else
                {
                    makeList(tail, curr);
                }

                curr = curr->right;
            }
        }
    }
    return head;
}