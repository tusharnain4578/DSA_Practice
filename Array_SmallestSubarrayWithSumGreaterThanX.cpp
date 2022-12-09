#include <iostream>
using namespace std;
// practice ---> https://practice.geeksforgeeks.org/problems/smallest-subarray-with-sum-greater-than-x5651/1

int smallestSubWithSum(int arr[], int n, int x)
{
    int start = 0, end = 0;
    int currsum = 0;
    int smallest_subarray_length = n + 1;

    while (end < n)
    {
        while (currsum <= x and end < n)
            currsum += arr[end++];

        while (currsum > x and start < n)
        {
            int this_subarray_length = end - start;

            if (this_subarray_length < smallest_subarray_length)
                smallest_subarray_length = this_subarray_length;

            currsum -= arr[start++];
        }
    }

    return smallest_subarray_length;
}