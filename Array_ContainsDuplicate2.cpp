#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;
// practice ---> https://leetcode.com/problems/contains-duplicate-ii/

bool containsNearbyDuplicate(vector<int> &nums, int k)
{
    unordered_map<int, int> mp;

    int n = nums.size();

    for (int i = 0; i < n; i++)
    {
        if (mp.count(nums[i]) and abs(i - mp[nums[i]]) <= k)
            return true;
        mp[nums[i]] = i;
    }

    return false;
}