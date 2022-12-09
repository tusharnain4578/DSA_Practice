#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
// practice --> https://practice.geeksforgeeks.org/problems/longest-subsequence-such-that-difference-between-adjacents-is-one4724/1

// the above gfg practice set is even accepting the recursive solution, idk why?

// the recursion and top-down is not recommended, you should practice the approach in the bottom of this file

// recursion //pick, non-pick way
int rec(int a[], int index, int prev)
{

    if (index < 0)
    {
        return 0;
    }

    int pick = 0;

    if (prev == -1 or abs(a[index] - a[prev]) == 1)
        pick = 1 + rec(a, index - 1, index);

    int non_pick = 0 + rec(a, index - 1, prev);

    return max(pick, non_pick);
}

int longestSubsequence(int N, int A[])
{
    return rec(A, N - 1, -1);
}

// memoization //pick, non-pick way
int mem(int a[], int index, int prev, vector<vector<int>> &dp)
{

    if (index < 0)
    {
        return 0;
    }

    if (dp[index][prev] != -1)
        return dp[index][prev];

    int pick = 0;

    if (prev == 0 or abs(a[index] - a[prev]) == 1)
        pick = 1 + mem(a, index - 1, index, dp);

    int non_pick = 0 + mem(a, index - 1, prev, dp);

    return dp[index][prev] = max(pick, non_pick);
}

int longestSubsequence_mem(int N, int A[])
{
    vector<vector<int>> dp(N, vector<int>(N, -1));

    return mem(A, N - 1, 0, dp); // here in prev, i am passing 0(instead of -1), because, -1 is not in dp, so 0 is also fine, because we will never have to do anything on a call where prev is 0, so it can be a starting function call
}

// The typical lis way
// recommended
// by using LongtestSUbsequenceOptimal.cpp tabulation
int longestSubsequence(int N, int A[])
{
    // initializing lis with 1, because every single element is an answer 1
    vector<int> lis(N, 1); // aka dp

    for (int i = 1; i < N; i++)
        for (int j = 0; j < i; j++)
            if (abs(A[i] - A[j]) == 1)
                lis[i] = max(lis[i], lis[j] + 1);

    // return max from lis array
    return *max_element(lis.begin(), lis.end());
}