#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// practice --> https://practice.geeksforgeeks.org/problems/boolean-parenthesization5610/1/
// Note -> gfg practice asking with mod

// Please revise in this order
// Recursion -> Memoization -> Tabulation

//
//
// Approaches ->

// Recursive Approach ------------------------------------------

int rec(int i, int j, const string &S, bool isTrue)
{
    if (i > j) // no need
        return 0;

    if (i == j)
    {
        if (isTrue)
            return S[i] == 'T';
        else
            return S[i] == 'F';
    }

    int totalWays = 0;

    for (int k = i + 1; k <= j - 1; k += 2) // look carefully, it's k += 2, ik you're note blind 😁, but just in case
    {
        int leftTrue = rec(i, k - 1, S, 1),
            leftFalse = rec(i, k - 1, S, 0),
            rightTrue = rec(k + 1, j, S, 1),
            rightFalse = rec(k + 1, j, S, 0);

        if (S[k] == '&')
        {
            if (isTrue)
                totalWays += leftTrue * rightTrue;
            else
                totalWays += (leftTrue * rightFalse) + (leftFalse * rightTrue) + (leftFalse * rightFalse);
        }
        else if (S[k] == '|')
        {
            if (isTrue)
                totalWays += (leftTrue * rightTrue) + (leftTrue * rightFalse) + (leftFalse * rightTrue);
            else
                totalWays += leftFalse * rightFalse;
        }
        else // S[k] == '^'
        {
            if (isTrue)
                totalWays += (rightTrue * leftFalse) + (rightFalse * leftTrue);
            else
                totalWays += (rightTrue * leftTrue) + (rightFalse * leftFalse);
        }
    }

    return totalWays;
}

int countWays(int N, string S)
{
    return rec(0, N - 1, S, 1);
}

// Memoized Approach ------------------------------------------

int mem(int i, int j, const string &S, bool isTrue, vector<vector<vector<int>>> &dp)
{
    if (i > j) // no need
        return 0;

    if (i == j)
    {
        if (isTrue)
            return S[i] == 'T';
        else
            return S[i] == 'F';
    }

    if (dp[i][j][isTrue] != -1)
        return dp[i][j][isTrue];

    int totalWays = 0;

    for (int k = i + 1; k <= j - 1; k += 2) // look carefully, it's k += 2
    {
        int leftTrue = mem(i, k - 1, S, 1, dp),
            leftFalse = mem(i, k - 1, S, 0, dp),
            rightTrue = mem(k + 1, j, S, 1, dp),
            rightFalse = mem(k + 1, j, S, 0, dp);

        if (S[k] == '&')
        {
            if (isTrue)
                totalWays += leftTrue * rightTrue;
            else
                totalWays += (leftTrue * rightFalse) + (leftFalse * rightTrue) + (leftFalse * rightFalse);
        }
        else if (S[k] == '|')
        {
            if (isTrue)
                totalWays += (leftTrue * rightTrue) + (leftTrue * rightFalse) + (leftFalse * rightTrue);
            else
                totalWays += leftFalse * rightFalse;
        }
        else // S[k] == '^'
        {
            if (isTrue)
                totalWays += (rightTrue * leftFalse) + (rightFalse * leftTrue);
            else
                totalWays += (rightTrue * leftTrue) + (rightFalse * leftFalse);
        }
    }

    return dp[i][j][isTrue] = totalWays;
}

int countWays(int N, string S)
{
    vector<vector<vector<int>>> dp(N, vector<vector<int>>(N, vector<int>(2, -1)));
    return mem(0, N - 1, S, 1, dp);
}

// Tabulation Approach ------------------------------------------

int countWays(int N, string S)
{
    vector<vector<vector<int>>> dp(N, vector<vector<int>>(N, vector<int>(2)));

    for (int i = N - 1; i >= 0; i--)
    {
        for (int j = 0; j < N; j++)
        {
            for (int isTrue = 0; isTrue <= 1; isTrue++)
            {
                if (i == j)
                {
                    if (isTrue)
                        dp[i][j][isTrue] = (S[i] == 'T');
                    else
                        dp[i][j][isTrue] = (S[i] == 'F');
                }
                else
                {
                    int totalWays = 0;

                    for (int k = i + 1; k <= j - 1; k += 2) // look carefully, it's k += 2
                    {
                        int leftTrue = dp[i][k - 1][1],
                            leftFalse = dp[i][k - 1][0],
                            rightTrue = dp[k + 1][j][1],
                            rightFalse = dp[k + 1][j][0];

                        if (S[k] == '&')
                        {
                            if (isTrue)
                                totalWays += leftTrue * rightTrue;
                            else
                                totalWays += (leftTrue * rightFalse) + (leftFalse * rightTrue) + (leftFalse * rightFalse);
                        }
                        else if (S[k] == '|')
                        {
                            if (isTrue)
                                totalWays += (leftTrue * rightTrue) + (leftTrue * rightFalse) + (leftFalse * rightTrue);
                            else
                                totalWays += leftFalse * rightFalse;
                        }
                        else // S[k] == '^'
                        {
                            if (isTrue)
                                totalWays += (rightTrue * leftFalse) + (rightFalse * leftTrue);
                            else
                                totalWays += (rightTrue * leftTrue) + (rightFalse * leftFalse);
                        }
                    }

                    dp[i][j][isTrue] = totalWays;
                }
            }
        }
    }

    return dp[0][N - 1][1];
}

//
//
//
//
//
//
//
//
//
//
//
// Memoization approach with mod 1003 for gfg
class Solution
{
    int mod = 1e3 + 3; // 1003

public:
    int mem(int i, int j, bool isTrue, const string &S, vector<vector<vector<int>>> &dp)
    {
        if (i > j)
            return 0;
        else if (i == j)
            return (isTrue) ? S[i] == 'T' : S[i] == 'F';

        if (dp[i][j][isTrue] != -1)
            return dp[i][j][isTrue];

        int ans = 0;

        for (int k = i + 1; k <= j - 1; k += 2)
        {
            int leftTrue = mem(i, k - 1, 1, S, dp);
            int leftFalse = mem(i, k - 1, 0, S, dp);
            int rightTrue = mem(k + 1, j, 1, S, dp);
            int rightFalse = mem(k + 1, j, 0, S, dp);

            if (S[k] == '&')
            {
                if (isTrue)
                    ans = (ans + (leftTrue * rightTrue) % mod) % mod;
                else
                    ans = (ans + (leftTrue * rightFalse) % mod + (rightTrue * leftFalse) % mod + (leftFalse * rightFalse) % mod) % mod;
            }
            else if (S[k] == '|')
            {
                if (isTrue)
                    ans = (ans + (leftTrue * rightFalse) % mod + (rightTrue * leftFalse) % mod + (leftTrue * rightTrue) % mod) % mod;
                else
                    ans = (ans + (leftFalse * rightFalse) % mod) % mod;
            }
            else
            {
                // else for xor
                if (isTrue)
                    ans = (ans + (leftTrue * rightFalse) % mod + (rightTrue * leftFalse) % mod) % mod;
                else
                    ans = (ans + (leftTrue * rightTrue) % mod + (leftFalse * rightFalse) % mod) % mod;
            }
        }

        return dp[i][j][isTrue] = ans;
    }
    int countWays(int N, string S)
    {
        vector<vector<vector<int>>> dp(N, vector<vector<int>>(N, vector<int>(2, -1)));
        return mem(0, N - 1, 1, S, dp);
    }
};