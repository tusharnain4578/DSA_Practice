#include <iostream>
#include <vector>
using namespace std;
// Please revise in this order
// Recursion -> Memoization -> Tabulation -> Space Optimization

// practice --> https://www.codingninjas.com/codestudio/problems/frog-jump_3621012
// .
// .
// Approaches ->
// Recursive Approach - - - - - - - - - - - - - - - - -
int rec(int index, vector<int> &heights)
{
    if (index == 0)
        return 0;

    int one_step = rec(index - 1, heights) + abs(heights[index] - heights[index - 1]);

    int two_step = INT_MAX;

    if (index > 1)
        two_step = rec(index - 2, heights) + abs(heights[index] - heights[index - 2]);

    return min(one_step, two_step);
}

int frogJump1(int n, vector<int> &heights)
{
    return rec(n - 1, heights);
}

// Memoized Approach - - - - - - - - - - - - - - - - -

int rec_Memoized(int index, vector<int> &heights, vector<int> &dp)
{
    if (index == 0)
        return 0;

    if (dp[index] != -1)
        return dp[index];

    int one_step = rec_Memoized(index - 1, heights, dp) + abs(heights[index] - heights[index - 1]);

    int two_step = INT_MAX;

    if (index > 1)
        two_step = rec_Memoized(index - 2, heights, dp) + abs(heights[index] - heights[index - 2]);

    return dp[index] = min(one_step, two_step);
}

int frogJump_Memoized(int n, vector<int> &heights)
{
    vector<int> dp(n, -1);
    return rec_Memoized(n - 1, heights, dp);
}

// Tabulated Approach - - - - - - - - - - - - - - - - -
int frogJump_Tabulated(int n, vector<int> &heights)
{
    vector<int> dp(n, -1);

    dp[0] = 0; // base case

    for (int index = 1; index < n; index++)
    {
        int one_step = dp[index - 1] + abs(heights[index] - heights[index - 1]);

        int two_step = INT_MAX;
        if (index > 1)
            two_step = dp[index - 2] + abs(heights[index] - heights[index - 2]);

        dp[index] = min(one_step, two_step);
    }
    return dp[n - 1];
}

// Space Optimized Approach - - - - - - - - - - - - - - -

int frogJump_SpaceOptimized(int n, vector<int> &heights)
{

    int prev1 = 0;
    int prev2 = 0;
    int curr = 0;
    for (int index = 1; index < n; index++)
    {
        int one_step = prev1 + abs(heights[index] - heights[index - 1]);

        int two_step = INT_MAX;
        if (index > 1)
            two_step = prev2 + abs(heights[index] - heights[index - 2]);

        curr = min(one_step, two_step);

        prev2 = prev1;
        prev1 = curr;
    }
    return curr;
}