#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;
// practice ---> https://leetcode.com/problems/continuous-subarray-sum/

// reference ---> https://www.youtube.com/watch?v=OKcrLfR-8mE

// reference also in the help folder

// hint -> prefix sum

bool checkSubarraySum(vector<int> &nums, int k)
{
    int n = nums.size();
    unordered_map<int, int> mp;

    mp[0] = -1;

    int currSum = 0;

    for (int i = 0; i < n; i++)
    {
        currSum += nums[i];

        int r = currSum % k; // current sum remainder with k

        if (mp.count(r) == 0)
            mp[r] = i;

        else if (i - mp[r] > 1)
            return true;
    }

    return false;
}