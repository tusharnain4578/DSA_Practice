// From Postorder and Inorder
#include <iostream>
#include <unordered_map>
using namespace std;

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

Node *constructTree(int post[], int post_start, int post_end, int in[], int in_start, int in_end, unordered_map<int, int> &mp)
{
    if (post_start > post_end || in_start > in_end)
        return NULL;

    Node *node = new Node(post[post_end]);

    int in_point = mp[node->data];

    node->left = constructTree(post, post_start, post_start + in_point - in_start - 1, in, in_start, in_point - 1, mp);
    node->right = constructTree(post, post_start + in_point - in_start, post_end - 1, in, in_point + 1, in_end, mp);

    return node;
}

Node *buildTree(int in[], int post[], int n)
{
    // Your code here
    int in_start = 0, in_end = n - 1, post_start = 0, post_end = n - 1;

    unordered_map<int, int> mp;

    for (int i = 0; i < n; i++)
        mp[in[i]] = i;

    return constructTree(post, post_start, post_end, in, in_start, in_end, mp);
}