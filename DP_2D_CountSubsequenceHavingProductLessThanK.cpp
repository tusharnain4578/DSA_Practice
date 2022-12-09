#include <iostream>
#include <vector>
using namespace std;

// pracice ---> https://practice.geeksforgeeks.org/problems/number-of-subsets-with-product-less-than-k/1

// In recursive solution, this approach have overlapping subproblems, for example you can draw recursion tree for a[]{1,2,3,4} with k = 10

// recursion
int rec(int a[], int index, int prod, int k)
{

    if (prod > k)
        return 0;

    if (index < 0)
    {
        if (prod <= k)
            return 1;
        return 0;
    }

    // not_pick
    int non_pick = rec(a, index - 1, prod, k);

    // we're using condition in prod arguement to handle the first recurion call
    //  pick
    int pick = rec(a, index - 1, prod * a[index], k);

    return pick + non_pick;
}

int numOfSubsets(int arr[], int N, int K)
{
    return rec(arr, N - 1, 1, K) - 1;
}

// memoization

int mem(int a[], int index, int prod, int k, vector<vector<int>> &dp)
{

    if (prod > k)
        return 0;

    if (index < 0)
    {
        if (prod <= k)
            return 1;
        return 0;
    }

    if (dp[index][prod] != -1)
        return dp[index][prod];

    int non_pick = mem(a, index - 1, prod, k, dp);

    int pick = mem(a, index - 1, prod * a[index], k, dp);

    return dp[index][prod] = pick + non_pick;
}

int numOfSubsets(int arr[], int N, int K)
{
    vector<vector<int>> dp(N, vector<int>(K + 1, -1));
    return mem(arr, N - 1, 1, K, dp) - 1;
}

// sadly there are no much talking about this problem on youtube, so this is only what i got 😔