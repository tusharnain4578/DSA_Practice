#include <iostream>
#include <vector>
using namespace std;

// practice --> https://practice.geeksforgeeks.org/problems/knapsack-with-duplicate-items4201/1

// Please revise in this order
// Recursion -> Memoization -> Tabulation -> Space Optimization

//
// Memoized solution of 0 1 Knapsack
int mem(vector<int> &wt, vector<int> &val, int ind, int W, vector<vector<int>> &dp)
{

    if (ind == 0)
    {
        // insstead of taking one occurance, just take how much you can take
        return (W / wt[0]) * val[0];
    }

    if (dp[ind][W] != -1)
        return dp[ind][W];
    // in bounded knapsack, you have to stand on to the index, while taking it
    int taken = wt[ind] <= W ? val[ind] + mem(wt, val, ind, W - wt[ind], dp) : INT_MIN;

    int notTaken = 0 + mem(wt, val, ind - 1, W, dp);

    return dp[ind][W] = max(notTaken, taken);
}

int knapsack_mem(vector<int> &wt, vector<int> &val, int n, int W)
{

    vector<vector<int>> dp(n, vector<int>(W + 1, -1));
    return mem(wt, val, n - 1, W, dp);
}
