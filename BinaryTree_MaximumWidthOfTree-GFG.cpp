#include <iostream>
#include <queue>
using namespace std;

// practice--->https://practice.geeksforgeeks.org/problems/maximum-width-of-tree/1/
//  Structure of Node
struct Node
{
    int data;
    Node *left;
    Node *right;
};

int getMaxWidth(Node *root)
{

    // Your code here
    if (!root)
        return 0;
    queue<Node *> q;
    q.push(root);
    int ans = 0;
    while (!q.empty())
    {
        int size = q.size();
        ans = max(ans, size);
        for (int i = 0; i < size; i++)
        {
            Node *node = q.front();
            q.pop();
            if (node->left)
                q.push(node->left);
            if (node->right)
                q.push(node->right);
        }
    }
    return ans;
}