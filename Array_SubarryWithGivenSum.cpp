#include <iostream>
#include <vector>
using namespace std;
// Non negative Elements
// practice --> https://practice.geeksforgeeks.org/problems/subarray-with-given-sum-1587115621/1/

// Please go through with the comments in the program
vector<int> subarraySum(int arr[], int n, long long s)
{
    int start = 0;
    long long sum = 0;

    for (int i = 0; i < n; i++)
    {
        sum += arr[i]; // first accumulate

        while (start < i and sum > s) // then handle the start condition
            sum -= arr[start++];

        if (sum == s)          // then handle equality condition
            return {start, i}; // return indexs in 0-based
    }

    return {-1};
}

int main()
{
    // int arr[]{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    // int arr[]{1, 2, 3, 7, 5};
    int arr[]{1, 2, 3, 4};
    int n = sizeof(arr) / sizeof(arr[0]);
    long long s = 0;
    vector<int> v = subarraySum(arr, n, s);
    for (auto &&i : v)
    {
        cout << i << " ";
    }

    return 0;
}