#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct node
{
    int u, v, wt;
    node(int u, int v, int wt) : u(u), v(v), wt(wt) {}
};

int findParent(int u, vector<int> &parent)
{
    if (parent[u] == u)
        return u;

    return parent[u] = findParent(parent[u], parent); // dp
}

void unionSet(int u, int v, vector<int> &parent, vector<int> &rank)
{
    u = findParent(u, parent);
    v = findParent(v, parent);

    if (rank[u] < rank[v])
        parent[u] = v;
    else if (rank[v] < rank[u])
        parent[v] = u;
    else
    {
        parent[u] = v;
        rank[v]++;
    }
}

bool edgesComparator(node a, node b)
{
    return a.wt < b.wt;
}

// Kruskal's Algorithm of calculating Spanning Tree
vector<pair<int, int>> KruskalsMSP(vector<node> &edges, int V)
{
    vector<int> parent(V);
    vector<int> rank(V, 0);

    sort(edges.begin(), edges.end(), edgesComparator); // sort acc to size, small to great

    for (int i = 0; i < V; i++)
        parent[i] = i;

    vector<pair<int, int>> mst; // resultant vector
    int cost = 0;               // will store the total distance counted in msp

    for (node &it : edges)
    {
        if (findParent(it.v, parent) != findParent(it.u, parent))
        {
            cost += it.wt;
            mst.push_back(make_pair(it.u, it.v));
            unionSet(it.u, it.v, parent, rank);
        }
    }
    cout << cost << endl;

    return mst;
}

int main()
{
    int V = 5;
    vector<node> edges;
    edges.push_back(node(0, 1, 2));
    edges.push_back(node(0, 3, 6));
    edges.push_back(node(1, 0, 2));
    edges.push_back(node(1, 2, 3));
    edges.push_back(node(1, 3, 8));
    edges.push_back(node(1, 4, 5));
    edges.push_back(node(2, 1, 3));
    edges.push_back(node(2, 4, 7));
    edges.push_back(node(3, 0, 6));
    edges.push_back(node(3, 1, 8));
    edges.push_back(node(4, 1, 5));
    edges.push_back(node(4, 2, 7));

    vector<pair<int, int>> msp = KruskalsMSP(edges, V);

    for (pair<int, int> &i : msp)
        cout << i.first << " - " << i.second << endl;

    return 0;
}