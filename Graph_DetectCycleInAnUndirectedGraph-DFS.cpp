#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// Using DFS
bool checkForCycle(int &node, int pre, vector<int> adj[], vector<bool> &visited)
{
    visited[node] = true;

    for (int &it : adj[node])
    {
        if (!visited[it])
        {
            if (checkForCycle(it, node, adj, visited))
                return true;
        }
        else if (it != pre)
            return true;
    }
    return false;
}

bool isCycle(int V, vector<int> adj[])
{
    vector<bool> visited(V, false);

    for (int i = 0; i < V; i++)
        if (!visited[i])
            if (checkForCycle(i, -1, adj, visited))
                return true;

    return false;
}

int main()
{

    int V = 5;
    int E = 5;
    vector<int> adj[V];

    adj[0].push_back(1);
    adj[1].push_back(0);

    adj[1].push_back(2);
    adj[2].push_back(1);

    adj[1].push_back(4);
    adj[4].push_back(1);

    adj[4].push_back(3);
    adj[3].push_back(4);

    adj[2].push_back(3);
    adj[3].push_back(2);

    bool ans = isCycle(V, adj);
    if (ans)
    {
        cout << "Cycle Detected";
    }
    else
        cout << "No Cycle Detected";

    return 0;
}