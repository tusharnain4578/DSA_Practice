#include <iostream>
#include <vector>
using namespace std;

void dfs(int node, int parent, vector<int> adj[], vector<bool> &visited, vector<int> &time_of_insertion, vector<int> &lowest_time, int &timer, vector<bool> &is_articulation)
{
    visited[node] = true;
    time_of_insertion[node] = lowest_time[node] = timer++;
    int child{0};
    for (int &it : adj[node])
    {
        if (it == parent)
            continue;

        if (!visited[it])
        {
            dfs(it, node, adj, visited, time_of_insertion, lowest_time, timer, is_articulation);

            lowest_time[node] = min(lowest_time[node], lowest_time[it]);

            child++;

            if (lowest_time[it] >= time_of_insertion[node] && parent != -1)
                is_articulation[node] = true;
        }
        else
            lowest_time[node] = min(lowest_time[node], time_of_insertion[it]);
    }

    if (parent == -1 && child > 1)
        is_articulation[node] = true;
}

vector<bool> articulationPoint(vector<int> adj[], int V)
{
    vector<bool> visited(V, false);
    vector<int> time_of_insertion(V, -1);
    vector<int> lowest_time(V, -1);
    vector<bool> is_articulation(V, false);
    int timer = 0;

    for (int i = 0; i < V; i++)
        if (!visited[i])
            dfs(i, -1, adj, visited, time_of_insertion, lowest_time, timer, is_articulation);

    return is_articulation;
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

    vector<bool> is_articulation = articulationPoint(adj, V);

    for (int i = 0; i < V; i++)
        if (is_articulation[i])
            cout << i << " ";

    return 0;
}