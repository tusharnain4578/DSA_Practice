#include <iostream>
#include <vector>
using namespace std;
// practice ---> https://practice.geeksforgeeks.org/problems/minimum-cost-to-fill-given-weight-in-a-bag1956/1

// recrusion
int rec(int cost[], int index, int W)
{
    if (W == 0)
        return 0;

    if (index < 0)
        return 1e9;

    int pick = 1e9;
    if (index + 1 <= W and cost[index] != -1)
        pick = cost[index] + rec(cost, index, W - (index + 1));

    int non_pick = 0 + rec(cost, index - 1, W);

    return min(pick, non_pick);
}

int minimumCost_rec(int cost[], int N, int W)
{
    return rec(cost, N - 1, W);
}

// memoization
int mem(int cost[], int index, int W, vector<vector<int>> &dp)
{
    if (W == 0)
        return 0;

    if (index < 0)
        return 1e9;

    if (dp[index][W] != -1)
        return dp[index][W];

    int pick = 1e9;
    if (index + 1 <= W and cost[index] != -1)
        pick = cost[index] + mem(cost, index, W - (index + 1), dp);

    int non_pick = 0 + mem(cost, index - 1, W, dp);

    return dp[index][W] = min(pick, non_pick);
}

int minimumCost_mem(int cost[], int N, int W)
{
    vector<vector<int>> dp(N, vector<int>(W + 1, -1)); // 2d DP
    return mem(cost, N - 1, W, dp);
}

// tabulation
int minimumCost_tab(int cost[], int N, int W)
{
    vector<vector<int>> dp(N + 1, vector<int>(W + 1)); // 2d DP

    // base case
    for (int i = 0; i <= W; i++)
        dp[0][i] = 1e9;
    for (int i = 0; i <= N; i++)
        dp[i][0] = 0;

    for (int index = 1; index <= N; index++)
    {
        for (int wt = 1; wt <= W; wt++)
        {
            int pick = 1e9;
            if (index <= wt and cost[index - 1] != -1)
                pick = cost[index - 1] + dp[index][wt - (index)];

            int non_pick = 0 + dp[index - 1][wt];

            dp[index][wt] = min(pick, non_pick);
        }
    }

    return dp[N][W];
}

// Space Optimized
int minimumCost(int cost[], int N, int W)
{
    vector<int> dp(W + 1);

    // base case
    for (int i = 0; i <= W; i++)
        dp[i] = 1e9;
    dp[0] = 0;

    for (int index = 1; index <= N; index++)
    {
        vector<int> temp(W + 1);
        temp[0] = 0;

        for (int wt = 1; wt <= W; wt++)
        {
            int pick = 1e9;
            if (index <= wt and cost[index - 1] != -1)
                pick = cost[index - 1] + temp[wt - (index)];

            int non_pick = 0 + dp[wt];

            temp[wt] = min(pick, non_pick);
        }

        dp = temp;
    }

    return dp[W];
}