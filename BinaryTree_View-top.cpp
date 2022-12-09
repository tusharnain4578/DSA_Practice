#include <iostream>
#include <vector>
#include <queue>
#include <map>
using namespace std;

// practice --> https://practice.geeksforgeeks.org/problems/top-view-of-binary-tree/1
struct Node
{
    int data;
    Node *left;
    Node *right;
};
// reference --> https://www.youtube.com/watch?v=s1d8UGDCCN8
vector<int> topView(Node *root)
{
    vector<int> ans;
    if (!root)
        return ans;

    map<int, int> top_nodes;
    queue<pair<Node *, int>> q;
    q.push(make_pair(root, 0));

    while (!q.empty())
    {
        pair<Node *, int> t = q.front();
        q.pop();

        Node *this_node = t.first;
        int hd = t.second;

        if (top_nodes.find(hd) == top_nodes.end())
            top_nodes[hd] = this_node->data;

        if (this_node->left)
            q.push(make_pair(this_node->left, hd - 1));

        if (this_node->right)
            q.push(make_pair(this_node->right, hd + 1));
    }
    for (auto &i : top_nodes)
        ans.push_back(i.second);

    return ans;
}