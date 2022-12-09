#include <iostream>
#include <vector>
using namespace std;
// practice ---> https://leetcode.com/problems/perfect-squares/

// recursion
int rec(int n)
{
    if (n == 0)
        return 0;

    int ans = n;

    for (int i = 1; i * i <= n; i++)
        ans = min(ans, 1 + rec(n - (i * i)));

    return ans;
}

int numSquares(int n)
{
    return rec(n);
}

// memoization
int mem(int n, vector<int> &dp)
{
    if (n == 0)
        return 0;

    if (dp[n] != -1)
        return dp[n];

    int ans = n;

    for (int i = 1; i * i <= n; i++)
        ans = min(ans, 1 + mem(n - (i * i), dp));

    return dp[n] = ans;
}

int numSquares(int n)
{
    vector<int> dp(n + 1, -1);
    return mem(n, dp);
}

// tabulation
int numSquares(int n)
{
    vector<int> dp(n + 1);

    dp[0] = 0;

    for (int nn = 1; nn <= n; nn++)
    {
        int ans = nn;

        for (int i = 1; i * i <= nn; i++)
            ans = min(ans, 1 + dp[nn - (i * i)]);

        dp[nn] = ans;
    }

    return dp[n];
}