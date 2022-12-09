#include <iostream>
#include <vector>
using namespace std;
// practice --> https://leetcode.com/problems/permutations/

void solve(vector<int> &nums, int index, vector<vector<int>> &ans)
{
    if (index == nums.size())
    {
        ans.push_back(nums);
        return;
    }

    for (int i = index; i < nums.size(); i++)
    {
        swap(nums[index], nums[i]);
        solve(nums, index + 1, ans);
        swap(nums[index], nums[i]); // We have to backtrack the swap, becuase we're using the nums array by reference, if it's not by reference, you can omit the backtrack
    }
}
vector<vector<int>> permute(vector<int> &nums)
{
    vector<vector<int>> ans;
    solve(nums, 0, ans);
    return ans;
}