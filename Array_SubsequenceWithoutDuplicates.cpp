#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
// practice ---> https://leetcode.com/problems/subsets-ii/

void rec(vector<int> &nums, int index, vector<int> &output, vector<vector<int>> &ans, bool dup)
{
    // bool dup is for knowing if we've previously excluded it or not
    if (index == nums.size())
    {
        ans.push_back(output);
        return;
    }

    rec(nums, index + 1, output, ans, true); // here, true means, to let the next function call know that we've excluded this number, so that that function cannot pick it

    if (index > 0 and nums[index] == nums[index - 1] and dup) // if you've excluded a number before, then exclude here too
        return;

    output.push_back(nums[index]);

    rec(nums, index + 1, output, ans, false); // here, false means that, we've picked it

    output.pop_back();
}

vector<vector<int>> subsetsWithDup(vector<int> &nums)
{
    sort(nums.begin(), nums.end()); // sorting to put all similar numbers together
    vector<vector<int>> ans;
    vector<int> output;
    rec(nums, 0, output, ans, false);
    return ans;
}