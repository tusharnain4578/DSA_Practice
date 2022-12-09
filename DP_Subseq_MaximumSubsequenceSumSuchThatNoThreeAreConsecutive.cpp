#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
// practice ---> https://www.codingninjas.com/codestudio/problems/maximum-subsequence-sum-such-that-no-three-are-consecutive_1215007

// reference --> https://www.youtube.com/watch?v=-FJinY9Yb-s

// recursion
int rec(vector<int> &a, int index)
{
    if (index < 0)
        return 0;
    else if (index == 0)
        return a[0];

    // three possibilities are there

    // 1. Don't choose the current and send the recursion to curr-1 (previus)
    int case1 = 0 + rec(a, index - 1);

    // 2. Choose the current and send the recursion to curr-2
    int case2 = a[index] + rec(a, index - 2);

    // 3. Choose the current and curr-1, and send the recursion to curr-3
    int case3 = a[index] + a[index - 1] + rec(a, index - 3);

    return max({case1, case2, case3});
}

int maxSum(vector<int> &a, int n)
{
    return rec(a, n - 1);
}

// memoization
int mem(vector<int> &a, int index, vector<int> &dp)
{
    if (index < 0)
        return 0;
    else if (index == 0)
        return a[0];

    if (dp[index] != -1)
        return dp[index];

    int case1 = 0 + mem(a, index - 1, dp);

    int case2 = a[index] + mem(a, index - 2, dp);

    int case3 = a[index] + a[index - 1] + mem(a, index - 3, dp);

    return dp[index] = max({case1, case2, case3});
}

int maxSum_mem(vector<int> &a, int n)
{
    vector<int> dp(n, -1);
    return mem(a, n - 1, dp);
}

// Tabulation
int maxSum_tab(vector<int> &a, int n)
{
    vector<int> dp(n);

    dp[0] = a[0]; // base case

    for (int index = 1; index < n; index++)
    {
        int case1 = 0 + dp[index - 1];

        int case2 = a[index] + ((index - 2 >= 0) ? dp[index - 2] : 0);

        int case3 = a[index] + a[index - 1] + ((index - 3 >= 0) ? dp[index - 3] : 0);

        dp[index] = max({case1, case2, case3});
    }

    return dp[n - 1];
}

// Space Optimized -> 4 variables only
int maxSum_SpaceOptimized(vector<int> &arr, int n)
{
    int a = arr[0], b, c;
    int curr;

    for (int index = 1; index < n; index++)
    {
        int case1 = 0 + a;

        int case2 = arr[index] + ((index - 2 >= 0) ? b : 0);

        int case3 = arr[index] + arr[index - 1] + ((index - 3 >= 0) ? c : 0);

        curr = max({case1, case2, case3});

        c = b;
        b = a;
        a = curr;
    }

    return a;
}

// Space Optimized -> 3 variables only

// just understand the flow of the 4 variables from above and you'll realize that we only require 3 of them, just have to readjust them

int maxSum_SpaceOptimized(vector<int> &arr, int n)
{
    int a = arr[0], b, c;
    int curr;

    for (int index = 1; index < n; index++)
    {
        int case1 = 0 + a;

        int case2 = arr[index] + ((index - 2 >= 0) ? b : 0);

        int case3 = arr[index] + arr[index - 1] + ((index - 3 >= 0) ? c : 0);

        c = b;
        b = a;

        // directly assigning the curr into a, that's all
        a = max({case1, case2, case3});
    }

    return a;
}

// This 3 variable method is the most efficient approach