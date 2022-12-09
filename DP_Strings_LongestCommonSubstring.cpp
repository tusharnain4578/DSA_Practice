#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// // returns the length of longest common substring ---->

// recursion //this will give tle (you know it), no need to memoize, i tried too messy code, just make a 2d matrix dp, you can easily fill it, try it
// btw that 2d dp tabulation approach is mentioned below this recrusion method
int rec(const string &s1, const string &s2, int i, int j, int count)
{
    if (i < 0 or j < 0)
        return count;

    if (s1[i] == s2[j])
        return rec(s1, s2, i - 1, j - 1, count + 1);

    // in the below recursion call, we are resetting count to zero, because this one case didnt match, so will find new one from the next call
    return max({count, rec(s1, s2, i - 1, j, 0), rec(s1, s2, i, j - 1, 0)});
}

int longestCommonSubstr(string S1, string S2, int n, int m)
{
    return rec(S1, S2, n - 1, m - 1, 0);
}

// Tabulation
int longestCommonSubstr(string s1, string s2, int m, int n)
{
    vector<vector<int>> dp(m, vector<int>(n));
    int ans = 0;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (s1[i] == s2[j])
            {
                dp[i][j] = (i - 1 < 0 or j - 1 < 0) ? 1 : 1 + dp[i - 1][j - 1];
                ans = max(ans, dp[i][j]);
            }
            else
            {
                dp[i][j] = 0;
            }
        }
    }

    return ans;
}

// Space Optimized
int longestCommonSubstr(string s1, string s2, int m, int n)
{
    vector<int> dp(n);
    int ans = 0;
    for (int i = 0; i < m; i++)
    {
        vector<int> temp(n);
        for (int j = 0; j < n; j++)
        {
            if (s1[i] == s2[j])
            {
                temp[j] = (i - 1 < 0 or j - 1 < 0) ? 1 : 1 + dp[j - 1];
                ans = max(ans, temp[j]);
            }
            else
            {
                temp[j] = 0;
            }
        }
        dp = temp;
    }

    return ans;
}

//
//
//
//
//
// prints the longest common substring ---->

string reverse(string s)
{
    int low = 0, high = s.size() - 1;

    while (low < high)
    {
        swap(s[low++], s[high--]);
    }
    return s;
}

// Tabulation
int longestCommonSubstr(string s1, string s2, int m, int n)
{
    vector<vector<int>> dp(m, vector<int>(n));
    int ans = 0;
    pair<int, int> end; // for ending point of longest substring
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (s1[i] == s2[j])
            {
                dp[i][j] = (i - 1 < 0 or j - 1 < 0) ? 1 : 1 + dp[i - 1][j - 1];
                // ans = max(ans, dp[i][j]);
                if (dp[i][j] > ans)
                {
                    ans = dp[i][j];

                    // setting end points
                    end.first = i;
                    end.second = j;
                }
            }
            else
            {
                dp[i][j] = 0;
            }
        }
    }

    int i = end.first, j = end.second;
    string lcs = ""; // longest common substring
    while (i >= 0 and j >= 0 and dp[i][j] != 0)
    {
        lcs += s1[i]; // or you can also take s2[j] //they're same
        i--, j--;
    }
    cout << reverse(lcs) << endl;

    return ans;
}