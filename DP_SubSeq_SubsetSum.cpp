#include <iostream>
#include <vector>
using namespace std;
// practice --> https://practice.geeksforgeeks.org/problems/subset-sum-problem-1611555638/1/

// Please revise in this order
// Recursion -> Memoization -> Tabulation -> Space Optimization

//
//
// Approaches ->

// Recursive Approach ------------------------------------------

bool rec(vector<int> arr, int index, int sum)
{
    if (sum == 0)
        return true;

    if (index == 0)
        return arr[index] == sum; // for first index, if it's the remaining sum, then it's true, otherwise false

    // only pick the element if it's smaller or equal to the target sum
    bool pick = (arr[index] <= sum) ? rec(arr, index - 1, sum - arr[index]) : false;

    bool non_pick = rec(arr, index - 1, sum);

    return pick or non_pick; // return (pick or non_pick), if any one of them is true, then return true, otherwise false
}

bool isSubsetSum_rec(vector<int> arr, int sum)
{
    int n = arr.size();
    return rec(arr, n - 1, sum);
}

// Memoized Approach ------------------------------------------

bool mem(vector<int> arr, int index, int sum, vector<vector<int>> &dp)
{
    if (sum == 0)
        return true;

    if (index == 0)
        return arr[index] == sum;

    if (dp[index][sum] != -1)
        return dp[index][sum];

    bool pick = (arr[index] <= sum) ? mem(arr, index - 1, sum - arr[index], dp) : false;

    bool non_pick = mem(arr, index - 1, sum, dp);

    return dp[index][sum] = pick or non_pick;
}

bool isSubsetSum_mem(vector<int> arr, int sum)
{
    int n = arr.size();

    vector<vector<int>> dp(n, vector<int>(sum + 1, -1)); // we're using int type matrix, because we have to initialize it with -1
    return mem(arr, n - 1, sum, dp);
}

// Tabulated Approach ------------------------------------------

bool isSubsetSum_tabulated(vector<int> arr, int sum)
{
    int n = arr.size();

    vector<vector<bool>> dp(n, vector<bool>(sum + 1)); // here we don't have to initialize matrix with -1, so we're taking bool type matrix

    for (int i = 0; i < n; i++) // i represents index in dp matrix
    {
        for (int j = 0; j <= sum; j++) // j represents sum in dp matrix
        {
            if (j == 0)
            {
                dp[i][j] = true; // or dp[i][0], they're same
            }
            else if (i == 0)
            {
                dp[i][j] = (arr[i] == j);
            }
            else
            {
                bool pick = (arr[i] <= j) ? dp[i - 1][j - arr[i]] : false;

                bool non_pick = dp[i - 1][j];

                dp[i][j] = pick or non_pick;
            }
        }
    }
    return dp[n - 1][sum];
}

// Space Approach ------------------------------------------

bool isSubsetSum_SpaceOptimized(vector<int> arr, int sum)
{
    int n = arr.size();

    vector<bool> dp(sum + 1); // here we don't have to initialize matrix with -1, so we're taking bool type matrix

    for (int i = 0; i < n; i++) // i represents index in dp matrix
    {
        vector<bool> temp(sum + 1);
        for (int j = 0; j <= sum; j++) // j represents sum in dp matrix
        {
            if (j == 0)
            {
                temp[j] = true; // or dp[i][0], they're same
            }
            else if (i == 0)
            {
                temp[j] = arr[i] == j;
            }
            else
            {
                bool pick = (arr[i] <= j) ? dp[j - arr[i]] : false;

                bool non_pick = dp[j];

                temp[j] = pick or non_pick;
            }
        }
        dp = temp;
    }
    return dp[sum];
}