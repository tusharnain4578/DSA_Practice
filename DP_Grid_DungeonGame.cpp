#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
// practice --> https://leetcode.com/problems/dungeon-game/

// Please revise in this order
// Recursion -> Memoization -> Tabulation -> Space Optimization

//
// Approaches ->

// Recursive Approach ------------------------------------------

int rec(vector<vector<int>> &grid, int &m, int &n, int i, int j)
{
    if (i >= m or j >= n)
        return INT_MAX;

    if (i == m - 1 and j == n - 1)
    {
        if (grid[i][j] < 0)
            return -grid[i][j] + 1;
        else
            return 1;
    }

    int right = rec(grid, m, n, i, j + 1);
    int down = rec(grid, m, n, i + 1, j);

    int health = min(right, down);

    if (health - grid[i][j] < 1)
        return 1;

    int res = health - grid[i][j];

    return res;
}

int calculateMinimumHP_rec(vector<vector<int>> &dungeon)
{
    int m = dungeon.size(), n = dungeon[0].size();
    return rec(dungeon, m, n, 0, 0);
}

// Memoized Approach ------------------------------------------

int mem(vector<vector<int>> &grid, int &m, int &n, int i, int j, vector<vector<int>> &dp)
{
    if (i >= m or j >= n)
        return INT_MAX;

    if (i == m - 1 and j == n - 1)
    {
        if (grid[i][j] < 0)
            return -grid[i][j] + 1;
        else
            return 1;
    }

    if (dp[i][j] != -1)
        return dp[i][j];

    int right = mem(grid, m, n, i, j + 1, dp);
    int down = mem(grid, m, n, i + 1, j, dp);

    int health = min(right, down);

    if (health - grid[i][j] < 1)
        return dp[i][j] = 1;

    int res = health - grid[i][j];

    return dp[i][j] = res;
}

int calculateMinimumHP_mem(vector<vector<int>> &dungeon)
{
    int m = dungeon.size(), n = dungeon[0].size();

    vector<vector<int>> dp(m, vector<int>(n, -1));

    return mem(dungeon, m, n, 0, 0, dp);
}

// Tabulated Approach ------------------------------------------

int calculateMinimumHP_tabulated(vector<vector<int>> &dungeon)
{
    int m = dungeon.size(), n = dungeon[0].size();
    vector<vector<int>> &grid = dungeon;

    vector<vector<int>> dp(m, vector<int>(n));

    for (int i = m - 1; i >= 0; i--)
    {
        for (int j = n - 1; j >= 0; j--)
        {

            if (i == m - 1 and j == n - 1)
            {
                if (grid[m - 1][n - 1] < 0)
                    dp[m - 1][n - 1] = -grid[m - 1][n - 1] + 1;
                else
                    dp[m - 1][n - 1] = 1;
            }
            else
            {
                int right = INT_MAX, down = INT_MAX;

                if (j + 1 < n)
                    right = dp[i][j + 1];

                if (i + 1 < m)
                    down = dp[i + 1][j];

                int health = min(right, down);

                int res;

                if (health - grid[i][j] < 1)
                    res = 1;
                else
                    res = health - grid[i][j];

                dp[i][j] = res;
            }
        }
    }
    return dp[0][0];
}

// Space Optimized Approach ------------------------------------------

int calculateMinimumHP_SpaceOptimized(vector<vector<int>> &dungeon)
{
    int m = dungeon.size(), n = dungeon[0].size();
    vector<vector<int>> &grid = dungeon;

    vector<int> dp(n);

    for (int i = m - 1; i >= 0; i--)
    {
        vector<int> temp(n);
        for (int j = n - 1; j >= 0; j--)
        {

            if (i == m - 1 and j == n - 1)
            {
                if (grid[m - 1][n - 1] < 0)
                    temp[j] = -grid[m - 1][n - 1] + 1;
                else
                    temp[j] = 1;
            }
            else
            {
                int right = INT_MAX, down = INT_MAX;

                if (j + 1 < n)
                    right = temp[j + 1];

                if (i + 1 < m)
                    down = dp[j];

                int health = min(right, down);

                int res;

                if (health - grid[i][j] < 1)
                    res = 1;
                else
                    res = health - grid[i][j];

                temp[j] = res;
            }
        }
        dp = temp;
    }
    return dp[0];
}