#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
// practice ---> https://practice.geeksforgeeks.org/problems/pairs-with-specific-difference1533/1

// There's a DP way also to solve this, you should try that out too.
// DP solution uses 1D DP, which can be optimized upto 2 variables only

int maxSumPairWithDifferenceLessThanK(int arr[], int N, int K)
{
    // Gotta sort the array, only then we can say that arr[i] has minimum diff with either arr[i-1] or arr[i+1], got it? if not search it man
    sort(arr, arr + N);

    // we will iterate the array from behind
    // so that we get bigger numbers in our pairs, which means greater sum

    int ans = 0;

    int i = N - 2;

    while (i >= 0)
    {
        if (abs(arr[i] - arr[i + 1]) < K)
        {
            ans += arr[i] + arr[i + 1];
            i -= 2;
        }
        else
            i -= 1;
    }

    return ans;
}