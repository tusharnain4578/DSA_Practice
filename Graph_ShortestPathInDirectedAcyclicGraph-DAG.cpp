#include <iostream>
#include <vector>
#include <queue>
#include <stack>
using namespace std;

void topoSort(int node, vector<pair<int, int>> adj[], vector<int> &vis, stack<int> &st)
{
    vis[node] = 1;

    for (auto &it : adj[node])
        if (!vis[it.first])
            topoSort(it.first, adj, vis, st);

    st.push(node);
}

vector<int> shortestPath(vector<pair<int, int>> adj[], int V, int source)
{
    vector<int> dist(V, INT_MAX);
    stack<int> st;
    vector<int> vis(V, 0);

    for (int i = 0; i < V; i++)
        if (!vis[i])
            topoSort(i, adj, vis, st);

    dist[source] = 0;

    while (!st.empty())
    {
        int this_node = st.top();
        st.pop();

        if (dist[this_node] != INT_MAX)
            for (auto &it : adj[this_node])
                if (dist[this_node] + it.second < dist[it.first])
                    dist[it.first] = dist[this_node] + it.second;
    }

    return dist;
}

void addEdge(vector<pair<int, int>> adj[], int u, int v, int wt)
{
    adj[u].push_back({v, wt});
}

int main()
{

    int V = 6;

    // Undirected Graph
    vector<pair<int, int>> adj[V];
    addEdge(adj, 0, 2, 2);
    addEdge(adj, 0, 5, 4);
    addEdge(adj, 2, 4, 1);
    addEdge(adj, 5, 3, 1);
    addEdge(adj, 4, 3, 3);
    addEdge(adj, 3, 1, 2);
    // addEdge(adj, 6, 5, );
    // addEdge(adj, 2, 4, );

    vector<int> ans = shortestPath(adj, V, 0);

    // cout << ans[0] << endl;
    // cout << ans.size();

    for (int i : ans)
        cout << i << " ";

    return 0;
}