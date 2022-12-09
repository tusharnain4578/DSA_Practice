#include <iostream>
#include <vector>
#include <queue>
#include <map>
using namespace std;
// practice --> https://practice.geeksforgeeks.org/problems/print-a-binary-tree-in-vertical-order/1
struct Node
{
    int data;
    Node *left;
    Node *right;
};
// reference --> https://www.youtube.com/watch?v=s1d8UGDCCN8
vector<int> verticalOrder(Node *root)
{
    map<int, map<int, vector<int>>> nodes;
    queue<pair<Node *, pair<int, int>>> q;
    vector<int> ans;

    if (!root)
        return ans;

    q.push(make_pair(root, make_pair(0, 0)));

    while (!q.empty())
    {
        pair<Node *, pair<int, int>> t = q.front();
        q.pop();

        Node *this_node = t.first;
        int hd = t.second.first;
        int level = t.second.second;

        nodes[hd][level].push_back(this_node->data);

        if (this_node->left)
            q.push(make_pair(this_node->left, make_pair(hd - 1, level + 1)));

        if (this_node->right)
            q.push(make_pair(this_node->right, make_pair(hd + 1, level + 1)));
    }

    for (auto &i : nodes)
    {
        for (auto &j : i.second)
        {
            for (auto &k : j.second)
            {
                ans.push_back(k);
            }
        }
    }
    return ans;
}