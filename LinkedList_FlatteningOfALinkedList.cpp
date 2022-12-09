#include <bits/stdc++.h>
using namespace std;

// practice --> https://practice.geeksforgeeks.org/problems/flattening-a-linked-list/1
struct Node
{
    int data;
    struct Node *next;
    struct Node *bottom;

    Node(int x)
    {
        data = x;
        next = NULL;
        bottom = NULL;
    }
};

Node *merge(Node *l1, Node *l2)
{
    if (l1 == NULL)
        return l2;
    if (l2 == NULL)
        return l1;

    Node *dummy = new Node(-1);
    Node *t = dummy;

    while (l1 && l2)
    {
        if (l1->data < l2->data)
        {
            t->bottom = l1;
            l1 = l1->bottom;
        }
        else
        {
            t->bottom = l2;
            l2 = l2->bottom;
        }
        t = t->bottom;
    }
    if (l1)
        t->bottom = l1;
    if (l2)
        t->bottom = l2;

    return dummy->bottom;
}

Node *flatten(Node *root)
{
    if (root == NULL)
        return root;

    Node *merged_list = flatten(root->next);

    return merge(root, merged_list);
}

int main()
{

    return 0;
}