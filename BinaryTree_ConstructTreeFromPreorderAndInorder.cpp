// From Preorder and Inorder
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

Node *constructTree(int pre[], int pre_start, int pre_end, int in[], int in_start, int in_end, unordered_map<int, int> &mp)
{
    if (in_start > in_end || pre_start > pre_end)
        return NULL;

    Node *node = new Node(pre[pre_start]);

    int in_point = mp[node->data]; // or mp[pre[pre_start];
    int before_inpoint = in_point - in_start;

    node->left = constructTree(pre, pre_start + 1, pre_start + before_inpoint, in, in_start, in_point - 1, mp);
    node->right = constructTree(pre, pre_start + before_inpoint + 1, pre_end, in, in_point + 1, in_end, mp);

    return node;
}

Node *buildTree(int in[], int pre[], int n)
{
    int in_start = 0, in_end = n - 1, pre_start = 0, pre_end = n - 1;

    unordered_map<int, int> mp;

    for (int i = 0; i < n; i++)
        mp[in[i]] = i;

    return constructTree(pre, pre_start, pre_end, in, in_start, in_end, mp);
}