#include <iostream>
#include <vector>
using namespace std;
// practice ---> https://leetcode.com/problems/jump-game-ii/

// this is the same program-> jump game 2

// more optimized way is greedy way, you can find that as JumpGame2 in greedy section

// recursion
int rec(vector<int> &nums, int index, const int &target)
{
    if (index >= target)
        return 0;

    int ans = 1e9;

    for (int i = 1; i <= nums[index]; i++)
    {
        int this_ans = 1 + rec(nums, index + i, target);

        if (this_ans < ans)
            ans = this_ans;
    }

    return ans;
}

int jump_rec(vector<int> &nums)
{
    int n = nums.size();

    int target = n - 1;

    int ans = rec(nums, 0, target);

    return ans >= 1e9 ? -1 : ans;
}

// memoization
int mem(vector<int> &nums, int index, int &target, vector<int> &dp)
{
    if (index >= target)
        return 0;

    if (dp[index] != -1)
        return dp[index];

    int ans = 1e9;

    for (int i = 1; i <= nums[index]; i++)
    {
        int this_ans = 1 + mem(nums, index + i, target, dp);

        if (this_ans < ans)
            ans = this_ans;
    }
    return dp[index] = ans;
}

int jump(vector<int> &nums)
{

    int n = nums.size();

    vector<int> dp(n, -1); // dp

    int target = n - 1;

    int ans = mem(nums, 0, target, dp);

    return ans >= 1e9 ? -1 : ans;
}

// tabulation
int jump(vector<int> &nums)
{

    int n = nums.size();

    vector<int> dp(n); // dp

    int target = n - 1;

    // base case
    dp[n - 1] = 0;

    for (int index = n - 2; index >= 0; index--)
    {
        int ans = 1e9;

        for (int i = 1; (i <= nums[index]) and (index + i <= target); i++)
        {
            int this_ans = 1 + dp[index + i];

            if (this_ans < ans)
                ans = this_ans;
        }

        dp[index] = ans;
    }

    return dp[0] >= 1e9 ? -1 : dp[0];
}

// can't be more optimized (at-least dp method), but there's an approach which does the job in linear time and constant space, which is greedy method (you can find that as JumpGame2 in greedy section)