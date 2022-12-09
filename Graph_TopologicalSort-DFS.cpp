#include <iostream>
#include <vector>
#include <stack>
using namespace std;

// This is just a typical bfs function, just after every end of recursion, put that value in a stack. The stack will contain the topological sort of the graph

// 1. The Topological sort is only applicable in Directed Acyclic Graph (DAG).

// 2. The Topological sort might not be unique in every graph. There can be more than 1 topological sort for a DAG Graph

void dfs(int &node, vector<int> adj[], vector<bool> &visited, stack<int> &s)
{
    visited[node] = true;

    for (int &it : adj[node])
    {
        if (!visited[it])
            dfs(it, adj, visited, s);
    }
    s.push(node);
}

vector<int> topoSort(int V, vector<int> adj[])
{
    vector<int> ans;
    vector<bool> visited(V, false);
    stack<int> s;

    for (int i = 0; i < V; i++)
        if (!visited[i])
            dfs(i, adj, visited, s);

    while (!s.empty())
        ans.push_back(s.top()), s.pop();

    return ans;
}

int main()
{

    int N = 6;

    vector<int> adj[5 + 1];

    adj[5].push_back(2);
    adj[5].push_back(0);
    adj[4].push_back(0);
    adj[4].push_back(1);
    adj[2].push_back(3);
    adj[3].push_back(1);

    vector<int> res = topoSort(6, adj);

    cout << "Toposort of the given graph is:" << endl;
    for (int i = 0; i < res.size(); i++)
    {
        cout << res[i] << " ";
    }

    return 0;
}