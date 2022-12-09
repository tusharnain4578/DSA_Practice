#include <iostream>
#include <vector>
using namespace std;
// practice ---> https://practice.geeksforgeeks.org/problems/count-palindromic-subsequences/1

// reference --> https://www.youtube.com/watch?v=vlbA8oUxSV0

// recursion
long long int rec(const string &str, int i, int j)
{
    if (i > j)
        return 0;

    if (i == j)
        return 1;

    if (str[i] == str[j])
        return 1 + rec(str, i + 1, j) + rec(str, i, j - 1);

    // else
    return rec(str, i + 1, j) + rec(str, i, j - 1) - rec(str, i + 1, j - 1);
}

long long int countPS(string str)
{
    int n = str.size();

    return rec(str, 0, n - 1);
}

// memoization
long long int mem(const string &str, int i, int j, vector<vector<long long int>> &dp)
{
    if (i > j)
        return 0;

    if (i == j)
        return 1;

    if (dp[i][j] != -1)
        return dp[i][j];

    if (str[i] == str[j])
        return dp[i][j] = 1 + mem(str, i + 1, j, dp) + mem(str, i, j - 1, dp);

    // else
    return dp[i][j] = mem(str, i + 1, j, dp) + mem(str, i, j - 1, dp) - mem(str, i + 1, j - 1, dp);
}

long long int countPS(string str)
{
    int n = str.size();

    vector<vector<long long int>> dp(n, vector<long long int>(n, -1));

    return mem(str, 0, n - 1, dp);
}

// tabulation

long long int countPS(string str)
{
    int n = str.size();

    vector<vector<long long int>> dp(n, vector<long long int>(n));

    for (int i = n - 1; i >= 0; i--)
    {
        for (int j = 0; j < n; j++)
        {
            if (i > j)
                dp[i][j] = 0;
            else if (i == j)
                dp[i][j] = 1;
            else
            {
                if (str[i] == str[j])
                    dp[i][j] = 1 + dp[i + 1][j] + dp[i][j - 1];
                else
                    dp[i][j] = dp[i + 1][j] + dp[i][j - 1] - dp[i + 1][j - 1];
            }
        }
    }

    return dp[0][n - 1];
}

// space optimization

long long int countPS(string str)
{
    int n = str.size();

    vector<long long int> dp(n);

    for (int i = n - 1; i >= 0; i--)
    {
        vector<long long int> temp(n);

        for (int j = 0; j < n; j++)
        {
            if (i > j)
                temp[j] = 0;
            else if (i == j)
                temp[j] = 1;
            else
            {
                if (str[i] == str[j])
                    temp[j] = 1 + dp[j] + temp[j - 1];
                else
                    temp[j] = dp[j] + temp[j - 1] - dp[j - 1];
            }
        }

        dp = temp;
    }

    return dp[n - 1];
}

//
//
//
//
// in gfg the solution can be large so it asks for mod 1e9+7
// here is the memoization approach with mod 1e9+7

int mod = 1e9 + 7;

long long int mem(const string &str, int i, int j, vector<vector<long long int>> &dp)
{
    if (i > j)
        return 0;

    if (i == j)
        return 1;

    if (dp[i][j] != -1)
        return dp[i][j];

    if (str[i] == str[j])
        return dp[i][j] = (1 + mem(str, i + 1, j, dp) % mod + mem(str, i, j - 1, dp) % mod) % mod;

    // else
    return dp[i][j] = (mem(str, i + 1, j, dp) % mod + mem(str, i, j - 1, dp) % mod - mem(str, i + 1, j - 1, dp) % mod + mod) % mod;
}

long long int countPS(string str)
{
    int n = str.size();

    vector<vector<long long int>> dp(n, vector<long long int>(n, -1));

    return mem(str, 0, n - 1, dp);
}

// Note (for line 145) -> Because if for (a%b) the calculated a becomes negative, you still want a positive value, so as (a+b)%b=a%b it gives the desired positive value, the Mod is analogous to b here. That's why we added mod in that