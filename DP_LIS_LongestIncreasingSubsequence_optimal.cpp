#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// practice --> https://leetcode.com/problems/longest-increasing-subsequence/

// This approach is using 1d DP

// Please revise in this order
// Recursion -> Memoization -> Tabulation -> Space Optimization

//
//
// Approaches ->

// Recursive Approach ------------------------------------------

int lis(int index, vector<int> &nums) // lis(i) will return the lis ending on index i
{
    int ans = 1;

    for (int i = 0; i < index; i++)
        if (nums[i] < nums[index])
            ans = max(ans, lis(i, nums) + 1);

    return ans;
}

int lengthOfLIS(vector<int> &nums)
{
    int n = nums.size();
    int ans = 0;

    for (int i = 0; i < n; i++)
        ans = max(ans, lis(i, nums)); // we have check lis() for every element to compare the largest lis

    return ans;
}

// Memoized Approach ------------------------------------------ O(N^2) -> time

int lis(int index, vector<int> &nums, vector<int> &dp)
{
    if (dp[index] != -1)
        return dp[index];

    int ans = 1;

    for (int i = 0; i < index; i++)
        if (nums[i] < nums[index])
            ans = max(ans, lis(i, nums, dp) + 1);

    return dp[index] = ans;
}

int lengthOfLIS(vector<int> &nums)
{
    int n = nums.size();
    vector<int> dp(n, -1);

    int ans = 0;

    for (int i = 0; i < n; i++)
        ans = max(ans, lis(i, nums, dp));

    return ans;
}

// Tabulated Approach ------------------------------------------

int lengthOfLIS(vector<int> &nums)
{
    int n = nums.size();

    vector<int> dp(n);
    dp[0] = 1; // first element will always be of size 1 lis

    for (int index = 1; index < n; index++)
    {
        int ans = 1;

        for (int i = 0; i < index; i++)
            if (nums[i] < nums[index])
                ans = max(ans, dp[i] + 1);

        dp[index] = ans;
    }

    // now, we have to return the maximum element from the dp, that will be the lis of nums array

    return *max_element(dp.begin(), dp.end());
}

// cannot be more optimized, atleast this approach