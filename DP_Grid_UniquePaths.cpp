#include <iostream>
#include <vector>
using namespace std;
// Most Optimal Approach is in Array_GridUniquePathsOptimal.cpp

// practice --> https://leetcode.com/problems/unique-paths/

// Please revise in this order
// Recursion -> Memoization -> Tabulation -> Space Optimization

// can also be done in 0 based indexing, but in this entire code file, i did it in 0 based indexing

//
//
// Approaches ->
// Recursive Approach ------------------------------------------
int uniquePaths_Rec(int m, int n) // m and n represents grid size
{
    if (m == 1 and n == 1)
        return 1;

    if (m < 1 or n < 1)
        return 0;

    return uniquePaths_Rec(m - 1, n) + uniquePaths_Rec(m, n - 1);
}

// Recursive Approach ------------------------------------------
int memoization(int m, int n, vector<vector<int>> &dp)
{
    if (m == 1 and n == 1)
        return 1;

    if (m < 1 or n < 1)
        return 0;

    if (dp[m][n] != -1)
        return dp[m][n];

    return dp[m][n] = memoization(m - 1, n, dp) + memoization(m, n - 1, dp);
}

int uniquePaths_Memoized(int m, int n) // m and n represents grid size
{
    vector<vector<int>> dp(m + 1, vector<int>(n + 1, -1));

    return memoization(m, n, dp);
}

// Tabulated Approach ------------------------------------------
int uniquePaths_Tabulated(int m, int n) // m and n represents grid size
{
    vector<vector<int>> dp(m + 1, vector<int>(n + 1));

    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= n; j++)
        {

            if (i == 1 and j == 1)
            {
                dp[i][j] = 1;
            }
            else
            {
                int up = 0, left = 0;

                if (i > 1)
                    up = dp[i - 1][j];

                if (j > 1)
                    left = dp[i][j - 1];

                dp[i][j] = up + left;
            }
        }
    }

    return dp[m][n];
}

// Space Optimized Approach ------------------------------------------
int uniquePaths_SpaceOptimized(int m, int n) // m and n represents grid size
{
    vector<int> dp(n + 1, 0);

    for (int i = 1; i <= m; i++)
    {
        vector<int> temp(n + 1);
        for (int j = 1; j <= n; j++)
        {

            if (i == 1 and j == 1)
            {
                temp[j] = 1;
            }
            else
            {
                int up = 0, left = 0;

                if (i > 1)
                    up = dp[j];

                if (j > 1)
                    left = temp[j - 1];

                temp[j] = up + left;
            }
        }
        dp = temp;
    }

    return dp[n];
}