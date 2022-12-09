#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// For returning length of Shortest common supersequence
int shortestCommonSupersequence_length(string text1, string text2, int m, int n)
{
    vector<int> dp(n); // dp

    for (int index1 = 0; index1 < m; index1++)
    {
        vector<int> temp(n);

        for (int index2 = 0; index2 < n; index2++)
        {
            if (text1[index1] == text2[index2])
                temp[index2] = (index1 - 1 < 0 or index2 - 1 < 0) ? 1 + 0 : 1 + dp[index2 - 1];
            else
                temp[index2] = 0 + max((index1 - 1 < 0) ? 0 : dp[index2], (index2 - 1 < 0) ? 0 : temp[index2 - 1]);
        }

        dp = temp;
    }
    int lcs = dp[n - 1];

    // size of string1 + size of string2 - their lcs
    return m + n - lcs;
}

// For printing Shortest Common Supersequence
string shortestCommonSupersequence_string(string text1, string text2, int m, int n)
{
    string ans = "";

    vector<vector<int>> dp(m, vector<int>(n)); // dp

    for (int index1 = 0; index1 < m; index1++)
    {
        for (int index2 = 0; index2 < n; index2++)
        {
            if (text1[index1] == text2[index2])
                dp[index1][index2] = (index1 - 1 < 0 or index2 - 1 < 0) ? 1 + 0 : 1 + dp[index1 - 1][index2 - 1];
            else
                dp[index1][index2] = 0 + max((index1 - 1 < 0) ? 0 : dp[index1 - 1][index2], (index2 - 1 < 0) ? 0 : dp[index1][index2 - 1]);
        }
    }

    int i = m - 1, j = n - 1;

    while (i >= 0 and j >= 0)
    {
        if (text1[i] == text2[j])
        {
            ans += text1[i];
            i--, j--;
        }
        else
        {
            int up = i - 1 < 0 ? 0 : dp[i - 1][j];
            int left = j - 1 < 0 ? 0 : dp[i][j - 1];

            if (up > left)
            {
                ans += text1[i];
                i--;
            }
            else
            {
                ans += text2[j];
                j--;
            }
        }
    }

    while (i >= 0)
    {
        ans += text1[i];
        i--;
    }

    while (j >= 0)
    {
        ans += text2[j];
        j--;
    }

    reverse(ans.begin(), ans.end());

    return ans;
}

int main()
{
    string a = "brute", b = "groot";
    cout << shortestCommonSupersequence_string(a, b, 5, 5);

    return 0;
}