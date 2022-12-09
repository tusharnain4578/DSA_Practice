#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// Using BFS
// We can detect cycle using Kahn's Algorithm of Topological sort

// The intuition is that, by using Kahn's algo of topological sort, the number of all the elements present in the toposort will be as same as number of all the elements of the graph if there is no cycle.

// If there is a cycle, then the topological sort have lesser elements, that's all.

bool isCyclic(int V, vector<int> adj[])
{
    // reference ---> https://www.youtube.com/watch?v=V6GxfKDyLBM

    // No need of visited vector
    vector<int> indegree(V, 0);
    // vector<int> ans;  No need to store topological sort, we just need the length.
    int count = 0; // We will use count for this purpose.

    queue<int> q;

    for (int i = 0; i < V; i++) // getting indegrees
        for (int &it : adj[i])
            indegree[it]++;

    // pushing elements in queue with indegree 0.
    for (int i = 0; i < V; i++)
        if (indegree[i] == 0)
            q.push(i);

    while (!q.empty())
    {
        int this_node = q.front();
        q.pop();
        // ans.push_back(this_node); No need to store, we just want length, so we just need to increment the count.
        count++;

        for (int &it : adj[this_node])
        {
            indegree[it]--;

            if (indegree[it] == 0)
                q.push(it);
        }
    }
    if (count == V) // If toposort size = Graph size, then there is no cycle.
        return false;

    return true; // otherwise it's true.
}

void addEdge(vector<int> adj[], int u, int v)
{
    adj[u].push_back(v);
    adj[v].push_back(u);
}

int main()
{

    int V = 6;

    vector<int> adj[V];
    addEdge(adj, 0, 1);
    addEdge(adj, 1, 2);
    addEdge(adj, 1, 5);
    addEdge(adj, 2, 3);
    addEdge(adj, 3, 4);
    addEdge(adj, 4, 0);
    addEdge(adj, 4, 1);

    if (isCyclic(V, adj))
        cout << "Cycle Detected"
             << "\n";
    else
        cout << "No Cycle Detected";

    return 0;
}