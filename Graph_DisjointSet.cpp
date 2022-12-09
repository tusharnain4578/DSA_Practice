#include <iostream>
#include <vector>
using namespace std;

int findParent(vector<int> &parent, vector<int> &rank, int x)
{
    if (parent[x] == x)
        return x;

    return parent[x] = findParent(parent, rank, parent[x]);
}

void unionSet(vector<int> &parent, vector<int> &rank, int u, int v)
{
    u = findParent(parent, rank, u);
    v = findParent(parent, rank, v);

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