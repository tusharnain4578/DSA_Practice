#include <iostream>
#include <vector>
using namespace std;

// practice --> https://practice.geeksforgeeks.org/problems/0-1-knapsack-problem0945/1/

// Please revise in this order
// Recursion -> Memoization -> Tabulation -> Space Optimization

//
//
// Approaches ->

// Recursive Approach ------------------------------------------
int rec(vector<int> &wt, vector<int> &val, int ind, int W)
{

    if (ind == 0)
    {
        if (wt[0] <= W)
            return val[0];
        else
            return 0;
    }

    int taken = wt[ind] <= W ? val[ind] + rec(wt, val, ind - 1, W - wt[ind]) : INT_MIN;

    int notTaken = 0 + rec(wt, val, ind - 1, W);

    return max(notTaken, taken);
}

int knapsack_rec(vector<int> &wt, vector<int> &val, int n, int W)
{
    return rec(wt, val, n - 1, W);
}

// Memoized Approach ------------------------------------------
int mem(vector<int> &wt, vector<int> &val, int ind, int W, vector<vector<int>> &dp)
{

    if (ind == 0)
    {
        if (wt[0] <= W)
            return val[0];
        else
            return 0;
    }

    if (dp[ind][W] != -1)
        return dp[ind][W];

    int taken = wt[ind] <= W ? val[ind] + mem(wt, val, ind - 1, W - wt[ind], dp) : INT_MIN;

    int notTaken = 0 + mem(wt, val, ind - 1, W, dp);

    return dp[ind][W] = max(notTaken, taken);
}

int knapsack_mem(vector<int> &wt, vector<int> &val, int n, int W)
{

    vector<vector<int>> dp(n, vector<int>(W + 1, -1));
    return mem(wt, val, n - 1, W, dp);
}

// Tabulated Approach ------------------------------------------

int knapsack_tabulated(vector<int> &wt, vector<int> &val, int n, int W)
{

    vector<vector<int>> dp(n, vector<int>(W + 1));

    for (int ind = 0; ind < n; ind++)
    {
        for (int cap = 0; cap <= W; cap++)
        {
            // Base Condition
            if (ind == 0)
            {
                if (wt[0] <= cap)
                    dp[ind][cap] = val[0];
                else
                    dp[ind][cap] = 0;
            }
            else
            {
                int taken = wt[ind] <= cap ? val[ind] + dp[ind - 1][cap - wt[ind]] : INT_MIN;

                int notTaken = 0 + dp[ind - 1][cap];

                dp[ind][cap] = max(notTaken, taken);
            }
        }
    }

    return dp[n - 1][W];
}

// Space Optimized Approach ------------------------------------------

int knapsack_SpaceOptimized(vector<int> &wt, vector<int> &val, int n, int W)
{

    vector<int> dp(W + 1);

    for (int ind = 0; ind < n; ind++)
    {
        vector<int> temp(W + 1);
        for (int cap = 0; cap <= W; cap++)
        {
            // Base Case
            if (ind == 0)
            {
                if (wt[0] <= cap)
                    temp[cap] = val[0];
                else
                    temp[cap] = 0;
            }
            else
            {
                int taken = wt[ind] <= cap ? val[ind] + dp[cap - wt[ind]] : INT_MIN;

                int notTaken = 0 + dp[cap];

                temp[cap] = max(notTaken, taken);
            }
        }
        dp = temp;
    }

    return dp[W];
}

// Single Array - Space Optimized Approach ------------------------------------------

int knapsack_SpaceOptimizedSingeArray(vector<int> &wt, vector<int> &val, int n, int W)
{

    vector<int> dp(W + 1);

    for (int ind = 0; ind < n; ind++)
    {
        for (int cap = W; cap >= 0; cap--)
        {
            // Base Condition
            if (ind == 0)
            {
                if (wt[0] <= cap)
                    dp[cap] = val[0];
                else
                    dp[cap] = 0;
            }
            else
            {
                int taken = wt[ind] <= cap ? val[ind] + dp[cap - wt[ind]] : INT_MIN;

                int notTaken = 0 + dp[cap];

                dp[cap] = max(notTaken, taken);
            }
        }
    }

    return dp[W];
}