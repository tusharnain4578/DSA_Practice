#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
// practice --> https://leetcode.com/problems/cherry-pickup-ii/

// Please revise in this order
// Recursion -> Memoization -> Tabulation -> Space Optimization

//
// problem type -> fixed starting point, variable ending point, 3d DP
// Approaches ->

// Recursive Approach ------------------------------------------

int rec(vector<vector<int>> &grid, int &m, int &n, int i, int j1, int j2) //(i1, j1) for robot 1, and (i2, j2) for robot 3
// but we don't need to take i1 and i2, both robots have to go down level 1 every time, their rows will always be same, that's why we only need i
{
    if (j1 < 0 or j2 < 0 or j1 >= n or j2 >= n) // out of bound base cases
        return -1;

    if (i == m - 1) // reached destination i.e, bottom row
    {
        if (j1 == j2) // if both robots reaches to same column, then we only include the cherries once
            return grid[i][j1];
        else // return sum of cherries collected by both robots
            return grid[i][j1] + grid[i][j2];
    }

    int max_cherries = 0;
    // 2 robots, 3 paths, they're moving simultaneously, all possible paths will by 3X3

    for (int r1_delta = -1; r1_delta <= 1; r1_delta++)
    {
        for (int r2_delta = -1; r2_delta <= 1; r2_delta++)
            max_cherries = max(max_cherries, rec(grid, m, n, i + 1, j1 + r1_delta, j2 + r2_delta));
    }

    // collecting current cherries
    if (j1 == j2) // if both robots reaches to same column, then we only include the cherries once
        max_cherries += grid[i][j1];
    else // return sum of cherries collected by both robots
        max_cherries += grid[i][j1] + grid[i][j2];

    return max_cherries;
}

int cherryPickup_rec(vector<vector<int>> &grid)
{
    int m = grid.size(), n = grid[0].size();

    return rec(grid, m, n, 0, 0, n - 1);
}

// Memoized Approach ------------------------------------------

int mem(vector<vector<int>> &grid, int &m, int &n, int i, int j1, int j2, vector<vector<vector<int>>> &dp)
{
    if (j1 < 0 or j2 < 0 or j1 >= n or j2 >= n) // out of bound base cases
        return -1;

    if (i == m - 1)
    {
        if (j1 == j2)
            return grid[i][j1];
        else
            return grid[i][j1] + grid[i][j2];
    }

    if (dp[i][j1][j2] != -1)
        return dp[i][j1][j2];

    int max_cherries = 0;

    for (int r1_delta = -1; r1_delta <= 1; r1_delta++)
    {
        for (int r2_delta = -1; r2_delta <= 1; r2_delta++)
            max_cherries = max(max_cherries, mem(grid, m, n, i + 1, j1 + r1_delta, j2 + r2_delta, dp));
    }

    if (j1 == j2)
        max_cherries += grid[i][j1];
    else
        max_cherries += grid[i][j1] + grid[i][j2];

    return dp[i][j1][j2] = max_cherries;
}

int cherryPickup_mem(vector<vector<int>> &grid)
{
    int m = grid.size(), n = grid[0].size();
    // vector of [m][n][n], because variations in function call are f(i, j1, j2), i ranges upto m, j1 ranges upto n, j2 ranges upto n, that's why [m][n][n]
    vector<vector<vector<int>>> dp(m, vector<vector<int>>(n, vector<int>(n, -1))); // 3d DP

    return mem(grid, m, n, 0, 0, n - 1, dp);
}

// Tabulated Approach ------------------------------------------

int cherryPickup_tabulated(vector<vector<int>> &grid)
{
    int m = grid.size(), n = grid[0].size();
    vector<vector<vector<int>>> dp(m, vector<vector<int>>(n, vector<int>(n))); // 3D DP

    for (int j1 = 0; j1 < n; j1++)
    {
        for (int j2 = 0; j2 < n; j2++)
        {
            if (j1 == j2)
                dp[m - 1][j1][j2] = grid[m - 1][j1];
            else
                dp[m - 1][j1][j2] = grid[m - 1][j1] + grid[m - 1][j2];
        }
    }

    for (int i = m - 2; i >= 0; i--)
    {
        for (int j1 = 0; j1 < n; j1++)
        {
            for (int j2 = 0; j2 < n; j2++)
            {
                int max_cherries = 0;

                for (int r1_delta = -1; r1_delta <= 1; r1_delta++)
                {
                    for (int r2_delta = -1; r2_delta <= 1; r2_delta++)
                    {
                        // out of bound indeces check
                        if (j1 + r1_delta >= 0 and j1 + r1_delta < n and j2 + r2_delta >= 0 and j2 + r2_delta < n)
                            max_cherries = max(max_cherries, dp[i + 1][j1 + r1_delta][j2 + r2_delta]);
                    }
                }

                if (j1 == j2)
                    max_cherries += grid[i][j1];
                else
                    max_cherries += grid[i][j1] + grid[i][j2];

                dp[i][j1][j2] = max_cherries;
            }
        }
    }
    return dp[0][0][n - 1];
}

// Space Optimized Approach ------------------------------------------

int cherryPickup_SpaceOptimized(vector<vector<int>> &grid)
{
    int m = grid.size(), n = grid[0].size();
    vector<vector<vector<int>>> dp(m, vector<vector<int>>(n, vector<int>(n))); // 3D DP

    for (int j1 = 0; j1 < n; j1++)
    {
        for (int j2 = 0; j2 < n; j2++)
        {
            if (j1 == j2)
                dp[m - 1][j1][j2] = grid[m - 1][j1];
            else
                dp[m - 1][j1][j2] = grid[m - 1][j1] + grid[m - 1][j2];
        }
    }

    for (int i = m - 2; i >= 0; i--)
    {
        for (int j1 = 0; j1 < n; j1++)
        {
            for (int j2 = 0; j2 < n; j2++)
            {
                int max_cherries = 0;

                for (int r1_delta = -1; r1_delta <= 1; r1_delta++)
                {
                    for (int r2_delta = -1; r2_delta <= 1; r2_delta++)
                    {
                        // out of bound indeces check
                        if (j1 + r1_delta >= 0 and j1 + r1_delta < n and j2 + r2_delta >= 0 and j2 + r2_delta < n)
                            max_cherries = max(max_cherries, dp[i + 1][j1 + r1_delta][j2 + r2_delta]);
                    }
                }

                if (j1 == j2)
                    max_cherries += grid[i][j1];
                else
                    max_cherries += grid[i][j1] + grid[i][j2];

                dp[i][j1][j2] = max_cherries;
            }
        }
    }
    return dp[0][0][n - 1];
}
