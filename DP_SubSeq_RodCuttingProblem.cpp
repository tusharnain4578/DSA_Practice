#include <iostream>
#include <vector>
using namespace std;

// practice --> https://www.codingninjas.com/codestudio/problems/rod-cutting-problem_800284

// Please revise in this order
// Recursion -> Memoization -> Tabulation -> Space Optimization

// Similar to Bounded Knapsack
//
//  Approaches ->

// Recursive Approach ------------------------------------------

int rec(vector<int> &price, int index, int N)
{
    if (index == 0)
    {
        return N * price[index];
    }

    int rod_length = index + 1;

    int pick = rod_length <= N ? price[index] + rec(price, index, N - rod_length) : INT_MIN;
    int non_pick = 0 + rec(price, index - 1, N);

    return max(pick, non_pick);
}

int cutRod(vector<int> &price, int n)
{
    return rec(price, n - 1, n);
}

// Memoized Approach ------------------------------------------

int mem(vector<int> &price, int index, int N, vector<vector<int>> &dp)
{
    if (index == 0)
    {
        return N * price[index];
    }

    if (dp[index][N] != -1)
        return dp[index][N];

    int rod_length = index + 1;

    int pick = rod_length <= N ? price[index] + mem(price, index, N - rod_length, dp) : INT_MIN;
    int non_pick = 0 + mem(price, index - 1, N, dp);

    return dp[index][N] = max(pick, non_pick);
}

int cutRod(vector<int> &price, int n)
{
    vector<vector<int>> dp(n, vector<int>(n + 1, -1));
    return mem(price, n - 1, n, dp);
}

// Tabulative Approach ------------------------------------------

int cutRod(vector<int> &price, int n)
{
    vector<vector<int>> dp(n, vector<int>(n + 1));

    for (int index = 0; index < n; index++)
    {
        for (int length = 0; length <= n; length++)
        {
            if (index == 0)
            {
                dp[index][length] = length * price[0]; // or length * price[index] - they're same
            }
            else
            {
                int rod_length = index + 1;

                int pick = rod_length <= length ? price[index] + dp[index][length - rod_length] : INT_MIN;
                int non_pick = 0 + dp[index - 1][length];

                dp[index][length] = max(pick, non_pick);
            }
        }
    }
    return dp[n - 1][n];
}

// Space Optimized Approach ------------------------------------------

int cutRod(vector<int> &price, int n)
{
    vector<int> dp(n + 1);

    for (int index = 0; index < n; index++)
    {
        vector<int> temp(n + 1);

        for (int length = 0; length <= n; length++)
        {
            if (index == 0)
            {
                temp[length] = length * price[0]; // or length * price[index] - they're same
            }
            else
            {
                int rod_length = index + 1;

                int pick = rod_length <= length ? price[index] + temp[length - rod_length] : INT_MIN;
                int non_pick = 0 + dp[length];

                temp[length] = max(pick, non_pick);
            }
        }
        dp = temp;
    }
    return dp[n];
}

// Single Array - Space Optimized Approach ------------------------------------------

// Just don't use the temp array, just think a little bit, how we are searching and then you can only do it using single arrya