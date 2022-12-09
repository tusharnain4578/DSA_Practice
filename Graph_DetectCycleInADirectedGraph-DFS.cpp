#include <iostream>
#include <vector>
#include <queue>
using namespace std;

bool DFSCycleCheck(int &node, vector<int> adj[], vector<bool> &visited, vector<bool> &dfs_visited)
{
    // reference ---> https://www.youtube.com/watch?v=uzVUw90ZFIg

    visited[node] = true;
    dfs_visited[node] = true;

    for (int &it : adj[node])
    {
        if (!visited[it])
        {
            if (DFSCycleCheck(it, adj, visited, dfs_visited))
                return true;
        }
        else if (dfs_visited[it])
            return true;
    }
    dfs_visited[node] = false;

    return false;
}

bool isCyclic(int V, vector<int> adj[])
{
    vector<bool> visited(V, false), dfs_visited(V, false);

    for (int i = 0; i < V; i++)
        if (!visited[i])
            if (DFSCycleCheck(i, adj, visited, dfs_visited))
                return true;

    return false;
}

void addEdge(vector<int> adj[], int u, int v)
{
    adj[u].push_back(v);
    adj[v].push_back(u);
}

int main()
{

    int V = 6;

    vector<int> adj[V];
    addEdge(adj, 0, 1);
    addEdge(adj, 1, 2);
    addEdge(adj, 1, 5);
    addEdge(adj, 2, 3);
    addEdge(adj, 3, 4);
    addEdge(adj, 4, 0);
    addEdge(adj, 4, 1);

    if (isCyclic(V, adj))
        cout << "Cycle Detected"
             << "\n";
    else
        cout << "No Cycle Detected";

    return 0;
}