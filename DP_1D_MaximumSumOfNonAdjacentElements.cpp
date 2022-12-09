#include <iostream>
#include <vector>
using namespace std;
// practice --> https://www.codingninjas.com/codestudio/problems/maximum-sum-of-non-adjacent-elements_843261

// Please revise in this order
// Recursion -> Memoization -> Tabulation -> Space Optimization

//
//
// Approaches ->
// Recursive Approach ------------------------------------------

int rec(int index, vector<int> &nums)
{
    if (index == 0)
        return nums[0]; // or return nums[index] -> same thing

    if (index < 0)
        return 0;

    int pick = nums[index] + rec(index - 2, nums);
    int non_pick = rec(index - 1, nums);

    return max(pick, non_pick);
}

int maximumNonAdjacentSum(vector<int> &nums)
{
    return rec(nums.size() - 1, nums);
}

// Memoized Approach ------------------------------------------

int rec_Memoized(int index, vector<int> &nums, vector<int> &dp)
{
    if (index == 0)
    {
        return nums[0]; // or return nums[index] -> same thing
    }
    if (index < 0)
    {
        return 0;
    }

    if (dp[index] != -1)
        return dp[index];

    int pick = nums[index] + rec_Memoized(index - 2, nums, dp);
    int non_pick = rec_Memoized(index - 1, nums, dp);

    return dp[index] = max(pick, non_pick);
}

int maximumNonAdjacentSum_Memoized(vector<int> &nums)
{
    vector<int> dp(nums.size(), -1);
    return rec_Memoized(nums.size() - 1, nums, dp);
}

// Tabulated Approach ------------------------------------------

int maximumNonAdjacentSum_Tabulated(vector<int> &nums)
{
    int n = nums.size();

    vector<int> dp(n);
    dp[0] = nums[0];

    for (int index = 1; index < n; index++)
    {
        int pick = nums[index];

        if (index > 1)
            pick += dp[index - 2];

        int non_pick = dp[index - 1];

        dp[index] = max(pick, non_pick);
    }
    return dp[n - 1];
}

// Space Optimized Approach ------------------------------------------

int maximumNonAdjacentSum_SpaceOptimized(vector<int> &nums)
{
    int n = nums.size();

    int prev1 = nums[0];
    int prev2 = 0;
    int curr = 0;
    for (int index = 1; index < n; index++)
    {
        int pick = nums[index];

        if (index > 1)
            pick += prev2;

        int non_pick = prev1;

        curr = max(pick, non_pick);

        prev2 = prev1;
        prev1 = curr;
    }
    return prev1;
}