#include <iostream>
#include <vector>
using namespace std;
// practice --> https://leetcode.com/problems/jump-game-ii/

// Please revise in this order
// Recursion -> Memoization -> Tabulation -> Space Optimization

//
//
// Approaches ->

// Recursive Approach ------------------------------------------
int rec(int index, vector<int> &nums, int &n)
{
    if (index == n - 1)
        return 0;

    int min_jump = INT_MAX;

    for (int i = index + 1; i <= index + nums[index]; i++)
    {
        if (i >= n)
            break;
        min_jump = min(min_jump, 1 + rec(i, nums, n));
    }

    return min_jump;
}

int jump(vector<int> &nums)
{
    int n = nums.size();
    return rec(0, nums, n);
}

// Memoized Approach ------------------------------------------
int mem(int index, vector<int> &nums, int &n, vector<int> &dp)
{
    if (index == n - 1)
        return 0;

    if (dp[index] != -1)
        return dp[index];

    int min_jump = 1e9;

    for (int i = index + 1; i <= index + nums[index]; i++)
    {
        if (i >= n)
            break;
        min_jump = min(min_jump, 1 + mem(i, nums, n, dp));
    }

    return dp[index] = min_jump;
}

int jump(vector<int> &nums)
{
    int n = nums.size();
    vector<int> dp(n - 1, -1);
    return mem(0, nums, n, dp);
}

// Tabulated Approach ------------------------------------------
int jump(vector<int> &nums)
{
    int n = nums.size();
    vector<int> dp(n);

    dp[n - 1] = 0; // base case initialization

    for (int index = n - 2; index >= 0; index--)
    {
        int min_jump = 1e9;

        for (int i = index + 1; i <= index + nums[index]; i++)
        {
            if (i >= n)
                break;
            min_jump = min(min_jump, 1 + dp[i]);
        }

        dp[index] = min_jump;
    }
    return dp[0];
}