#include <iostream>
#include <vector>
using namespace std;
// practice --> https://practice.geeksforgeeks.org/problems/peak-element/1#

// This solution is straightforwrd, time complexity is of O(N)
// There is a better approach which uses binary search and can solve this in O(logN). You can find that solution in BinarySearch Part of this folder

int peakElement(int arr[], int n)
{
    if (n == 1 || n == 0)
        return 0;

    if (arr[0] > arr[1])
        return 0;

    if (arr[n - 1] > arr[n - 2])
        return n - 1;

    for (int i = 1; i < n - 1; i++)
    {
        if (arr[i] > arr[i - 1] && arr[i] > arr[i + 1])
        {
            return i;
        }
    }

    return 0;
}