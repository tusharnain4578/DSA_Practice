#include <iostream>
using namespace std;

// reference ---> https://www.youtube.com/watch?v=QG0hE0R_ng4
//  Structure of Node
struct Node
{
    int data;
    Node *left;
    Node *right;
};
// <include, exclude>
pair<int, int> solve(Node *root)
{
    if (!root)
        return make_pair(0, 0);

    pair<int, int> left = solve(root->left);
    pair<int, int> right = solve(root->right);

    pair<int, int> res;
    res.first = root->data + left.second + right.second;
    res.second = max(left.first, left.second) + max(left.first, left.second);

    return res;
}

int getMaxSum(Node *root)
{
    pair<int, int> ans = solve(root);

    return max(ans.first, ans.second);
}