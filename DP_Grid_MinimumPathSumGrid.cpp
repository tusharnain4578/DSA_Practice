#include <iostream>
#include <vector>
using namespace std;
// practice --> https://leetcode.com/problems/minimum-path-sum/

// Please revise in this order
// Recursion -> Memoization -> Tabulation -> Space Optimization

//
//
// Approaches ->

// Recursive Approach ------------------------------------------

int rec(vector<vector<int>> &grid, int m, int n)
{
    if (m == 0 and n == 0)
        return grid[0][0];

    int up = INT_MAX, left = INT_MAX;

    if (m - 1 >= 0)
        up = grid[m][n] + rec(grid, m - 1, n);

    if (n - 1 >= 0)
        left = grid[m][n] + rec(grid, m, n - 1);

    return min(up, left);
}

int minPathSum_rec(vector<vector<int>> &grid)
{
    int m = grid.size(), n = grid[0].size();

    return rec(grid, m - 1, n - 1);
}

// Memoized Approach ------------------------------------------

int mem(vector<vector<int>> &grid, int m, int n, vector<vector<int>> &dp)
{
    if (m == 0 and n == 0)
        return grid[0][0];

    if (dp[m][n] != -1)
        return dp[m][n];

    int up = INT_MAX, left = INT_MAX;

    if (m - 1 >= 0)
        up = grid[m][n] + mem(grid, m - 1, n, dp);

    if (n - 1 >= 0)
        left = grid[m][n] + mem(grid, m, n - 1, dp);

    return dp[m][n] = min(up, left);
}

int minPathSum_mem(vector<vector<int>> &grid)
{
    int m = grid.size(), n = grid[0].size();
    vector<vector<int>> dp(m, vector<int>(n, -1));

    return mem(grid, m - 1, n - 1, dp);
}

// Tabulated Approach ------------------------------------------

int minPathSum_tebulated(vector<vector<int>> &grid)
{
    int m = grid.size(), n = grid[0].size();
    vector<vector<int>> dp(m, vector<int>(n));

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i == 0 and j == 0)
            {
                dp[i][j] = grid[i][j];
            }
            else
            {
                int up = INT_MAX, left = INT_MAX;

                if (i - 1 >= 0)
                    up = grid[i][j] + dp[i - 1][j];

                if (j - 1 >= 0)
                    left = grid[i][j] + dp[i][j - 1];

                dp[i][j] = min(up, left);
            }
        }
    }

    return dp[m - 1][n - 1];
}

// Space Optimized Approach ------------------------------------------

int minPathSum_SpaceOptimized(vector<vector<int>> &grid)
{
    int m = grid.size(), n = grid[0].size();
    vector<int> dp(n);

    for (int i = 0; i < m; i++)
    {
        vector<int> temp(n);
        for (int j = 0; j < n; j++)
        {
            if (i == 0 and j == 0)
            {
                temp[j] = grid[i][j];
            }
            else
            {
                int up = INT_MAX, left = INT_MAX;

                if (i - 1 >= 0)
                    up = grid[i][j] + dp[j];

                if (j - 1 >= 0)
                    left = grid[i][j] + temp[j - 1];

                temp[j] = min(up, left);
            }
        }
        dp = temp;
    }

    return dp[n - 1];
}