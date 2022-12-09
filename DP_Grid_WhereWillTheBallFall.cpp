#include <iostream>
#include <vector>
using namespace std;
// practice ---> https://leetcode.com/problems/where-will-the-ball-fall/

// reference ---> https://www.youtube.com/watch?v=n9MWnpCcbzA
// she's just using dfs, i will use this approach with dynamic programming

// grid[i][j] = 1 ---> left to right
// grid[i][j] = -1 ---> right to left

// recursion
int rec(int i, int j, vector<vector<int>> &grid, int &m, int &n)
{
    if (i == m) // if the boll reach the last row, return the column (answer)
        return j;

    if (grid[i][j] == 1 and j + 1 < n and grid[i][j + 1] == 1) // left to right
        return rec(i + 1, j + 1, grid, m, n);

    if (grid[i][j] == -1 and j - 1 >= 0 and grid[i][j - 1] == -1) // right to left
        return rec(i + 1, j - 1, grid, m, n);

    // else the ball is stuck
    return -1;
}

vector<int> findBall_rec(vector<vector<int>> &grid)
{
    int m = grid.size(), n = grid[0].size();

    vector<int> ans;

    for (int i = 0; i < n; i++)
        ans.push_back(rec(0, i, grid, m, n));

    return ans;
}

// memoization
int mem(int i, int j, vector<vector<int>> &grid, int &m, int &n, vector<vector<int>> &dp)
{
    if (i == m)
        return j;

    if (dp[i][j] != -1)
        return dp[i][j];

    if (grid[i][j] == 1 and j + 1 < n and grid[i][j + 1] == 1)
        return dp[i][j] = mem(i + 1, j + 1, grid, m, n, dp);

    if (grid[i][j] == -1 and j - 1 >= 0 and grid[i][j - 1] == -1)
        return dp[i][j] = mem(i + 1, j - 1, grid, m, n, dp);

    return dp[i][j] = -1;
}

vector<int> findBall_mem(vector<vector<int>> &grid)
{
    int m = grid.size(), n = grid[0].size();

    vector<int> ans;

    vector<vector<int>> dp(m, vector<int>(n, -1));

    for (int i = 0; i < n; i++)
        ans.push_back(mem(0, i, grid, m, n, dp));

    return ans;
}

// tabulation

vector<int> findBall_tab(vector<vector<int>> &grid)
{
    int m = grid.size(), n = grid[0].size();

    vector<vector<int>> dp(m + 1, vector<int>(n));

    // base case
    for (int j = 0; j < n; j++)
        dp[m][j] = j;

    for (int i = m - 1; i >= 0; i--)
    {
        for (int col = 0; col < n; col++)
        {
            if (grid[i][col] == 1 and col + 1 < n and grid[i][col + 1] == 1)
                dp[i][col] = dp[i + 1][col + 1];
            else if (grid[i][col] == -1 and col - 1 >= 0 and grid[i][col - 1] == -1)
                dp[i][col] = dp[i + 1][col - 1];
            else
                dp[i][col] = -1;
        }
    }

    return dp[0];
}

// Space Optimized

vector<int> findBall(vector<vector<int>> &grid)
{
    int m = grid.size(), n = grid[0].size();

    vector<int> dp(n);

    // base case
    for (int j = 0; j < n; j++)
        dp[j] = j;

    for (int i = m - 1; i >= 0; i--)
    {
        vector<int> temp(n);

        for (int col = 0; col < n; col++)
        {
            if (grid[i][col] == 1 and col + 1 < n and grid[i][col + 1] == 1)
                temp[col] = dp[col + 1];
            else if (grid[i][col] == -1 and col - 1 >= 0 and grid[i][col - 1] == -1)
                temp[col] = dp[col - 1];
            else
                temp[col] = -1;
        }
        dp = temp;
    }

    return dp;
}