#include <iostream>
#include <vector>
#include <queue>
using namespace std;
// practice --> https://leetcode.com/problems/find-if-path-exists-in-graph/

void bfs(int node, vector<int> adj[], vector<bool> &vis)
{
    vis[node] = true;

    queue<int> q;
    q.push(node);

    while (!q.empty())
    {
        int this_node = q.front();
        q.pop();

        for (auto &it : adj[this_node])
        {
            if (!vis[it])
            {
                q.push(it);
                vis[it] = true;
            }
        }
    }
}

bool validPath(int n, vector<vector<int>> &edges, int source, int destination)
{
    vector<int> adj[n];

    for (auto x : edges)
    {
        int u = x[0];
        int v = x[1];

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<bool> vis(n, false);

    bfs(source, adj, vis);

    return vis[destination];
}