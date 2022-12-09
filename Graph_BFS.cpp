#include <iostream>
#include <vector>
#include <queue>
using namespace std;

void getBFS(int node, vector<int> adj[], vector<bool> &visited, vector<int> &bfs)
{
    visited[node] = true;

    queue<int> q;
    q.push(node);

    while (!q.empty())
    {
        int this_node = q.front();
        q.pop();

        bfs.push_back(this_node); // Collecting the resultant bfs

        for (int &it : adj[this_node])
        {
            if (!visited[it])
            {
                q.push(it);
                visited[it] = true;
            }
        }
    }
}

vector<int> bfsOfGraph(int V, vector<int> adj[])
{
    // reference ---> https://www.youtube.com/watch?v=UeE67iCK2lQ

    // This code is also handling disconnected nodes

    vector<int> bfs;                // for resultant bfs
    vector<bool> visited(V, false); // visited array for marking the visited nodes to prevent visiting them again

    for (int i = 0; i < V; i++) // Loop is used to include disconnected nodes. For only connected nodes, just remove the loop and for the first time, push 0 in the que instead of i
        if (!visited[i])
            getBFS(i, adj, visited, bfs);

    return bfs;
}

void addEdge(vector<int> adj[], int u, int v)
{
    adj[u].push_back(v);
    adj[v].push_back(u);
}

int main()
{
    vector<int> adj[6];

    addEdge(adj, 0, 1);
    addEdge(adj, 0, 5);
    addEdge(adj, 0, 2);
    addEdge(adj, 0, 3);
    addEdge(adj, 2, 4);

    vector<int> bfs = bfsOfGraph(6, adj);

    for (int i : bfs)
        cout << i << " ";

    return 0;
}