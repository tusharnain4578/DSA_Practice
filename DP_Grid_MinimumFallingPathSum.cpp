#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
// practice --> https://leetcode.com/problems/minimum-falling-path-sum/

// Please revise in this order
// Recursion -> Memoization -> Tabulation -> Space Optimization

//
//
// Approaches ->

// Recursive Approach ------------------------------------------

int rec(vector<vector<int>> &matrix, int i, int j)
{
    if (i == 0)
        return matrix[i][j]; // equals matrix[0][j];

    int up_left = INT_MAX, up_right = INT_MAX;

    // no need for grid size validation for i, because i == 0 is taken care in above base case

    int up = matrix[i][j] + rec(matrix, i - 1, j);

    if (j - 1 >= 0)
        up_left = matrix[i][j] + rec(matrix, i - 1, j - 1);

    if (j + 1 < matrix[0].size())
        up_right = matrix[i][j] + rec(matrix, i - 1, j + 1);

    return min(up, min(up_left, up_right));
}

int minFallingPathSum_rec(vector<vector<int>> &matrix)
{
    int m = matrix.size(), n = matrix[0].size();
    int ans = INT_MAX;

    for (int i = 0; i < n; i++)
    {
        ans = min(ans, rec(matrix, m - 1, i));
    }

    return ans;
}

// Memoized Approach ------------------------------------------

int mem(vector<vector<int>> &matrix, int i, int j, vector<vector<int>> &dp)
{
    if (i == 0)
        return matrix[i][j]; // equals matrix[0][j];

    if (dp[i][j] != -1)
        return dp[i][j];

    int up_left = INT_MAX, up_right = INT_MAX;

    // no need for grid size validation for i, because i == 0 is taken care in above base case

    int up = matrix[i][j] + mem(matrix, i - 1, j, dp);

    if (j - 1 >= 0)
        up_left = matrix[i][j] + mem(matrix, i - 1, j - 1, dp);

    if (j + 1 < matrix[0].size())
        up_right = matrix[i][j] + mem(matrix, i - 1, j + 1, dp);

    return dp[i][j] = min(up, min(up_left, up_right));
}

int minFallingPathSum_mem(vector<vector<int>> &matrix)
{
    int m = matrix.size(), n = matrix[0].size();
    int ans = INT_MAX;

    vector<vector<int>> dp(m, vector<int>(n, -1));

    for (int i = 0; i < n; i++)
    {
        ans = min(ans, mem(matrix, m - 1, i, dp));
    }

    return ans;
}

// Tabulated Approach ------------------------------------------

int minFallingPathSum_tabulated(vector<vector<int>> &matrix)
{
    int m = matrix.size(), n = matrix[0].size();
    int ans = INT_MAX;

    vector<vector<int>> dp(m, vector<int>(n));

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i == 0)
            {
                dp[i][j] = matrix[0][j]; // or matrix[i][j], they're same
            }
            else
            {
                int up_left = INT_MAX, up_right = INT_MAX;

                //

                int up = matrix[i][j] + dp[i - 1][j];

                if (j - 1 >= 0)
                    up_left = matrix[i][j] + dp[i - 1][j - 1];

                if (j + 1 < matrix[0].size())
                    up_right = matrix[i][j] + dp[i - 1][j + 1];

                dp[i][j] = min(up, min(up_left, up_right));
            }
        }
    }
    ans = *min_element(dp[m - 1].begin(), dp[m - 1].end());
    return ans;
}

// Space Optimized Approach ------------------------------------------

int minFallingPathSum_SpaceOptimized(vector<vector<int>> &matrix)
{
    int m = matrix.size(), n = matrix[0].size();
    int ans = INT_MAX;

    vector<int> dp(n);

    for (int i = 0; i < m; i++)
    {
        vector<int> temp(n);

        for (int j = 0; j < n; j++)
        {
            if (i == 0)
            {
                temp[j] = matrix[0][j]; // or matrix[i][j], they're same
            }
            else
            {
                int up_left = INT_MAX, up_right = INT_MAX;

                //

                int up = matrix[i][j] + dp[j];

                if (j - 1 >= 0)
                    up_left = matrix[i][j] + dp[j - 1];

                if (j + 1 < matrix[0].size())
                    up_right = matrix[i][j] + dp[j + 1];

                temp[j] = min(up, min(up_left, up_right));
            }
        }
        dp = temp;
    }
    ans = *min_element(dp.begin(), dp.end());
    return ans;
}