#include <iostream>
#include <vector>
using namespace std;
// practice --> https://leetcode.com/problems/search-insert-position/submissions/

int searchInsert(vector<int> &nums, int target)
{
    int low = 0, high = nums.size() - 1;

    int ans = 0;

    while (low <= high)
    {
        int mid = (low + high) / 2;

        if (nums[mid] == target)
        {
            return mid;
        }
        else if (nums[mid] < target)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }

    return low;
}