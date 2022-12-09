#include <iostream>
#include <vector>
using namespace std;
// practice --> https://leetcode.com/problems/remove-duplicates-from-sorted-array-ii/

int removeDuplicates(vector<int> &nums)
{
    int n = nums.size();
    if (n < 3)
        return n;
    int in = 2;

    for (int i = 2; i < n; i++)
    {
        if (nums[i] != nums[in - 2])
            nums[in++] = nums[i];
    }

    return in;
}