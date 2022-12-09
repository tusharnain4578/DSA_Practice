#include <iostream>
using namespace std;

// practice --> https://practice.geeksforgeeks.org/problems/max-sum-in-the-configuration/1/
int max_sum(int arr[], int n)
{
    // refference ---> https://www.youtube.com/watch?v=yroWfS5P2E4
    // We have to derive a formula - highly recommend reference

    int sum = 0;
    int s0 = 0;
    for (int i = 0; i < n; i++)
    {
        sum += arr[i];
        s0 += i * arr[i];
    }

    int max = s0;
    int si = s0;

    for (int i = 0; i < n - 1; i++)
    {
        int ps = si + sum - n * arr[n - 1 - i];
        if (ps > max)
            max = ps;

        si = ps;
    }
    return max;
}
int main()
{
    int arr[]{8, 3, 1, 2};
    int size = sizeof(arr) / sizeof(arr[0]);
    cout << max_sum(arr, size);

    return 0;
}