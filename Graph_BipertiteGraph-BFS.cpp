#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// Using BFS
bool bipartiteBFS(int node, vector<int> adj[], vector<short> &color)
{
    color[node] = 1;
    queue<int> q;
    q.push(node);

    while (!q.empty())
    {
        int this_node = q.front();
        q.pop();
        for (int &it : adj[this_node])
        {
            if (color[it] == -1)
            {
                color[it] = 1 - color[this_node];
                q.push(it);
            }
            else if (color[it] == color[this_node])
                return false;
        }
    }
    return true;
}

bool isBipartite(int V, vector<int> adj[])
{
    vector<short> color(V, -1);

    for (int i = 0; i < V; i++)
        if (color[i] == -1)
            if (!bipartiteBFS(i, adj, color))
                return false;

    return true;
}

int main()
{
    int n, m;
    cin >> n >> m;
    vector<int> adj[n];
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    if (isBipartite(n, adj))
    {
        cout << "yes";
    }
    else
    {
        cout << "No";
    }
    return 0;
}

/*
8 7
0 1
1 2
2 3
3 4
4 6
6 7
1 7
4 5

// bipartite graph example
*/

/*
7 7
0 1
1 2
2 3
3 4
4 6
6 1
4 5
// not bipartite example
*/
