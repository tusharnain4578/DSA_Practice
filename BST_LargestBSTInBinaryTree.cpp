#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *left, *right;
    Node(int val) : data(val), left(NULL), right(NULL) {}
};

class nodeData
{
public:
    int min_node, max_node, max_size;
    nodeData(int min_node, int max_node, int max_size) : min_node(min_node), max_node(max_node), max_size(max_size) {}
};

// We will be using postorder traversal because, we need the information from both the nodes(left and right), then we have to proceed next
nodeData solve(Node *root)
{
    if (!root)
        return nodeData(INT_MAX, INT_MIN, 0); // An empty tree is a BST of size 0.

    // Get values from left and right subtree of current tree.
    nodeData left = solve(root->left);
    nodeData right = solve(root->right);

    // Current node is greater than max in left AND smaller than min in right, it is a BST.
    if (root->data > left.max_node and root->data < right.min_node) // then it's a bst
        return nodeData(min(root->data, left.min_node), max(root->data, right.max_node), left.max_size + right.max_size + 1);

    // Otherwise, return [-infinity, infinity] so that parent can't be valid BST
    return nodeData(INT_MIN, INT_MAX, max(left.max_size, right.max_size));
}

/*You are required to complete this method */
// Return the size of the largest sub-tree which is also a BST
int largestBst(Node *root)
{
    return solve(root).max_size;
}