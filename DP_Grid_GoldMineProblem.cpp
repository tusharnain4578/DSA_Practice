#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// problem says col 1 to last col, we're gonna go opposite

// recursive approach
int rec(vector<vector<int>> &M, int &n, int &m, int i, int j)
{
    if (i < 0 or j < 0 or i >= n or j >= m)
        return 0;

    if (j == m - 1)
    {
        return M[i][j];
    }

    int up_right = M[i][j] + rec(M, n, m, i - 1, j + 1);
    int down_right = M[i][j] + rec(M, n, m, i + 1, j + 1);
    int right = M[i][j] + rec(M, n, m, i, j + 1);

    return max({up_right, down_right, right});
}

int maxGold(int n, int m, vector<vector<int>> M)
{
    int ans = INT_MIN;
    for (int i = 0; i < n; i++)
        ans = max(ans, rec(M, n, m, i, 0));

    return ans;
}

// Memoized approach
int mem(vector<vector<int>> &M, int &n, int &m, int i, int j, vector<vector<int>> &dp)
{
    if (i < 0 or j < 0 or i >= n or j >= m)
        return 0;

    if (j == m - 1)
    {
        return M[i][j];
    }

    if (dp[i][j] != -1)
        return dp[i][j];

    int up_right = M[i][j] + mem(M, n, m, i - 1, j + 1, dp);
    int down_right = M[i][j] + mem(M, n, m, i + 1, j + 1, dp);
    int right = M[i][j] + mem(M, n, m, i, j + 1, dp);

    return dp[i][j] = max({up_right, down_right, right});
}

int maxGold_mem(int n, int m, vector<vector<int>> M)
{
    int ans = INT_MIN;

    vector<vector<int>> dp(n, vector<int>(m, -1));

    for (int i = 0; i < n; i++)
        ans = max(ans, mem(M, n, m, i, 0, dp));

    return ans;
}

// Tabulation approach

int maxGold_tab(int n, int m, vector<vector<int>> M)
{
    // reference --> https://www.youtube.com/watch?v=hs0lilfJ7C0

    int ans = INT_MIN;

    vector<vector<int>> dp(n, vector<int>(m));

    // base case //i.e, filling the last column of dp table

    for (int i = 0; i < n; i++)
        dp[i][m - 1] = M[i][m - 1];

    for (int j = m - 2; j >= 0; j--)
    {
        // already filled the last col of dp table, that's why starting from 2nd last col
        for (int i = 0; i < n; i++)
        {

            int up_right = (i - 1 >= 0) ? M[i][j] + dp[i - 1][j + 1] : 0;
            int down_right = (i + 1 < n) ? M[i][j] + dp[i + 1][j + 1] : 0;
            int right = M[i][j] + dp[i][j + 1];

            dp[i][j] = max({up_right, down_right, right});
        }
    }

    // the max value from the first column of dp table  is the answer

    for (int i = 0; i < n; i++)
        ans = max(ans, dp[i][0]);

    return ans;
}

// Space Optimized approach

int maxGold_SpaceOptimized(int n, int m, vector<vector<int>> M)
{

    int ans = INT_MIN;

    vector<int> dp(n);

    for (int i = 0; i < n; i++)
        dp[i] = M[i][m - 1];

    for (int j = m - 2; j >= 0; j--)
    {
        vector<int> temp(n);
        // already filled the last col of dp table, that's why starting from 2nd last col
        for (int i = 0; i < n; i++)
        {

            int up_right = (i - 1 >= 0) ? M[i][j] + dp[i - 1] : 0;
            int down_right = (i + 1 < n) ? M[i][j] + dp[i + 1] : 0;
            int right = M[i][j] + dp[i];

            temp[i] = max({up_right, down_right, right});
        }
        dp = temp;
    }

    // the max value from the first column of dp table  is the answer

    for (int i = 0; i < n; i++)
        ans = max(ans, dp[i]);

    return ans;
}

// Constant space solution i.e, O(1) time

//  by using the input table as dp table, idk if it's recommended or not, but you can ask the other person

// just replaced the dp from tabulation approach to M(input table)

int maxGold_ConstantTime(int n, int m, vector<vector<int>> M)
{

    int ans = INT_MIN;

    for (int j = m - 2; j >= 0; j--)
    {
        // already filled the last col of dp table, that's why starting from 2nd last col
        for (int i = 0; i < n; i++)
        {

            int up_right = (i - 1 >= 0) ? M[i][j] + M[i - 1][j + 1] : 0;
            int down_right = (i + 1 < n) ? M[i][j] + M[i + 1][j + 1] : 0;
            int right = M[i][j] + M[i][j + 1];

            M[i][j] = max({up_right, down_right, right});
        }
    }

    // the max value from the first column of dp table  is the answer

    for (int i = 0; i < n; i++)
        ans = max(ans, M[i][0]);

    return ans;
}