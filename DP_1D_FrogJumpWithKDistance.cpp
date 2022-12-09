#include <iostream>
#include <vector>
using namespace std;
// Please revise in this order
// Recursion -> Memoization -> Tabulation -> Space Optimization

// .
// .
// Approaches ->
// Recursive Approach - - - - - - - - - - - - - - - - -
int rec(int index, int k, vector<int> &heights)
{
    if (index == 0)
        return 0;

    int min_steps = INT_MAX;
    for (int i = 1; i <= k; i++)
    {
        if (index - i >= 0)
        {
            int solve = rec(index - i, k, heights) + abs(heights[index] - heights[index - i]);
            min_steps = min(min_steps, solve);
        }
    }

    return min_steps;
}

int frogJump_rec(int n, int k, vector<int> &heights)
{
    return rec(n - 1, k, heights);
}

// Memoized Approach - - - - - - - - - - - - - - - - -
int rec_Memoized(int index, int k, vector<int> &heights, vector<int> &dp)
{
    if (index == 0)
        return 0;

    if (dp[index] != -1)
        return dp[index];

    int min_steps = INT_MAX;
    for (int i = 1; i <= k; i++)
    {
        if (index - i >= 0)
        {
            int solve = rec_Memoized(index - i, k, heights, dp) + abs(heights[index] - heights[index - i]);
            min_steps = min(min_steps, solve);
        }
    }

    return dp[index] = min_steps;
}

int frogJump_Memoized(int n, int k, vector<int> &heights)
{
    vector<int> dp(n, -1);
    return rec_Memoized(n - 1, k, heights, dp);
}

// Tabulated Approach - - - - - - - - - - - - - - - - -
int frogJump_Tabulated(int n, int k, vector<int> &heights)
{
    vector<int> dp(n);

    dp[0] = 0;

    for (int index = 1; index < n; index++)
    {
        int min_steps = INT_MAX;

        for (int j = 1; j <= k; j++)
        {

            if (index - j >= 0)
            {
                int solve = dp[index - j] + abs(heights[index] - heights[index - j]);
                min_steps = min(min_steps, solve);
            }
        }
        dp[index] = min_steps;
    }

    return dp[n - 1];
}

// Space Optimized Approach - - - - - - - - - - - - - - - - -
// No further space optimization will be done, because by doing more space optimization, we are making it O(k) space complexity, because we have to store previous k elements. What if k == n, then the worst case space complexity will be O(N^2). That's why further space complexity is illogical

int main()
{
    vector<int> h{40, 10, 20, 70, 80, 10, 20, 70, 80, 60};
    cout << frogJump_Tabulated(10, 4, h);
    return 0;
}