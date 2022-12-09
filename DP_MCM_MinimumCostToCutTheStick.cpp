#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// practice --> https://leetcode.com/problems/minimum-cost-to-cut-a-stick/

// Please revise in this order
// Recursion -> Memoization -> Tabulation -> Space Optimization

//
//
// Approaches ->

// Recursive Approach ------------------------------------------

int rec(int i, int j, vector<int> &cuts)
{
    if (i > j)
        return 0;

    int min_cost = INT_MAX;

    for (int k = i; k <= j; k++)
    {
        int cost = cuts[j + 1] - cuts[i - 1] + rec(i, k - 1, cuts) + rec(k + 1, j, cuts);

        min_cost = min(min_cost, cost);
    }

    return min_cost;
}

int minCost(int n, vector<int> &cuts)
{
    int c = cuts.size();
    cuts.insert(cuts.begin(), 0);
    cuts.push_back(n);
    sort(cuts.begin(), cuts.end());

    return rec(1, c, cuts);
}

// Memoized Approach ------------------------------------------
int mem(int i, int j, vector<int> &cuts, vector<vector<int>> &dp)
{
    if (i > j)
        return 0;

    if (dp[i][j] != -1)
        return dp[i][j];

    int min_cost = INT_MAX;

    for (int k = i; k <= j; k++)
    {
        int cost = cuts[j + 1] - cuts[i - 1] + mem(i, k - 1, cuts, dp) + mem(k + 1, j, cuts, dp);

        min_cost = min(min_cost, cost);
    }

    return dp[i][j] = min_cost;
}

int minCost(int n, vector<int> &cuts)
{
    int c = cuts.size();
    cuts.insert(cuts.begin(), 0);
    cuts.push_back(n);
    sort(cuts.begin(), cuts.end());

    vector<vector<int>> dp(c + 1, vector<int>(c + 1, -1));

    return mem(1, c, cuts, dp);
}

// Tabulation Approach ------------------------------------------

int minCost(int n, vector<int> &cuts)
{
    int c = cuts.size();
    cuts.insert(cuts.begin(), 0);
    cuts.push_back(n);
    sort(cuts.begin(), cuts.end());

    vector<vector<int>> dp(c + 2, vector<int>(c + 2, 0));

    for (int i = c; i >= 1; i--)
    {
        for (int j = 1; j <= c; j++)
        {
            if (i > j)
                continue;

            int min_cost = INT_MAX;

            for (int k = i; k <= j; k++)
            {
                int cost = cuts[j + 1] - cuts[i - 1] + dp[i][k - 1] + dp[k + 1][j];

                min_cost = min(min_cost, cost);
            }

            dp[i][j] = min_cost;
        }
    }

    return dp[1][c];
}