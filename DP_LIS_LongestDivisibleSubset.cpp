#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// practice --> https://leetcode.com/problems/largest-divisible-subset/

// This approach based on DP_LIS solution of 1d DP
// reference --> https://www.youtube.com/watch?v=Wv6DlL0Sawg

//
//
// Approaches ->

// Tabulated Approach ------------------------------------------

vector<int> largestDivisibleSubset(vector<int> &nums)
{
    int n = nums.size();
    sort(nums.begin(), nums.end());

    vector<int> dp(n);

    dp[0] = 1;

    for (int index = 1; index < n; index++)
    {
        int ans = 1;
        for (int i = 0; i < index; i++)
            if (nums[index] % nums[i] == 0) // nums[i] will always be lesser than nums[index], coz they're sorted
                ans = max(ans, dp[i] + 1);

        dp[index] = ans;
    }

    int max = *max_element(dp.begin(), dp.end());

    int prev = -1;
    vector<int> ans;

    for (int i = n - 1; i >= 0; i--)
    {
        if (dp[i] == max and (prev % nums[i] == 0 or prev == -1))
        {
            ans.push_back(nums[i]);
            max--;
            prev = nums[i];
        }
    }

    return ans;
}