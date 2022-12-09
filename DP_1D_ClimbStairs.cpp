#include <iostream>
#include <vector>
using namespace std;
// Please revise in this order
// Recursion -> Memoization -> Tabulation -> Space Optimization

// practice --> https://leetcode.com/problems/climbing-stairs/

//  Only recursion
int climbStairs_Recursion(int n)
{
    if (n == 0)
        return 1;

    if (n < 0)
        return 0;

    return climbStairs_Recursion(n - 1) + climbStairs_Recursion(n - 2);
}

// Memoized approach
int climbStairs_Memoized(int n, vector<int> &dp)
{
    if (n == 0)
        return 1;

    if (n < 0)
        return 0;

    if (dp[n] != -1)
        return dp[n];

    return dp[n] = climbStairs_Memoized(n - 1, dp) + climbStairs_Memoized(n - 2, dp);
}

// Tabulated approach
int climbStairs_Tabulated(int n)
{
    vector<int> v(n + 1);

    v[0] = v[1] = 1; // base cases

    for (int i = 2; i <= n; i++)
    {
        v[i] = v[i - 1] + v[i - 2];
    }

    return v[n];
}

// Space Optimized approach
int climbStairs_SpaceOptimized(int n)
{
    int prev1, prev2;
    prev1 = prev2 = 1;
    int curr = 1;
    for (int i = 2; i <= n; i++)
    {
        curr = prev1 + prev2;
        prev1 = prev2;
        prev2 = curr;
    }

    return curr;
}

int main()
{
    int n = 3;
    vector<int> dp(n + 1, -1);

    int ans = climbStairs_Memoized(n, dp);

    cout << ans << endl;

    return 0;
}