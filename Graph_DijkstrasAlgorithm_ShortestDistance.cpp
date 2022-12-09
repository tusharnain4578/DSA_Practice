#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// Dijkstra’s Algorithm
// Applies on all graphs, directed, undirected
vector<int> shortestPath(vector<pair<int, int>> adj[], int V, int source)
{
    vector<int> dist(V, INT_MAX);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq; // the only motive of priority queue here is to get pop the value on the basis of minimum distance, nothing else

    pq.push(make_pair(0, source));
    dist[source] = 0;

    while (!pq.empty())
    {
        int this_value = pq.top().second;
        int this_dist = pq.top().first;
        pq.pop();

        for (auto &it : adj[this_value])
        {
            if (this_dist + it.second < dist[it.first])
            {
                dist[it.first] = this_dist + it.second;
                pq.push(make_pair(dist[it.first], it.first));
            }
        }
    }

    return dist;
}

int main()
{
    int V = 5, source = 0;
    vector<pair<int, int>> g[V];
    g[0].push_back({1, 2});
    g[0].push_back({3, 1});
    g[1].push_back({0, 2});
    g[1].push_back({4, 5});
    g[1].push_back({2, 4});
    g[2].push_back({1, 4});
    g[2].push_back({3, 3});
    g[2].push_back({4, 1});
    g[3].push_back({0, 1});
    g[3].push_back({2, 3});
    g[4].push_back({1, 5});
    g[4].push_back({2, 1});

    vector<int> ans = shortestPath(g, V, source);

    for (int i : ans)
        cout << i << " ";

    return 0;
}