#include <iostream>
#include <vector>
using namespace std;
// practice ---> https://practice.geeksforgeeks.org/problems/longest-repeating-subsequence2004/1

// reference --> https://www.youtube.com/watch?v=He3tjOT3jac

// pre-req :- Longest Common Subsequence(LCS)

// Space Optimized algorithm of LCS, with a minor change, i.e, we're not counting two characters if with the same indexes, even if they are matching (please go through refernce)
int longestCommonSubsequence(string text1, string text2)
{
    int m = text1.size(), n = text2.size();

    vector<int> dp(n); // dp

    for (int index1 = 0; index1 < m; index1++)
    {
        vector<int> temp(n);

        for (int index2 = 0; index2 < n; index2++)
        {
            if (text1[index1] == text2[index2] and index1 != index2)
                temp[index2] = (index1 - 1 < 0 or index2 - 1 < 0) ? 1 + 0 : 1 + dp[index2 - 1];
            else
                temp[index2] = 0 + max((index1 - 1 < 0) ? 0 : dp[index2], (index2 - 1 < 0) ? 0 : temp[index2 - 1]);
        }

        dp = temp;
    }

    return dp[n - 1];
}

// Longest Repeating Subsequence (LRS)
int LongestRepeatingSubsequence(string str)
{
    return longestCommonSubsequence(str, str);
}