#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// practice --> https://practice.geeksforgeeks.org/problems/lcs-of-three-strings0028/1

// pre req-> LCS

// recusion
int rec(const string &A, const string &B, const string &C, int i, int j, int k)
{
    if (i < 0 or j < 0 or k < 0)
        return 0;

    if (A[i] == B[j] and B[j] == C[k])
        return 1 + rec(A, B, C, i - 1, j - 1, k - 1);

    return 0 + max({rec(A, B, C, i - 1, j, k), rec(A, B, C, i, j - 1, k), rec(A, B, C, i, j, k - 1)});
}

int LCSof3(string A, string B, string C, int n1, int n2, int n3)
{
    return rec(A, B, C, n1 - 1, n2 - 1, n3 - 1);
}

// memoization

int mem(const string &A, const string &B, const string &C, int i, int j, int k, vector<vector<vector<int>>> &dp)
{
    if (i < 0 or j < 0 or k < 0)
        return 0;

    if (dp[i][j][k] != -1)
        return dp[i][j][k];

    if (A[i] == B[j] and B[j] == C[k])
        return 1 + mem(A, B, C, i - 1, j - 1, k - 1, dp);

    return dp[i][j][k] = 0 + max({mem(A, B, C, i - 1, j, k, dp), mem(A, B, C, i, j - 1, k, dp), mem(A, B, C, i, j, k - 1, dp)});
}

int LCSof3(string A, string B, string C, int n1, int n2, int n3)
{
    vector<vector<vector<int>>> dp(n1, vector<vector<int>>(n2, vector<int>(n3, -1)));
    return mem(A, B, C, n1 - 1, n2 - 1, n3 - 1, dp);
}

// Tabulation // 3d dp
int LCSof3(string A, string B, string C, int n1, int n2, int n3)
{
    // initializing dp of an extra space because of the <0 base condition and by default filling it with 0's
    vector<vector<vector<int>>> dp(n1 + 1, vector<vector<int>>(n2 + 1, vector<int>(n3 + 1, 0)));

    for (int i = 1; i <= n1; i++)
    {
        for (int j = 1; j <= n2; j++)
        {
            for (int k = 1; k <= n3; k++)
            {
                if (A[i - 1] == B[j - 1] and B[j - 1] == C[k - 1])
                    dp[i][j][k] = 1 + dp[i - 1][j - 1][k - 1];
                else
                    dp[i][j][k] = 0 + max({dp[i - 1][j][k], dp[i][j - 1][k], dp[i][j][k - 1]});
            }
        }
    }
    return dp[n1][n2][n3];
}

// Space Optimized Solution // 2d dp
int LCSof3(string A, string B, string C, int n1, int n2, int n3)
{
    // initializing dp of an extra space because of the <0 base condition and by default filling it with 0's
    vector<vector<int>> dp(n2 + 1, vector<int>(n3 + 1, 0));

    for (int i = 1; i <= n1; i++)
    {
        vector<vector<int>> temp(n2 + 1, vector<int>(n3 + 1, 0));

        for (int j = 1; j <= n2; j++)
        {
            for (int k = 1; k <= n3; k++)
            {
                if (A[i - 1] == B[j - 1] and B[j - 1] == C[k - 1])
                    temp[j][k] = 1 + dp[j - 1][k - 1];
                else
                    temp[j][k] = 0 + max({dp[j][k], temp[j - 1][k], temp[j][k - 1]});
            }
        }

        dp = temp;
    }
    return dp[n2][n3];
}