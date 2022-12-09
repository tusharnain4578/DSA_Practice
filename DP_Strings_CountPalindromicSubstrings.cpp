#include <iostream>
#include <vector>
using namespace std;
// practice ---> https://leetcode.com/problems/palindromic-substrings/

// reference --> gfg article

// the gfg is not accepting single charater as a palindroem, idk why
// so in the for loop you just have to start the j counter from i+1, that's all

// There is solution in the string section which is way faster than this

// recursion
bool rec(const string &s, int i, int j)
{
    if (i > j)
        return true;

    if (s[i] == s[j])
        return rec(s, i + 1, j - 1);

    return false;
}

int countSubstrings(string s)
{
    int n = s.size();

    int count = 0;

    for (int i = 0; i < n; i++)
        for (int j = i; j < n; j++)
            if (rec(s, i, j))
                count++;

    return count;
}
//
//
// memoization
bool mem(const string &s, int i, int j, vector<vector<int>> &dp)
{
    if (i > j)
        return true;

    if (dp[i][j] != -1)
        return dp[i][j];

    if (s[i] == s[j])
        return dp[i][j] = mem(s, i + 1, j - 1, dp);

    return dp[i][j] = false;
}

int countSubstrings(string s)
{
    int n = s.size();

    int count = 0;

    vector<vector<int>> dp(n, vector<int>(n, -1));

    for (int i = 0; i < n; i++)
        for (int j = i; j < n; j++)
            if (mem(s, i, j, dp))
                count++;

    return count;
}
//
//
// tabulation
int countSubstrings(string s)
{
    int n = s.size();

    int count = 0;

    vector<vector<int>> dp(n, vector<int>(n));

    for (int i = n - 1; i >= 0; i--)
    {
        for (int j = i; j < n; j++)
        {
            if (i == j) // for single character //base case ya' know
                dp[i][j] = true;
            else if (i + 1 == j) // for 2 size string //kinda like base case
                dp[i][j] = s[i] == s[j] ? true : false;
            else
            {
                if (s[i] == s[j])
                    dp[i][j] = dp[i + 1][j - 1];
                else
                    dp[i][j] = false;
            }

            count += dp[i][j];
        }
    }

    return count;
}

// space optimized
int countSubstrings(string s)
{
    int n = s.size();

    int count = 0;

    vector<int> dp(n);

    for (int i = n - 1; i >= 0; i--)
    {
        vector<int> temp(n);

        for (int j = i; j < n; j++)
        {
            if (i == j) // for single character //base case ya' know
                temp[j] = true;
            else if (i + 1 == j) // for 2 size string //kinda like base case
                temp[j] = s[i] == s[j] ? true : false;
            else
            {
                if (s[i] == s[j])
                    temp[j] = dp[j - 1];
                else
                    temp[j] = false;
            }

            count += temp[j];
        }

        dp = temp;
    }

    return count;
}