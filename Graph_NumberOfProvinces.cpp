#include <iostream>
#include <vector>
using namespace std;
// practice --> https://leetcode.com/problems/number-of-provinces/

void dfs(int s, vector<vector<int>> &isConnected, vector<bool> &vis)
{
    vis[s] = true;
    vector<int> adj;

    for (int i = 0; i < isConnected.size(); i++)
        if (isConnected[s][i] == 1)
            adj.push_back(i);

    for (auto &it : adj)
        if (!vis[it])
            dfs(it, isConnected, vis);
}

int findCircleNum(vector<vector<int>> &isConnected)
{
    int n = isConnected.size();
    vector<bool> vis(n, false);

    int ans = 0;

    for (int i = 0; i < n; i++)
        if (!vis[i])
            dfs(i, isConnected, vis), ans++;

    return ans;
}