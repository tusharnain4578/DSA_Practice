#include <iostream>
#include <vector>
using namespace std;
// practice ---> https://leetcode.com/problems/arithmetic-slices/

// just the bottom up is very intuitive and makes sense, just see the reference

// reference --> https://www.youtube.com/watch?v=D7PZZtvHnGo

// bottom up //tabulation
int numberOfArithmeticSlices(vector<int> &nums)
{
    int n = nums.size();

    if (n < 3)
        return 0;

    vector<int> dp(n);
    dp[0] = dp[1] = 0;

    int result = 0;

    for (int i = 2; i < n; i++)
    {
        if (nums[i] - nums[i - 1] == nums[i - 1] - nums[i - 2])
        {
            dp[i] = dp[i - 1] + 1;

            result += dp[i];
        }
    }

    return result;
}

//
// Space optimized
int numberOfArithmeticSlices(vector<int> &nums)
{
    int n = nums.size();

    if (n < 3)
        return 0;

    int curr = 0, total = 0;

    for (int i = 2; i < n; i++)
    {
        if (nums[i] - nums[i - 1] == nums[i - 1] - nums[i - 2])
        {
            curr++;
            total += curr;
        }
        else
            curr = 0;
    }

    return total;
}