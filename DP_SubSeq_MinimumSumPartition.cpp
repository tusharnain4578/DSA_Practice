#include <iostream>
#include <vector>
#include <numeric>
using namespace std;
// practice --> https://practice.geeksforgeeks.org/problems/minimum-sum-partition3317/1/\

// using space optimized code of subset sum
vector<bool> isSubsetSumDP(int arr[], int n, int sum)
{
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
    return dp;
}

int minDifference(int arr[], int n)
{
    int total_sum = accumulate(arr, arr + n, 0);

    vector<bool> dp = isSubsetSumDP(arr, n, total_sum);

    int min_dif = INT_MAX;

    for (int i = 0; i < dp.size(); i++)
    {
        if (dp[i])
        {
            int s1 = i;
            int s2 = total_sum - s1;

            min_dif = min(min_dif, abs(s1 - s2));
        }
    }

    return min_dif;
}