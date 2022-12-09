#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// practice --> https://leetcode.com/problems/burst-balloons/

// Please revise in this order
// Recursion -> Memoization -> Tabulation -> Space Optimization

//
//
// Approaches ->

// Recursive Approach ------------------------------------------

int rec(int i, int j, vector<int> &nums)
{
    if (i > j)
        return 0;

    int max_coins = INT_MIN;
    for (int k = i; k <= j; k++)
    {
        int coins = nums[i - 1] * nums[k] * nums[j + 1] + rec(i, k - 1, nums) + rec(k + 1, j, nums);
        max_coins = max(max_coins, coins);
    }

    return max_coins;
}

int maxCoins(vector<int> &nums)
{
    int n = nums.size();

    nums.insert(nums.begin(), 1);
    nums.push_back(1);

    return rec(1, n, nums);
}

// Memoized Approach ------------------------------------------

int mem(int i, int j, vector<int> &nums, vector<vector<int>> &dp)
{
    if (i > j)
        return 0;

    if (dp[i][j] != -1)
        return dp[i][j];

    int max_coins = INT_MIN;
    for (int k = i; k <= j; k++)
    {
        int coins = nums[i - 1] * nums[k] * nums[j + 1] + mem(i, k - 1, nums, dp) + mem(k + 1, j, nums, dp);
        max_coins = max(max_coins, coins);
    }

    return dp[i][j] = max_coins;
}

int maxCoins(vector<int> &nums)
{
    int n = nums.size();

    nums.insert(nums.begin(), 1);
    nums.push_back(1);

    vector<vector<int>> dp(n + 1, vector<int>(n + 1, -1)); // dp

    return mem(1, n, nums, dp);
}

// Tabulation Approach ------------------------------------------

int maxCoins(vector<int> &nums)
{
    int n = nums.size();

    nums.insert(nums.begin(), 1);
    nums.push_back(1);

    vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0)); // dp

    for (int i = n; i >= 1; i--)
    {
        for (int j = 1; j <= n; j++)
        {
            if (i > j)
                continue;

            int max_coins = INT_MIN;
            for (int k = i; k <= j; k++)
            {
                int coins = nums[i - 1] * nums[k] * nums[j + 1] + dp[i][k - 1] + dp[k + 1][j];
                max_coins = max(max_coins, coins);
            }

            dp[i][j] = max_coins;
        }
    }

    return dp[1][n];
}