#include <iostream>
#include <vector>
using namespace std;
// practice ---> https://practice.geeksforgeeks.org/problems/smallest-sum-contiguous-subarray/1

// just reverse the kadane

int smallestSumSubarray(vector<int> &a)
{
    int currSum = 0, minSum = INT_MAX;
    int n = a.size();
    for (int i = 0; i < n; i++)
    {
        currSum += a[i];
        if (currSum < minSum)
            minSum = currSum;

        if (currSum > 0)
            currSum = 0;
    }
    return minSum;
}