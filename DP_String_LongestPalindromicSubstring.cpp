#include <iostream>
#include <vector>
using namespace std;
// practice ---> https://leetcode.com/problems/longest-palindromic-substring/

// by using the space optimized approach from Count Palindromic Substring

// but there is a better approach than this in the string section which uses the odd/even approach (that approach is way faster than this, and uses no extra space)

string longestPalindrome(string s)
{
    int n = s.size();

    vector<int> dp(n);

    int lps_start = 0, lps_end = 0;

    for (int i = n - 1; i >= 0; i--)
    {
        vector<int> temp(n);

        for (int j = i; j < n; j++)
        {
            if (i == j)
                temp[j] = true;
            else if (i + 1 == j)
                temp[j] = s[i] == s[j] ? true : false;
            else
            {
                if (s[i] == s[j])
                    temp[j] = dp[j - 1];
                else
                    temp[j] = false;
            }

            if (temp[j])
                if (j - i + 1 > lps_end - lps_start + 1)
                    lps_start = i, lps_end = j;
        }

        dp = temp;
    }

    return s.substr(lps_start, lps_end - lps_start + 1);
}