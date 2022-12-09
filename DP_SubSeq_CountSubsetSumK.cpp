#include <iostream>
#include <vector>
using namespace std;
// practice --> https://www.codingninjas.com/codestudio/problems/number-of-subsets_3952532

//  using the space optimized solution of SubsetSum
//  In Subset Sum, we were supposed to return true or false if the array contains the subset sum,
//  But here we have to count the occurance of that Sum in array
//  So just where you returned true, now return 1
//  where you return false, just return 0
int SubsetSumCount(vector<int> &arr, int sum)
{
    int n = arr.size();

    vector<int> dp(sum + 1); // here we don't have to initialize matrix with -1, so we're taking bool type matrix

    for (int i = 0; i < n; i++) // i represents index in dp matrix
    {
        vector<int> temp(sum + 1);
        for (int j = 0; j <= sum; j++) // j represents sum in dp matrix
        {
            if (j == 0)
            {
                temp[j] = 1; // or dp[i][0], they're same
            }
            else if (i == 0)
            {
                temp[j] = arr[i] == j;
            }
            else
            {
                int pick = (arr[i] <= j) ? dp[j - arr[i]] : 0;

                int non_pick = dp[j];

                temp[j] = pick + non_pick;
            }
        }
        dp = temp;
    }
    return dp[sum];
}

////*****************The above code will fail if there are some 0's in the arr
// because the problem was guaranteed that arr[i]>=1
// but for arr[i]>=0, you just have to alter the base case
// here is the new base case
// whenever you solve this problem, you have to check the constraint, it's very important

// instead of ->
/*
if (j == 0)
{
    temp[j] = 1; // or dp[i][0], they're same
}
else if (i == 0)
{
    temp[j] = arr[i] == j;
}
*/

// use this ->
/*
if (i == 0)
{
    if (j == 0 and arr[i] == 0)
        temp[j] = 2; // one for pick, one for non pick, both will be counted, because addtion of zero doesn't changes the sum
    else if (j == 0)
        temp[j] = 1;
    else if (j == arr[i])
        temp[j] = 1;
}
*/