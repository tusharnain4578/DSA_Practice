#include <iostream>
#include <vector>
using namespace std;
// practice ---> https://practice.geeksforgeeks.org/problems/longest-alternating-subsequence5951/1
//
// O(N) time and constant space approach

// reference ---> https://www.youtube.com/watch?v=YrtczUOlRC8

int AlternatingaMaxLength(vector<int> &nums)
{
    int n = nums.size();

    int incr = 1, decr = 1;

    for (int i = 1; i < n; i++)
    {
        if (nums[i] > nums[i - 1])
            incr = decr + 1;
        else if (nums[i] < nums[i - 1])
            decr = incr + 1;
    }

    return max(incr, decr);
}