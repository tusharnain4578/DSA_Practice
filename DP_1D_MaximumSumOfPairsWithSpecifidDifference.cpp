#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
// practice ---> https://practice.geeksforgeeks.org/problems/pairs-with-specific-difference1533/1

// There's a kinda' greedy way also (better ig), you can find that on Greedy section of this folder

// recursion
int rec(int arr[], int &N, int index, int &K)
{
    if (index >= N)
        return 0;

    int pick = 0, not_pick;

    if (index + 1 < N and abs(arr[index] - arr[index + 1]) < K)
        pick = arr[index] + arr[index + 1] + rec(arr, N, index + 2, K);

    not_pick = 0 + rec(arr, N, index + 1, K);

    return max(pick, not_pick);
}

int maxSumPairWithDifferenceLessThanK_rec(int arr[], int N, int K)
{
    // Gotta sort the array, only then we can say that arr[i] has minimum diff with either arr[i-1] or arr[i+1], got it? if not search it man
    sort(arr, arr + N);

    return rec(arr, N, 0, K); // here i called the recursion from 0 to N, doesn matter you can go otherwise also. recursion order doesnt matter because, we're in DP nigga' we're about to cover all the possible cases,
    // In the greedy solution of this problem, we have to start from end of the array (you can find it's greedy solution in this folder)
}

// memoization
int mem(int arr[], int &N, int index, int &K, vector<int> &dp)
{
    if (index >= N)
        return 0;

    if (dp[index] != -1)
        return dp[index];

    int pick = 0, not_pick;

    if (index + 1 < N and abs(arr[index] - arr[index + 1]) < K)
        pick = arr[index] + arr[index + 1] + mem(arr, N, index + 2, K, dp);

    not_pick = 0 + mem(arr, N, index + 1, K, dp);

    return dp[index] = max(pick, not_pick);
}

int maxSumPairWithDifferenceLessThanK_mem(int arr[], int N, int K)
{
    sort(arr, arr + N);

    vector<int> dp(N, -1); // 1D DP. you're not blind, silly me. LOL

    return mem(arr, N, 0, K, dp);
}

// tabulation
int maxSumPairWithDifferenceLessThanK_tab(int arr[], int N, int K)
{
    sort(arr, arr + N);

    vector<int> dp(N + 1);

    // base case
    dp[N] = 0;

    for (int index = N - 1; index >= 0; index--)
    {
        int pick = 0, not_pick;

        if (index + 1 < N and abs(arr[index] - arr[index + 1]) < K)
            pick = arr[index] + arr[index + 1] + dp[index + 2];

        not_pick = 0 + dp[index + 1];

        dp[index] = max(pick, not_pick);
    }

    return dp[0];
}

// Space Optimized -> 3 variables only
int maxSumPairWithDifferenceLessThanK(int arr[], int N, int K)
{
    sort(arr, arr + N);

    int a = 0, b, c;

    for (int index = N - 1; index >= 0; index--)
    {
        int pick = 0, not_pick;

        if (index + 1 < N and abs(arr[index] - arr[index + 1]) < K)
            pick = arr[index] + arr[index + 1] + b;

        not_pick = 0 + a;

        c = max(pick, not_pick);

        b = a;
        a = c;
    }

    return c;
}

// Space Optimized -> 2 variables only
int maxSumPairWithDifferenceLessThanK(int arr[], int N, int K)
{
    sort(arr, arr + N);

    int a = 0, b;

    for (int index = N - 1; index >= 0; index--)
    {
        int pick = 0, not_pick;

        if (index + 1 < N and abs(arr[index] - arr[index + 1]) < K)
            pick = arr[index] + arr[index + 1] + b;

        not_pick = 0 + a;

        b = a;

        a = max(pick, not_pick);
    }

    return a;
}