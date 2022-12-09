#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// Using BFS
// Kahn's Algorithm

vector<int> topoSort(int V, vector<int> adj[])
{
    // No need of visited vector
    vector<int> indegree(V, 0);
    vector<int> ans;

    queue<int> q;

    for (int i = 0; i < V; i++) // getting indegrees
        for (int &it : adj[i])
            indegree[it]++;

    // pushing elements in queue with indegree 0
    for (int i = 0; i < V; i++)
        if (indegree[i] == 0)
            q.push(i);

    while (!q.empty())
    {
        int this_node = q.front();
        q.pop();
        ans.push_back(this_node);

        for (int &it : adj[this_node])
        {
            indegree[it]--;

            if (indegree[it] == 0)
                q.push(it);
        }
    }

    return ans;
}

int main()
{

    vector<int> adj[6];
    adj[5].push_back(2);
    adj[5].push_back(0);
    adj[4].push_back(0);
    adj[4].push_back(1);
    adj[3].push_back(1);
    adj[2].push_back(3);

    vector<int> v = topoSort(6, adj);
    for (auto it : v)
        cout << it << " ";

    return 0;
}