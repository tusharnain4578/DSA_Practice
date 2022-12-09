#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// Using BFS
bool checkForCycle(int node, vector<int> adj[], vector<bool> &visited)
{
    queue<pair<int, int>> q;
    visited[node] = true;
    q.push({node, -1});

    while (!q.empty())
    {
        int this_node = q.front().first;
        int pre = q.front().second;

        q.pop();

        for (int &it : adj[this_node])
        {
            if (!visited[it])
            {
                visited[it] = true;
                q.push({it, this_node});
            }
            else if (it != pre)
                return true;
        }
    }
    return false;
}

bool isCycle(int V, vector<int> adj[])
{
    vector<bool> visited(V, false);

    for (int i = 0; i < V; i++)
        if (!visited[i])
            if (checkForCycle(i, adj, visited))
                return true;

    return false;
}