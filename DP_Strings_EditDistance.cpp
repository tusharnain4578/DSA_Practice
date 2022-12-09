// LC Hard
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// practice --> https://leetcode.com/problems/edit-distance/

// Please revise in this order
// Recursion -> Memoization -> Tabulation -> Space Optimization

//
// Approaches ->

// Recursive Approach ------------------------------------------

int rec(string &s1, string &s2, int i, int j)
{
    // base case
    if (i < 0)
        return j + 1;
    if (j < 0)
        return i + 1;

    if (s1[i] == s2[j])
        return 0 + rec(s1, s2, i - 1, j - 1); // 0, because no operations required

    // else
    // different cases // + 1, because 1 operation applying
    int insertion = 1 + rec(s1, s2, i, j - 1);
    int deletion = 1 + rec(s1, s2, i - 1, j);
    int replace = 1 + rec(s1, s2, i - 1, j - 1);

    return min({insertion, deletion, replace});
}

int minDistance_rec(string word1, string word2)
{
    int m = word1.size(), n = word2.size();

    return rec(word1, word2, m - 1, n - 1);
}

// Memoized Approach ------------------------------------------

int mem(string &s1, string &s2, int i, int j, vector<vector<int>> &dp)
{
    // base case
    if (i < 0)
        return j + 1;
    if (j < 0)
        return i + 1;

    if (dp[i][j] != 0)
        return dp[i][j];

    if (s1[i] == s2[j])
        return 0 + mem(s1, s2, i - 1, j - 1, dp);

    int insertion = 1 + mem(s1, s2, i, j - 1, dp);
    int deletion = 1 + mem(s1, s2, i - 1, j, dp);
    int replace = 1 + mem(s1, s2, i - 1, j - 1, dp);

    return dp[i][j] = min({insertion, deletion, replace});
}

int minDistance_mem(string word1, string word2)
{
    int m = word1.size(), n = word2.size();

    vector<vector<int>> dp(m, vector<int>(n, -1)); // dp

    return mem(word1, word2, m - 1, n - 1, dp);
}

// Tabulated Approach ------------------------------------------

int minDistance_tabulated(string word1, string word2)
{
    int m = word1.size(), n = word2.size();

    vector<vector<int>> dp(m + 1, vector<int>(n + 1)); // dp

    // base case

    for (int i = 0; i <= n; i++)
        dp[0][i] = i; // using i, instead of i+1, because here we are using 1 based indexing

    for (int j = 0; j <= m; j++)
        dp[j][0] = j; // using j, instead of j+1, because here we are using 1 based indexing

    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (word1[i - 1] == word2[j - 1])
            {
                dp[i][j] = 0 + dp[i - 1][j - 1];
            }
            else
            {
                int insertion = 1 + dp[i][j - 1];
                int deletion = 1 + dp[i - 1][j];
                int replace = 1 + dp[i - 1][j - 1];

                dp[i][j] = min({insertion, deletion, replace});
            }
        }
    }

    return dp[m][n];
}

// Space Optimized Approach ------------------------------------------

int minDistance(string word1, string word2)
{
    int m = word1.size(), n = word2.size();

    vector<int> dp(n + 1); // dp

    // base case

    for (int i = 0; i <= n; i++)
        dp[i] = i; // using i, instead of i+1, because here we are using 1 based indexing

    for (int i = 1; i <= m; i++)
    {
        vector<int> temp(n + 1);
        temp[0] = i;
        for (int j = 1; j <= n; j++)
        {
            if (word1[i - 1] == word2[j - 1])
            {
                temp[j] = 0 + dp[j - 1];
            }
            else
            {
                int insertion = 1 + temp[j - 1];
                int deletion = 1 + dp[j];
                int replace = 1 + dp[j - 1];

                temp[j] = min({insertion, deletion, replace});
            }
        }
        dp = temp;
    }

    return dp[n];
}