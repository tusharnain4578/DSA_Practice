#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
// practice ---> https://practice.geeksforgeeks.org/problems/largest-square-formed-in-a-matrix0806/1

// reference --> https://www.youtube.com/watch?v=MMr19RE7KYY

// recursion
int rec(vector<vector<int>> &matrix, int i, int j, int &ans)
{
    if (i < 0 or j < 0)
        return 0;

    int left = rec(matrix, i, j - 1, ans);
    int up = rec(matrix, i - 1, j, ans);
    int up_left = rec(matrix, i - 1, j - 1, ans);

    if (matrix[i][j] == 1)
    {
        int this_ans = 1 + min({left, up, up_left});

        if (this_ans > ans)
            ans = this_ans;

        return this_ans; // here return this_ans, not ans
    }

    // else
    return 0;
}

int maxSquare(int n, int m, vector<vector<int>> mat)
{
    int ans = 0;
    rec(mat, n - 1, m - 1, ans);

    return ans;
}

// memoization
int mem(vector<vector<int>> &matrix, int i, int j, int &ans, vector<vector<int>> &dp)
{
    if (i < 0 or j < 0)
        return 0;

    if (dp[i][j] != -1)
        return dp[i][j];

    int left = mem(matrix, i, j - 1, ans, dp);
    int up = mem(matrix, i - 1, j, ans, dp);
    int up_left = mem(matrix, i - 1, j - 1, ans, dp);

    if (matrix[i][j] == 1)
    {
        int this_ans = 1 + min({left, up, up_left});

        if (this_ans > ans)
            ans = this_ans;

        return dp[i][j] = this_ans; // here return this_ans, not ans
    }

    // else
    return dp[i][j] = 0;
}

int maxSquare_mem(int n, int m, vector<vector<int>> mat)
{
    int ans = 0;

    vector<vector<int>> dp(n, vector<int>(m, -1));

    mem(mat, n - 1, m - 1, ans, dp);

    return ans;
}

// Tabulation
int maxSquare(int n, int m, vector<vector<int>> mat)
{
    int ans = 0;

    vector<vector<int>> dp(n + 1, vector<int>(m + 1));

    // base case
    for (int i = 0; i < n; i++)
        dp[i][0] = 0;

    for (int i = 0; i < m; i++)
        dp[0][i] = 0;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            int left = dp[i][j - 1];
            int up = dp[i - 1][j];
            int up_left = dp[i - 1][j - 1];

            if (mat[i - 1][j - 1] == 1)
            {
                int this_ans = 1 + min({left, up, up_left});

                if (this_ans > ans)
                    ans = this_ans;

                dp[i][j] = this_ans; // here return this_ans, not ans
            }
            else
                dp[i][j] = 0;
        }
    }

    // the maximum value from the entire dp is the ans, which we are calculating on our iterations
    return ans;
}

// Space Optimized
int maxSquare(int n, int m, vector<vector<int>> mat)
{
    int ans = 0;

    vector<int> dp(m + 1, 0);

    // for base case, we just set the dp with zero (its one row btw)

    for (int i = 1; i <= n; i++)
    {
        vector<int> temp(m + 1);
        temp[0] = 0; // base case, coz first col in every row is zero

        for (int j = 1; j <= m; j++)
        {
            int left = temp[j - 1];
            int up = dp[j];
            int up_left = dp[j - 1];

            if (mat[i - 1][j - 1] == 1)
            {
                int this_ans = 1 + min({left, up, up_left});

                if (this_ans > ans)
                    ans = this_ans;

                temp[j] = this_ans; // here return this_ans, not ans
            }
            else
                temp[j] = 0;
        }

        dp = temp;
    }

    // the maximum value from the entire dp is the ans, which we are calculating on our iterations
    return ans;
}