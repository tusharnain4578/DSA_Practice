#include <iostream>
#include <unordered_set>
#include <vector>
#include <algorithm>
using namespace std;
// practice --> https://leetcode.com/problems/permutations-ii/

// Approach -> Using set // NOTE, you can't use unordered_set of type<vector<int>>
void solve(vector<int> &nums, int index, vector<vector<int>> &ans)
{
    // reference ---> https://www.youtube.com/watch?v=is_T6uzlTyg
    if (index == nums.size())
    {
        ans.push_back(nums);
        return;
    }

    unordered_set<int> s;

    for (int i = index; i < nums.size(); i++)
    {
        if (s.find(nums[i]) != s.end())
            continue;

        s.insert(nums[i]);
        swap(nums[index], nums[i]);
        solve(nums, index + 1, ans);
        swap(nums[index], nums[i]);
    }
}

vector<vector<int>> permuteUnique(vector<int> &nums)
{
    vector<vector<int>> ans;
    solve(nums, 0, ans);

    return ans;
}
