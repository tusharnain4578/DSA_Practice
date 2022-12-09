#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// Undirected non weighted graph
vector<int> ShortestPath(vector<int> adj[], int V, int source)
{
    vector<int> dist(V, INT_MAX);
    dist[source] = 0;

    queue<int> q;
    q.push(source);

    while (!q.empty())
    {
        int this_node = q.front();
        q.pop();

        for (int &it : adj[this_node])
        {
            if (dist[this_node] + 1 < dist[it])
            {
                dist[it] = dist[this_node] + 1;
                q.push(it);
            }
        }
    }

    return dist;
}

void addEdge(vector<int> adj[], int u, int v)
{
    adj[u].push_back(v);
    adj[v].push_back(u);
}

int main()
{

    int V = 8;

    // Undirected Graph
    vector<int> adj[V];
    addEdge(adj, 0, 5);
    addEdge(adj, 0, 3);
    addEdge(adj, 3, 1);
    addEdge(adj, 1, 6);
    addEdge(adj, 6, 7);
    addEdge(adj, 6, 2);
    addEdge(adj, 6, 5);
    addEdge(adj, 2, 4);

    vector<int> ans = ShortestPath(adj, V, 0);

    // cout << ans[0] << endl;
    // cout << ans.size();

    for (int i : ans)
        cout << i << " ";

    return 0;
}