// LC Hard
#include <iostream>
#include <vector>
using namespace std;

// practice --> https://leetcode.com/problems/distinct-subsequences/

// Please revise in this order
// Recursion -> Memoization -> Tabulation -> Space Optimization

//
// Approaches ->

// Recursive Approach ------------------------------------------

int rec(string s, string t, int i, int j)
{
    // base case
    if (j < 0)
        return 1;

    if (i < 0)
        return 0;

    if (s[i] == t[j])
    {
        int including_this = rec(s, t, i - 1, j - 1);
        int not_including_this = rec(s, t, i - 1, j);

        return including_this + not_including_this;
    }
    else
    {
        return rec(s, t, i - 1, j);
    }
}

int numDistinct_rec(string s, string t)
{
    int m = s.size(), n = t.size();
    return rec(s, t, m - 1, n - 1);
}

// Recursive Approach ------------------------------------------

int mem(string s, string t, int i, int j, vector<vector<int>> &dp)
{
    // base case
    if (j < 0)
        return 1;

    if (i < 0)
        return 0;

    if (dp[i][j] != -1)
        return dp[i][j];

    if (s[i] == t[j])
    {
        int including_this = mem(s, t, i - 1, j - 1, dp);
        int not_including_this = mem(s, t, i - 1, j, dp);

        return dp[i][j] = including_this + not_including_this;
    }
    else
    {
        return dp[i][j] = mem(s, t, i - 1, j, dp);
    }
}

int numDistinct_mem(string s, string t)
{
    int m = s.size(), n = t.size();

    vector<vector<int>> dp(m, vector<int>(n, -1)); // dp

    return mem(s, t, m - 1, n - 1, dp);
}

// Tabulative Approach ------------------------------------------

int numDistinct_tab(string s, string t)
{
    int m = s.size(), n = t.size();

    vector<vector<long long>> dp(m + 1, vector<long long>(n + 1)); // dp

    // base case initialization
    for (int i = 0; i <= m; i++)
        dp[i][0] = 1;

    for (int i = 1; i <= n; i++)
        dp[0][i] = 0;

    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (s[i - 1] == t[j - 1])
            {

                int including_this = dp[i - 1][j - 1];
                int not_including_this = dp[i - 1][j];

                dp[i][j] = (long long)including_this + (long long)not_including_this;
            }
            else
            {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }

    return dp[m][n];
}

// Space Optimized Approach ------------------------------------------

int numDistinct_SpaceOptimized(string s, string t)
{
    int m = s.size(), n = t.size();

    vector<long long> dp(n + 1, 0); // dp

    // base case initialization
    dp[0] = 1;

    for (int i = 1; i <= m; i++)
    {
        vector<long long> temp(n + 1, 0);
        temp[0] = 1;
        for (int j = 1; j <= n; j++)
        {
            if (s[i - 1] == t[j - 1])
            {

                int including_this = dp[j - 1];
                int not_including_this = dp[j];

                temp[j] = (long long)including_this + (long long)not_including_this;
            }
            else
            {
                temp[j] = dp[j];
            }
        }
        dp = temp;
    }

    return dp[n];
}

// Single Array Space Optimized Approach ------------------------------------------

int numDistinct_SpaceOptimizedSingleArray(string s, string t)
{
    int m = s.size(), n = t.size();

    vector<long long> dp(n + 1, 0); // dp

    // base case initialization
    dp[0] = 1;

    for (int i = 1; i <= m; i++)
    {
        for (int j = n; j >= 1; j--)
        {
            if (s[i - 1] == t[j - 1])
            {

                int including_this = dp[j - 1];
                int not_including_this = dp[j];

                dp[j] = (long long)including_this + (long long)not_including_this;
            }
            else
            {
                dp[j] = dp[j];
            }
        }
    }

    return dp[n];
}