#include <iostream>
#include <vector>
#include <numeric>
using namespace std;
// practice --> https://www.codingninjas.com/codestudio/problems/partitions-with-given-difference_3751628

// Formula derived ->
//  https://drive.google.com/file/d/1-ayg1u0bpTr3fyKIIj703xo2iX9gNeCm/view?usp=sharing

//
// In the problem statement, it is mentioned that the answer can be great and we can use modulo 1e9+7
// 10^9 + 7
// modulo is in line 42

int subsetSumCount(vector<int> &arr, int sum)
{
    int n = arr.size();
    int mod = 1e9 + 7;

    vector<int> dp(sum + 1); // here we don't have to initialize matrix with -1, so we're taking bool type matrix

    for (int i = 0; i < n; i++) // i represents index in dp matrix
    {
        vector<int> temp(sum + 1);
        for (int j = 0; j <= sum; j++) // j represents sum in dp matrix
        {
            if (i == 0)
            {
                if (j == 0 and arr[i] == 0)
                    temp[j] = 2; // one for pick, one for non pick, both will be counted, because addtion of zero doesn't changes the sum
                else if (j == 0)
                    temp[j] = 1;
                else if (j == arr[i])
                    temp[j] = 1;
            }
            else
            {
                int pick = (arr[i] <= j) ? dp[j - arr[i]] : 0;

                int non_pick = dp[j];

                temp[j] = (pick + non_pick) % mod;
            }
        }
        dp = temp;
    }
    return dp[sum];
}

int countPartitions(int n, int d, vector<int> &arr)
{
    int total_sum = accumulate(arr.begin(), arr.end(), 0);

    if (total_sum - d < 0 or (total_sum - d) % 2)
        return 0;

    int s2 = (total_sum - d) / 2;

    return subsetSumCount(arr, s2);
}
