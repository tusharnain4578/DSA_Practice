#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;
// practice ---> https://practice.geeksforgeeks.org/problems/largest-independent-set-problem/1

// reference --> https://www.youtube.com/watch?v=O0qFZUpVxm0

// tree node structure
struct Node
{
    int data;
    struct Node *left;
    struct Node *right;

    Node(int x)
    {
        data = x;
        left = right = NULL;
    }
};
// ----------------------------------------------------
//--------------------------------------------------
//--------------------------------------------
//
//
// recursion
int rec(Node *root)
{
    if (root == NULL)
        return 0;

    int excluding_root = rec(root->left) + rec(root->right);

    int including_root = 1; // 1 for the root itself

    if (root->left)
        including_root += rec(root->left->left) + rec(root->left->right);

    if (root->right)
        including_root += rec(root->right->left) + rec(root->right->right);

    return max(excluding_root, including_root);
}
int LISS(Node *root)
{
    return rec(root);
}

// memoization - by using hashmap as dp
int mem(Node *root, unordered_map<Node *, int> &dp)
{
    if (root == NULL)
        return 0;

    if (dp.count(root))
        return dp[root];

    int excluding_root = mem(root->left, dp) + mem(root->right, dp);

    int including_root = 1; // 1 for the root itself

    if (root->left)
        including_root += mem(root->left->left, dp) + mem(root->left->right, dp);

    if (root->right)
        including_root += mem(root->right->left, dp) + mem(root->right->right, dp);

    return dp[root] = max(excluding_root, including_root);
}
int LISS(Node *root)
{
    unordered_map<Node *, int> dp;
    return mem(root, dp);
}

// Ig no more optimization