#include <iostream>
#include <vector>
using namespace std;
// practice --> https://leetcode.com/problems/search-in-rotated-sorted-array/

int search(vector<int> &nums, int target)
{
    // reference ---> https://www.youtube.com/watch?v=1uu3g_uu8O0
    int low = 0, high = nums.size() - 1;

    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (nums[mid] == target)
            return mid;
        else if (nums[low] <= nums[mid])
        {
            if (target >= nums[low] && target <= nums[mid])
                high = mid - 1;
            else
                low = mid + 1;
        }
        else if (nums[mid] <= nums[high])
        {
            if (target >= nums[mid] && target <= nums[high])
                low = mid + 1;
            else
                high = mid - 1;
        }
    }
    return -1;
}

int main()
{
    vector<int> v{4, 5, 6, 7, 0, 1, 2};
    int target{0};
    cout << search(v, target);

    return 0;
}