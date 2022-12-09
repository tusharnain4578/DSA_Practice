#include <iostream>
#include <queue>
#include <vector>
using namespace std;
// Spanning Tree should not have a cycle

void MST(vector<pair<int, int>> adj[], int V)
{
    vector<int> key(V, INT_MAX);
    vector<int> parent(V, -1);
    vector<bool> mst(V, false);

    // purpose of p_queue is to pop elements as per the minimum path size
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    key[0] = 0;
    pq.push(make_pair(0, 0)); // order-> (dist, node)

    for (int i = 0; i < V - 1; i++)
    {
        int node_data = pq.top().second;
        pq.pop();

        mst[node_data] = true;

        for (auto &it : adj[node_data])
        {
            int it_value = it.first;
            int it_weight = it.second;

            if (mst[it_value] == false && it_weight < key[it_value])
            {
                key[it_value] = it_weight;
                parent[it_value] = node_data;
                pq.push(make_pair(key[it_value], it.first));
            }
        }
    }

    // The will no parent node for 0th node, so we're starting loop with 1
    for (int i = 1; i < V; i++)
        cout << parent[i] << " -> " << i << endl;
}

int main()
{
    int V = 5;
    vector<pair<int, int>> adj[V];
    adj[0].push_back({3, 3});
    adj[0].push_back({4, 7});
    adj[1].push_back({2, 1});
    adj[1].push_back({3, 4});
    adj[1].push_back({0, 8});
    adj[2].push_back({1, 1});
    adj[2].push_back({3, 2});
    adj[3].push_back({2, 2});
    adj[3].push_back({1, 4});
    adj[3].push_back({0, 3});
    adj[4].push_back({0, 7});
    adj[4].push_back({3, 3});

    MST(adj, V);

    return 0;
}