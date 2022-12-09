#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
// practice ---> https://practice.geeksforgeeks.org/problems/maximum-sum-increasing-subsequence4749/1

// reference --> https://www.youtube.com/watch?v=e1xG-9vuqI8

// Pre requisite ---> LIS_optimal code in this folder // the LIS_best won't work here
// I am using tabulation of LIS_optimal here

int maxSumIS(int arr[], int n)
{
    vector<int> dp;

    // copying array into vector dp
    copy(arr, arr + n, back_inserter(dp));

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < i; j++)
        {
            if (arr[j] < arr[i])
                dp[i] = max(dp[i], dp[j] + arr[i]);
        }
    }

    return *max_element(dp.begin(), dp.end());
}