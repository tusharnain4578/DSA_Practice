#include <iostream>
#include <vector>
using namespace std;
// practice ---> https://practice.geeksforgeeks.org/problems/nth-catalan-number0817/1

// The best(optimized) approach is the one where we use the binomial coefficient method
// The approach is given in the bottom of this file (last function)

// recursive approach
int findCatalan(int n)
{
    if (n == 0 or n == 1)
        return 1;

    int ans = 0;

    for (int i = 0; i < n; i++)
        ans += findCatalan(i) * findCatalan(n - i - 1);

    return ans;
}

// memoization approach
int mem(int n, vector<int> &dp)
{
    if (n == 0 or n == 1)
        return 1;

    if (dp[n] != -1)
        return dp[n];

    int ans = 0;

    for (int i = 0; i < n; i++)
        ans += mem(i, dp) * mem(n - i - 1, dp);

    return dp[n] = ans;
}

int findCatalan_mem(int n)
{
    vector<int> dp(n + 1, -1);

    return mem(n, dp);
}

// tabulation approach
int findCatalan_tab(int n)
{
    vector<int> dp(n + 1);

    dp[0] = dp[1] = 1;

    // for i loop is for the dp loop you know, for handling recursion
    // and the inside loop is the loop we use for collection the solution
    for (int i = 2; i <= n; i++)
    {
        for (int j = 0; j < i; j++)
            dp[i] += dp[j] * dp[i - 1 - j];
    }

    return dp[n];
}

// It can not be more optimized (in dynamic programming), you can see why

// ncr
int binomialCoeff(unsigned int n, unsigned int k)
{
    unsigned long int res = 1;

    // Since C(n, k) = C(n, n-k)
    if (k > n - k)
        k = n - k;

    // Calculate value of [n*(n-1)*---*(n-k+1)] / [k*(k-1)*---*1]
    for (int i = 0; i < k; ++i)
    {
        res *= (n - i);
        res /= (i + 1);
    }

    return res;
}

int findCatalan(int n)
{
    // nth catalan number mathematical formula --> https://www.youtube.com/watch?v=CMaZ69P1bAc&t=905s

    return binomialCoeff(2 * n, n) / (n + 1);
}