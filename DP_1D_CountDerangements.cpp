#include <iostream>
#include <vector>
using namespace std;
// practice ---> https://practice.geeksforgeeks.org/problems/dearrangement-of-balls0918/1

// reference --> https://www.youtube.com/watch?v=NW-BLDQHFXk

// recursion
long int rec(int n)
{
    if (n == 1)
        return 0;
    if (n == 2)
        return 1;

    // (n-1) * f(n-2) + (n-1) * f(n-1)
    return (n - 1) * (rec(n - 2) + rec(n - 1));
}

long int disarrange(int N)
{
    return rec(N);
}

// memoization
long int mem(int n, vector<long int> &dp)
{
    if (n == 1)
        return 0;
    if (n == 2)
        return 1;

    if (dp[n] != -1)
        return dp[n];

    // (n-1) * f(n-2) + (n-1) * f(n-1)
    return dp[n] = (n - 1) * (mem(n - 2, dp) + mem(n - 1, dp));
}

long int disarrange(int N)
{
    vector<long int> dp(N + 1, -1);

    return mem(N, dp);
}

// tabulation
long int disarrange(int N)
{
    vector<long int> dp(N + 1);
    dp[1] = 0, dp[2] = 1;

    for (int n = 3; n <= N; n++)
        dp[n] = (n - 1) * (dp[n - 2] + dp[n - 1]);

    return dp[N];
}

// Space Optimized -> 3 variables
long int disarrange(int N)
{
    long int a = 0, b = 1, curr;

    for (int n = 3; n <= N; n++)
    {
        curr = (n - 1) * (a + b);

        a = b;
        b = curr;
    }

    return b; // or curr
}

// cannot be optimized more ig