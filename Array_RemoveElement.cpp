#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
// practice --> https://leetcode.com/problems/remove-element/

int removeElement(vector<int> &nums, int val)
{
    int n = nums.size();

    int in = 0;

    for (int i = 0; i < n; i++)
        // if the element is not val
        if (nums[i] != val)
            nums[in++] = nums[i];

    return in;
}