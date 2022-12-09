#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
// practice ---> https://practice.geeksforgeeks.org/problems/cutted-segments1642/1

// reference --> https://www.youtube.com/watch?v=O0N4xn38Ncg

// recursion
int rec(int n, int &x, int &y, int &z)
{
    if (n == 0)
    {
        return 0;
    }

    int cut1_segment = x <= n ? 1 + rec(n - x, x, y, z) : INT_MIN;
    int cut2_segment = y <= n ? 1 + rec(n - y, x, y, z) : INT_MIN;
    int cut3_segment = z <= n ? 1 + rec(n - z, x, y, z) : INT_MIN;

    int maxCutSegments = max({cut1_segment, cut2_segment, cut3_segment});

    return maxCutSegments;
}
int maximizeTheCuts(int n, int x, int y, int z)
{
    int ans = rec(n, x, y, z);

    return ans > 0 ? ans : 0;
}

// Memoization
int mem(int n, int &x, int &y, int &z, vector<int> &dp)
{
    if (n == 0)
    {
        return 0;
    }

    if (dp[n] != -1)
        return dp[n];

    int cut1_segment = x <= n ? 1 + mem(n - x, x, y, z, dp) : INT_MIN;
    int cut2_segment = y <= n ? 1 + mem(n - y, x, y, z, dp) : INT_MIN;
    int cut3_segment = z <= n ? 1 + mem(n - z, x, y, z, dp) : INT_MIN;

    int maxCutSegments = max({cut1_segment, cut2_segment, cut3_segment});

    return dp[n] = maxCutSegments;
}
int maximizeTheCuts(int n, int x, int y, int z)
{
    vector<int> dp(n + 1, -1);
    int ans = mem(n, x, y, z, dp);

    return ans > 0 ? ans : 0;
}

// Tabulation
int maximizeTheCuts(int n, int x, int y, int z)
{
    vector<int> dp(n + 1);

    dp[0] = 0;

    for (int i = 1; i <= n; i++)
    {
        int cut1_segment = x <= i ? 1 + dp[i - x] : INT_MIN;
        int cut2_segment = y <= i ? 1 + dp[i - y] : INT_MIN;
        int cut3_segment = z <= i ? 1 + dp[i - z] : INT_MIN;

        int maxCutSegments = max({cut1_segment, cut2_segment, cut3_segment});

        dp[i] = maxCutSegments;
    }

    int ans = dp[n];

    return ans > 0 ? ans : 0;
}