#include <iostream>
#include <vector>
using namespace std;

void getDFS(int &node, vector<int> adj[], vector<int> &dfs, vector<bool> &visited)
{
    visited[node] = true;
    dfs.push_back(node);

    for (int &it : adj[node])
        if (!visited[it])
            getDFS(it, adj, dfs, visited);
}

vector<int> dfsOfGraph(int V, vector<int> adj[])
{
    vector<int> dfs;
    vector<bool> visited(V, false);

    for (int i = 0; i < V; i++)
        if (!visited[i])
            getDFS(i, adj, dfs, visited);

    return dfs;
}

void addEdge(vector<int> adj[], int u, int v)
{
    adj[u].push_back(v);
    adj[v].push_back(u);
}

int main()
{
    vector<int> adj[6];

    addEdge(adj, 0, 2);
    addEdge(adj, 0, 3);
    addEdge(adj, 0, 4);
    addEdge(adj, 1, 5);
    addEdge(adj, 2, 4);

    vector<int> bfs = dfsOfGraph(6, adj);

    for (int i : bfs)
        cout << i << " ";

    return 0;
}