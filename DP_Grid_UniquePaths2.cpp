#include <iostream>
#include <vector>
using namespace std;
// Most Optimal Approach is in Array_GridUniquePathsOptimal.cpp

// practice --> https://leetcode.com/problems/unique-paths/

// Please revise in this order
// Recursion -> Memoization -> Tabulation -> Space Optimization

// in this entire code file, i did it in 0 based indexing

//
//
// Approaches ->
// Recursive Approach ------------------------------------------
int rec(vector<vector<int>> &grid, int m, int n)
{
    // check the obstacle condition first because what if the destination grid is obstacle itself
    if (m < 0 or n < 0 or grid[m][n] == 1)
        return 0;

    if (m == 0 and n == 0)
        return 1;

    int up = rec(grid, m - 1, n);
    int left = rec(grid, m, n - 1);

    return up + left;
}
int uniquePathsWithObstacles(vector<vector<int>> &obstacleGrid)
{
    int m = obstacleGrid.size();
    int n = obstacleGrid[0].size();

    return rec(obstacleGrid, m - 1, n - 1);
}

// memoized Approach ------------------------------------------
int mem(vector<vector<int>> &grid, int m, int n, vector<vector<int>> &dp)
{
    // check the obstacle condition first because what if the destination grid is obstacle itself
    if (m < 0 or n < 0 or grid[m][n] == 1)
        return 0;

    if (m == 0 and n == 0)
        return 1;

    if (dp[m][n] != -1)
        return dp[m][n];

    int up = mem(grid, m - 1, n, dp);
    int left = mem(grid, m, n - 1, dp);

    return dp[m][n] = up + left;
}
int uniquePathsWithObstacles_mem(vector<vector<int>> &obstacleGrid)
{
    int m = obstacleGrid.size();
    int n = obstacleGrid[0].size();

    vector<vector<int>> dp(m, vector<int>(n, -1));

    return mem(obstacleGrid, m - 1, n - 1, dp);
}

// Tabulated Approach -------------------------------------
int uniquePathsWithObstacles_tabulated(vector<vector<int>> &obstacleGrid)
{
    int m = obstacleGrid.size();
    int n = obstacleGrid[0].size();

    vector<vector<int>> dp(m, vector<int>(n));

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (obstacleGrid[i][j] == 1)
            {
                dp[i][j] = 0;
            }
            else if (i == 0 and j == 0) // use if-else ladder, because
            {
                dp[i][j] = 1;
            }
            else
            {
                int up = 0, left = 0;

                if (i > 0)
                    up = dp[i - 1][j];
                if (j > 0)
                    left = dp[i][j - 1];

                dp[i][j] = up + left;
            }
        }
    }

    return dp[m - 1][n - 1];
}

// Space Optimized Approach -------------------------------------
int uniquePathsWithObstacles_spaceoptimized(vector<vector<int>> &obstacleGrid)
{
    int m = obstacleGrid.size();
    int n = obstacleGrid[0].size();

    vector<int> dp(n);

    for (int i = 0; i < m; i++)
    {
        vector<int> temp(n);

        for (int j = 0; j < n; j++)
        {
            if (obstacleGrid[i][j] == 1)
            {
                temp[j] = 0;
            }
            else if (i == 0 and j == 0) // use if-else ladder, because what if the destination is obstacle itself
            {
                temp[j] = 1;
            }
            else
            {
                int up = 0, left = 0;

                if (i > 0)
                    up = dp[j];
                if (j > 0)
                    left = temp[j - 1];

                temp[j] = up + left;
            }
        }
        dp = temp;
    }

    return dp[n - 1];
}
