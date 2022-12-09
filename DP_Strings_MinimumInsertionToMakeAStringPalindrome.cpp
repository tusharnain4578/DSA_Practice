#include <iostream>
#include <vector>
using namespace std;

//********** Longest Palindromic Subseq *************
string reverse(string s)
{
    int low = 0, high = s.size() - 1;

    while (low < high)
    {
        swap(s[low++], s[high--]);
    }
    return s;
}

int lcs(string s1, string s2)
{
    int m = s1.size(), n = s2.size();

    vector<int> dp(n);

    for (int i = 0; i < m; i++)
    {
        vector<int> temp(n);
        for (int j = 0; j < n; j++)
        {
            if (s1[i] == s2[j])
            {
                temp[j] = (i - 1 < 0 or j - 1 < 0) ? 1 : 1 + dp[j - 1];
            }
            else
            {
                temp[j] = max((i - 1 < 0) ? 0 : dp[j], (j - 1 < 0) ? 0 : temp[j - 1]);
            }
        }
        dp = temp;
    }
    return dp[n - 1];
}

int longestPalindromeSubseq(string s)
{
    return lcs(s, reverse(s));
}
//********** Longest Palindromic Subseq *************

// Minimum Insertion to make a string palindrome
int countMin(string str)
{
    return str.size() - longestPalindromeSubseq(str);
}