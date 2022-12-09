#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
// practice ---> https://practice.geeksforgeeks.org/problems/path-in-matrix3805/1

// problem statement gave top to bottom, but bottom to top will be same, think about it

// recursion
int rec(vector<vector<int>> &matrix, int &N, int i, int j)
{
    if (j < 0 or j >= N)
        return -1e9;

    if (i == 0)
        return matrix[i][j];

    int up = matrix[i][j] + rec(matrix, N, i - 1, j);
    int up_left = matrix[i][j] + rec(matrix, N, i - 1, j - 1);
    int up_right = matrix[i][j] + rec(matrix, N, i - 1, j + 1);

    return max({up, up_left, up_right});
}

int maximumPath_rec(int N, vector<vector<int>> Matrix)
{
    int ans = INT_MIN;

    for (int i = 0; i < N; i++)
        ans = max(ans, rec(Matrix, N, N - 1, i));

    return ans;
}

// memoization
int mem(vector<vector<int>> &matrix, int &N, int i, int j, vector<vector<int>> &dp)
{
    if (j < 0 or j >= N)
        return -1e9;

    if (i == 0)
        return matrix[i][j];

    if (dp[i][j] != -1)
        return dp[i][j];

    int up = matrix[i][j] + mem(matrix, N, i - 1, j, dp);
    int up_left = matrix[i][j] + mem(matrix, N, i - 1, j - 1, dp);
    int up_right = matrix[i][j] + mem(matrix, N, i - 1, j + 1, dp);

    return dp[i][j] = max({up, up_left, up_right});
}

int maximumPath_mem(int N, vector<vector<int>> Matrix)
{
    int ans = INT_MIN;

    vector<vector<int>> dp(N, vector<int>(N, -1));

    for (int i = 0; i < N; i++)
        ans = max(ans, mem(Matrix, N, N - 1, i, dp));

    return ans;
}

// tabulation
int maximumPath(int N, vector<vector<int>> Matrix)
{
    int ans = INT_MIN;

    vector<vector<int>> dp(N, vector<int>(N));

    // base case
    for (int i = 0; i < N; i++)
        dp[0][i] = Matrix[0][i];

    for (int i = 1; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            int up = Matrix[i][j] + dp[i - 1][j];
            int up_left = j - 1 >= 0 ? Matrix[i][j] + dp[i - 1][j - 1] : -1e9;
            int up_right = j + 1 < N ? Matrix[i][j] + dp[i - 1][j + 1] : -1e9;

            dp[i][j] = max({up, up_left, up_right});
        }
    }

    for (int i = 0; i < N; i++)
        ans = max(ans, dp[N - 1][i]);

    return ans;
}

// Space Optimized
int maximumPath(int N, vector<vector<int>> Matrix)
{
    int ans = INT_MIN;

    vector<int> dp(N);

    // base case
    for (int i = 0; i < N; i++)
        dp[i] = Matrix[0][i];

    for (int i = 1; i < N; i++)
    {
        vector<int> temp(N);

        for (int j = 0; j < N; j++)
        {
            int up = Matrix[i][j] + dp[j];
            int up_left = j - 1 >= 0 ? Matrix[i][j] + dp[j - 1] : -1e9;
            int up_right = j + 1 < N ? Matrix[i][j] + dp[j + 1] : -1e9;

            temp[j] = max({up, up_left, up_right});
        }

        dp = temp;
    }

    ans = *min_element(dp.begin(), dp.end());

    return ans;
}