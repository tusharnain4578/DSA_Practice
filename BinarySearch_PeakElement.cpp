#include <iostream>
#include <vector>
using namespace std;
//"Every independent array has a peak element"

// practice --> https://practice.geeksforgeeks.org/problems/peak-element/1#
int peakElement(int arr[], int n)
{
    // reference --> https://www.youtube.com/watch?v=zNEn4n0IdPY

    int low = 0, high = n - 1;

    while (low <= high)
    {
        int mid = (low + high) / 2;

        // This if condition might be typical to understand, consider watching reference video
        if ((mid == 0 || arr[mid] >= arr[mid - 1]) && (mid == n - 1 || arr[mid] >= arr[mid + 1]))
            return arr[mid];
        else if (arr[mid - 1] >= arr[mid])
            high = mid - 1;
        else
            low = mid + 1;
    }

    return -1;
}