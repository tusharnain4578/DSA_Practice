#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// practice --> https://practice.geeksforgeeks.org/problems/matrix-chain-multiplication0303/1

//*********************************************

// tip-> if the columns of the first matrix is equal to the rows of the second matrix, only then they can be multiplied. And the product matrix will be row of first matrix * cols of second matrix

// example-> A(10x30) * B(30*5)

// no of cols of A i.e, 30 and rows of B(30), are both 30, which means they can be multiplied

// The resultant matrix of their product is of size P(10x5)

//**********************************************

// Please revise in this order
// Recursion -> Memoization -> Tabulation -> Space Optimization

//
//
// Approaches ->

// Recursive Approach ------------------------------------------

int rec(int i, int j, int arr[])
{
    if (i == j)
        return 0;

    int ans = INT_MAX;

    for (int k = i; k < j; k++)
    {
        int steps = arr[i - 1] * arr[k] * arr[j] + rec(i, k, arr) + rec(k + 1, j, arr);

        if (steps < ans)
            ans = steps;
    }

    return ans;
}

int matrixMultiplication(int N, int arr[])
{
    return rec(1, N - 1, arr);
}

// Memoized Approach ------------------------------------------

int mem(int i, int j, int arr[], vector<vector<int>> &dp)
{
    if (i == j) // base case
        return 0;

    if (dp[i][j] != -1)
        return dp[i][j];

    int ans = INT_MAX;

    for (int k = i; k < j; k++)
    {
        int steps = arr[i - 1] * arr[k] * arr[j] + mem(i, k, arr, dp) + mem(k + 1, j, arr, dp);

        if (steps < ans)
            ans = steps;
    }

    return dp[i][j] = ans;
}

int matrixMultiplication(int N, int arr[])
{
    vector<vector<int>> dp(N, vector<int>(N, -1)); // 2D DP
    return mem(1, N - 1, arr, dp);
}

// Tabulation

int matrixMultiplication(int N, int arr[])
{
    vector<vector<int>> dp(N, vector<int>(N)); // 2D DP

    for (int i = 0; i < N; i++) // base case initialization
        dp[i][i] = 0;

    for (int i = N - 1; i >= 1; i--)
    {
        for (int j = i + 1; j < N; j++)
        {
            int ans = INT_MAX;

            for (int k = i; k < j; k++)
            {
                int steps = arr[i - 1] * arr[k] * arr[j] + dp[i][k] + dp[k + 1][j];

                if (steps < ans)
                    ans = steps;
            }

            dp[i][j] = ans;
        }
    }

    return dp[1][N - 1];
}