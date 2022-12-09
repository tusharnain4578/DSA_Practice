#include <iostream>
using namespace std;
// practice ---> https://practice.geeksforgeeks.org/problems/minimum-swaps-required-to-bring-all-elements-less-than-or-equal-to-k-together4847/1

int minSwap(int arr[], int n, int k)
{
    // reference --> https://www.youtube.com/watch?v=yXjVfeWzyAM&ab
    int count = 0;

    for (int i = 0; i < n; i++)
        if (arr[i] <= k)
            count++;

    int bad = 0;

    for (int i = 0; i < count; i++)
        if (arr[i] > k)
            bad++;

    int ans = bad;

    int i = 0, j = count;

    while (j < n)
    {
        if (arr[i] > k)
            bad--;

        if (arr[j] > k)
            bad++;

        ans = min(ans, bad);

        i++;
        j++;
    }

    return ans;
}