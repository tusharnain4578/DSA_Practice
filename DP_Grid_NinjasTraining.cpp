#include <iostream>
#include <vector>
using namespace std;
// practice --> https://www.codingninjas.com/codestudio/problems/ninja-s-training_3621003

// Please revise in this order
// Recursion -> Memoization -> Tabulation -> Space Optimization

// .
// .
// Approaches ->
// Recursive Approach ------------------------------------------

int rec(int index, int prev, vector<vector<int>> &points)
{
    if (index == 0)
    {
        int max_el = INT_MIN;
        for (int i = 0; i < 3; i++)
        {
            if (i != prev)
                max_el = max(max_el, points[index][i]);
        }
        return max_el;
    }

    int max_ans = INT_MIN;
    for (int i = 0; i <= 2; i++)
    {
        if (i != prev)
        {
            int solve = points[index][i] + rec(index - 1, i, points);
            max_ans = max(max_ans, solve);
        }
    }

    return max_ans;
}

int ninjaTraining(int n, vector<vector<int>> &points)
{
    // Write your code here.
    return rec(n - 1, 3, points);
}

// Memoized Approach ------------------------------------------

int rec_Memoized(int index, int prev, vector<vector<int>> &points, vector<vector<int>> &dp)
{
    if (index == 0)
    {
        int max_el = INT_MIN;
        for (int i = 0; i < 3; i++)
        {
            if (i != prev)
                max_el = max(max_el, points[index][i]);
        }
        return max_el;
    }

    if (dp[index][prev] != -1)
        return dp[index][prev];

    int max_ans = INT_MIN;
    for (int i = 0; i <= 2; i++)
    {
        if (i != prev)
        {
            int solve = points[index][i] + rec_Memoized(index - 1, i, points, dp);
            max_ans = max(max_ans, solve);
        }
    }

    return dp[index][prev] = max_ans;
}

int ninjaTraining_Memoized(int n, vector<vector<int>> &points)
{
    // Write your code here.
    vector<vector<int>> dp(n, vector<int>(4, -1));
    return rec_Memoized(n - 1, 3, points, dp);
}

// Tabulated Approach ------------------------------------------

int ninjaTraining_Tabulated(int n, vector<vector<int>> &points)
{
    // Write your code here.
    vector<vector<int>> dp(n, vector<int>(4));

    dp[0][0] = max(points[0][1], points[0][2]);
    dp[0][1] = max(points[0][0], points[0][2]);
    dp[0][2] = max(points[0][0], points[0][1]);
    dp[0][3] = max(points[0][0], max(points[0][1], points[0][2]));

    for (int index = 1; index < n; index++)
    {
        for (int prev = 0; prev <= 3; prev++)
        {
            int maxi = 0;

            for (int task = 0; task <= 2; task++)
            {
                if (task != prev)
                {
                    int solve = points[index][task] + dp[index - 1][task];
                    maxi = max(maxi, solve);
                }
            }
            dp[index][prev] = maxi;
        }
    }
    return dp[n - 1][3];
}

// Space Optimized Approact -----------------------------------

int ninjaTraining_SpaceOptimized(int n, vector<vector<int>> &points)
{
    // Write your code here.
    vector<int> dp(4);

    dp[0] = max(points[0][1], points[0][2]);
    dp[1] = max(points[0][0], points[0][2]);
    dp[2] = max(points[0][0], points[0][1]);
    dp[3] = max(points[0][0], max(points[0][1], points[0][2]));

    for (int index = 1; index < n; index++)
    {
        vector<int> new_one(4);

        for (int prev = 0; prev <= 3; prev++)
        {
            int maxi = 0;

            for (int task = 0; task <= 2; task++)
            {
                if (task != prev)
                {
                    int solve = points[index][task] + dp[task];
                    maxi = max(maxi, solve);
                }
            }
            new_one[prev] = maxi;
        }
        dp = new_one;
    }
    return dp[3];
}