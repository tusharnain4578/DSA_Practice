#include <iostream>
#include <vector>
using namespace std;
// practice --> https://leetcode.com/problems/triangle/

// Please revise in this order
// Recursion -> Memoization -> Tabulation -> Space Optimization

//
//
// Approaches ->

// Recursive Approach ------------------------------------------

int rec(vector<vector<int>> &tri, int i, int j, int m)
{
    if (i == m)
        return tri[i][j];

    // no grid size validation required, because the last row is managed by above base case,
    // that means there will always be next row, and next row is 1 size bigger than this one
    int down = tri[i][j] + rec(tri, i + 1, j, m);
    int diagonal = tri[i][j] + rec(tri, i + 1, j + 1, m);

    return min(down, diagonal);
}

int minimumTotal(vector<vector<int>> &triangle)
{
    int m = triangle.size() - 1; // m rows count

    return rec(triangle, 0, 0, m - 1);
}

// Memoized Approach ------------------------------------------

int mem(vector<vector<int>> &tri, int i, int j, int m, vector<vector<int>> &dp)
{
    if (i == m)
        return tri[i][j];

    if (dp[i][j] != -1)
        return dp[i][j];

    // no grid size validation required, because the last row is managed by above base case,
    // that means there will always be next row, and next row is 1 size bigger than this one
    int down = tri[i][j] + mem(tri, i + 1, j, m, dp);
    int diagonal = tri[i][j] + mem(tri, i + 1, j + 1, m, dp);

    return dp[i][j] = min(down, diagonal);
}

int minimumTotal_mem(vector<vector<int>> &triangle)
{
    int m = triangle.size(); // m rows count

    vector<vector<int>> dp(m);

    for (int i = 0; i < m; i++)
        dp[i].resize(i + 1, -1); // for making tringular dp

    return mem(triangle, 0, 0, m - 1, dp); // m-1 is last row index
}

// Tabulated Approach ------------------------------------------

int minimumTotal_tabulated(vector<vector<int>> &triangle)
{
    int m = triangle.size(); // m rows count

    vector<vector<int>> dp(m);

    for (int i = 0; i < m; i++) // for making tringular dp
    {
        if (i == m - 1)
        {
            dp[i] = triangle[m - 1];
            break;
        }

        dp[i].resize(i + 1);
    }

    for (int i = m - 2; i >= 0; i--)
    {
        for (int j = 0; j <= i; j++)
        {
            int down = triangle[i][j] + dp[i + 1][j];
            int diagonal = triangle[i][j] + dp[i + 1][j + 1];

            dp[i][j] = min(down, diagonal);
        }
    }

    return dp[0][0];
}

// Space Optimized Approach ------------------------------------------

int minimumTotal_SpaceOptimized(vector<vector<int>> &triangle)
{
    int m = triangle.size(); // m rows count

    vector<int> dp(m);

    dp = triangle[m - 1];

    for (int i = m - 2; i >= 0; i--)
    {
        vector<int> temp(i + 1);
        for (int j = 0; j <= i; j++)
        {
            int down = triangle[i][j] + dp[j];
            int diagonal = triangle[i][j] + dp[j + 1];

            temp[j] = min(down, diagonal);
        }

        dp = temp;
    }

    return dp[0];
}