#include <iostream>
#include <vector>
using namespace std;
// practice ---> https://practice.geeksforgeeks.org/problems/word-wrap1646/1

// recursion

int rec(int index, int remLen, const int &maxLen, const vector<int> &nums, const int &n)
{
    if (index == n)
        return 0;

    int currWordLen = nums[index];

    if (currWordLen < remLen)
    {
        // putting the word on the current line, so we dont have to pay any cost value here
        int placing_word_on_current_line = 0 + rec(index + 1, remLen == maxLen ? remLen - currWordLen : remLen - currWordLen - 1, maxLen, nums, n);

        // putting the word on the next line, so we have to pay the cost for remaing length here

        int placing_word_on_next_line = (remLen * remLen) + rec(index + 1, maxLen - currWordLen, maxLen, nums, n);

        return min(placing_word_on_current_line, placing_word_on_next_line);
    }
    // else
    //  can't place it on current, so we have only 1 option, i.e, to place it in next line, so here we go

    return (remLen * remLen) + rec(index + 1, maxLen - currWordLen, maxLen, nums, n);
}
int solveWordWrap(vector<int> nums, int k)
{
    int n = nums.size();
    return rec(0, k, k, nums, n);
}

//
//
//
// memoization
int mem(int index, int remLen, const int &maxLen, const vector<int> &nums, const int &n, vector<vector<int>> &dp)
{
    if (index == n)
        return 0;

    if (dp[index][remLen] != -1)
        return dp[index][remLen];

    int currWordLen = nums[index];

    if (currWordLen < remLen)
    {
        int placing_word_on_current_line = 0 + mem(index + 1, remLen == maxLen ? remLen - currWordLen : remLen - currWordLen - 1, maxLen, nums, n, dp);

        int placing_word_on_next_line = (remLen * remLen) + mem(index + 1, maxLen - currWordLen, maxLen, nums, n, dp);

        return dp[index][remLen] = min(placing_word_on_current_line, placing_word_on_next_line);
    }

    return dp[index][remLen] = (remLen * remLen) + mem(index + 1, maxLen - currWordLen, maxLen, nums, n, dp);
}
int solveWordWrap(vector<int> nums, int k)
{
    int n = nums.size();

    vector<vector<int>> dp(n, vector<int>(k + 1, -1)); // 2D DP

    return mem(0, k, k, nums, n, dp);
}

//
//
//
// tabulation

int solveWordWrap(vector<int> nums, int k)
{
    int n = nums.size();
    int &maxLen = k; // ehh

    vector<vector<int>> dp(n + 1, vector<int>(k + 1));

    // base case
    for (int i = 0; i <= k; i++)
        dp[n][i] = 0;

    for (int index = n - 1; index >= 0; index--)
    {
        for (int remLen = 0; remLen <= k; remLen++)
        {
            int currWordLen = nums[index];

            if (currWordLen < remLen)
            {
                int placing_word_on_current_line = 0 + dp[index + 1][remLen == maxLen ? remLen - currWordLen : remLen - currWordLen - 1];

                int placing_word_on_next_line = (remLen * remLen) + dp[index + 1][maxLen - currWordLen];

                dp[index][remLen] = min(placing_word_on_current_line, placing_word_on_next_line);
            }
            else
            {
                dp[index][remLen] = (remLen * remLen) + dp[index + 1][maxLen - currWordLen];
            }
        }
    }

    return dp[0][k];
}

//
//
//
// Space Optimization

int solveWordWrap(vector<int> nums, int k)
{
    int n = nums.size();
    int &maxLen = k; // ehh

    vector<int> dp(k + 1, 0);

    for (int index = n - 1; index >= 0; index--)
    {
        vector<int> temp(k + 1);

        for (int remLen = 0; remLen <= k; remLen++)
        {
            int currWordLen = nums[index];

            if (currWordLen < remLen)
            {
                int placing_word_on_current_line = 0 + dp[remLen == maxLen ? remLen - currWordLen : remLen - currWordLen - 1];

                int placing_word_on_next_line = (remLen * remLen) + dp[maxLen - currWordLen];

                temp[remLen] = min(placing_word_on_current_line, placing_word_on_next_line);
            }
            else
            {
                temp[remLen] = (remLen * remLen) + dp[maxLen - currWordLen];
            }
        }

        dp = temp;
    }

    return dp[k];
}