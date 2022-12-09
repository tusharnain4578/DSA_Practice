// Kosaraju's Algorithm for Strongly connected components
#include <iostream>
#include <vector>
#include <stack>
using namespace std;

void dfsForToposort(int node, vector<int> adj[], vector<bool> &visited, stack<int> &st)
{
    visited[node] = true;

    for (int &it : adj[node])
        if (!visited[it])
            dfsForToposort(it, adj, visited, st);

    st.push(node);
}

void dfs(int node, vector<int> transpose[], vector<bool> &visited, vector<int> &scc)
{
    scc.push_back(node);
    visited[node] = true;

    for (int &it : transpose[node])
        if (!visited[it])
            dfs(it, transpose, visited, scc);
}

vector<vector<int>> kosaraju(vector<int> adj[], int V)
{
    vector<vector<int>> scc;

    vector<bool> visited(V, false);
    stack<int> toposort;

    for (int i = 0; i < V; i++)
        if (!visited[i])
            dfsForToposort(i, adj, visited, toposort);

    vector<int> transpose[V];

    for (int i = 0; i < V; i++)
    {
        visited[i] = false; // also resetting visited array
        for (int &it : adj[i])
            transpose[it].push_back(i);
    }

    while (!toposort.empty())
    {
        int node = toposort.top();
        toposort.pop();

        if (!visited[node])
        {
            vector<int> _scc;
            dfs(node, transpose, visited, _scc);
            if (!_scc.empty())
                scc.push_back(_scc);
        }
    }

    return scc;
}

int main()
{
    int V = 6;
    vector<int> adj[V];
    adj[0].push_back(2);
    adj[1].push_back(0);
    adj[2].push_back(1);
    adj[2].push_back(4);
    adj[3].push_back(5);
    adj[4].push_back(3);
    adj[5].push_back(4);

    vector<vector<int>> scc = kosaraju(adj, V);

    for (vector<int> &i : scc)
    {
        for (int &j : i)
            cout << j << " ";
        cout << endl;
    }
    return 0;
}