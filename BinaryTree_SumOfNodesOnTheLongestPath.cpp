// Sum of the Longest Bloodline of a Tree (Sum of nodes on the longest path from root to leaf node)
#include <iostream>
using namespace std;

// Structure of Node
struct Node
{
    int data;
    Node *left;
    Node *right;
};
// reference ---> https://www.youtube.com/watch?v=QG0hE0R_ng4
void solve(Node *root, int len, int &maxlen, int sum, int &maxsum)
{
    if (!root)
    {
        if (len > maxlen)
        {
            maxlen = len;
            maxsum = sum;
        }
        else if (len == maxlen)
            maxsum = max(maxsum, sum);

        return;
    }

    sum += root->data;

    solve(root->left, len + 1, maxlen, sum, maxsum);
    solve(root->right, len + 1, maxlen, sum, maxsum);
}

int sumOfLongRootToLeafPath(Node *root)
{
    int maxsum = 0, maxlen = 0;

    solve(root, 0, maxlen, 0, maxsum);

    return maxsum;
}