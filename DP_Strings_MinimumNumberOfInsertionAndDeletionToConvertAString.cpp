#include <iostream>
#include <vector>
using namespace std;
// practice gfg --> https://practice.geeksforgeeks.org/problems/minimum-number-of-deletions-and-insertions0209/1/

// practice leetcode --> https://leetcode.com/problems/delete-operation-for-two-strings/

// In the leetcode, problem statement only allows deletion, but there's no differnce, because same approach will do that too

//**************     lcs     *************************
int longestCommonSubsequence(string text1, string text2)
{
    int m = text1.size(), n = text2.size();

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

    return dp[n - 1];
}
//**************     lcs     *************************

int minOperations(string str1, string str2)
{
    int lcs = longestCommonSubsequence(str1, str2);

    return (str1.size() - lcs) + (str2.size() - lcs);
}