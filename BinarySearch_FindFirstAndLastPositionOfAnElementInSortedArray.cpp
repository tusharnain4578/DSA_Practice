#include <iostream>
#include <vector>
using namespace std;
// practice --> https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/

// dir -> 0 for left, 1 for right
int binarySearch(const vector<int> &nums, const int target, bool dir)
{
    int low = 0, high = nums.size() - 1;
    int res = -1;

    while (low <= high)
    {
        int mid = (low + high) / 2;

        if (nums[mid] == target)
        {
            res = mid;
            if (dir)
                low = mid + 1;
            else
                high = mid - 1;
        }
        else if (nums[mid] < target)
            low = mid + 1;
        else
            high = mid - 1;
    }

    return res;
}

vector<int> searchRange(vector<int> &nums, int target)
{
    return {binarySearch(nums, target, 0), binarySearch(nums, target, 1)};
}