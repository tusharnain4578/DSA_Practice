#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// practice --> https://leetcode.com/problems/number-of-longest-increasing-subsequence/

// This approach is using prev_index

//
// Approaches ->

// Tabulation Approach ------------------------------------------

int findNumberOfLIS(vector<int> &nums)
{
    int n = nums.size();

    vector<int> dp(n, 1);
    dp[0] = 1;

    int max_lis = 1;

    vector<int> lis_count(n, 1);

    for (int index = 1; index < n; index++)
    {

        for (int i = 0; i < index; i++)
        {
            if (nums[i] < nums[index] and dp[i] + 1 > dp[index])
            {
                dp[index] = dp[i] + 1;
                lis_count[index] = lis_count[i];
            }
            else if (nums[i] < nums[index] and dp[i] + 1 == dp[index])
            {
                lis_count[index] += lis_count[i];
            }
        }

        max_lis = max(max_lis, dp[index]);
    }

    int res = 0;

    for (int i = 0; i < n; i++)
        if (dp[i] == max_lis)
            res += lis_count[i];

    return res;
}