#include <iostream>
#include <vector>
using namespace std;

void dfs(int node, int parent, vector<int> adj[], vector<bool> &visited, vector<int> &time_of_insertion, vector<int> &lowest_time, int &timer, vector<pair<int, int>> &bridges)
{
    visited[node] = true;
    time_of_insertion[node] = lowest_time[node] = timer++;

    for (int &it : adj[node])
    {

        if (it == parent)
            continue;

        if (!visited[it])
        {
            dfs(it, node, adj, visited, time_of_insertion, lowest_time, timer, bridges);

            lowest_time[node] = min(lowest_time[node], lowest_time[it]);

            if (lowest_time[it] > time_of_insertion[node])
                bridges.push_back(make_pair(node, it));
        }
        else
            lowest_time[node] = min(lowest_time[node], time_of_insertion[it]);
    }
}

vector<pair<int, int>> bridgesInGraph(vector<int> adj[], int V)
{
    vector<bool> visited(V, false);
    vector<int> time_of_insertion(V, -1);
    vector<int> lowest_time(V, -1);
    int timer = 0;

    vector<pair<int, int>> bridges; // ans

    for (int i = 0; i < V; i++)
        if (!visited[i])
            dfs(i, -1, adj, visited, time_of_insertion, lowest_time, timer, bridges);

    return bridges;
}

void addEdge(vector<int> adj[], int u, int v)
{
    adj[u].push_back(v);
    adj[v].push_back(u);
}

int main()
{
    int V = 12;
    vector<int> adj[V];

    addEdge(adj, 0, 1);
    addEdge(adj, 0, 3);
    addEdge(adj, 1, 2);
    addEdge(adj, 2, 3);
    addEdge(adj, 3, 4);
    addEdge(adj, 4, 5);
    addEdge(adj, 5, 6);
    addEdge(adj, 5, 8);
    addEdge(adj, 7, 6);
    addEdge(adj, 7, 8);
    addEdge(adj, 7, 9);
    addEdge(adj, 9, 10);
    addEdge(adj, 9, 11);
    addEdge(adj, 10, 11);

    vector<pair<int, int>> bridges = bridgesInGraph(adj, V);

    for (pair<int, int> &i : bridges)
        cout << i.first << " - " << i.second << endl;

    return 0;
}