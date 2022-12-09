#include <iostream>
#include <vector>
using namespace std;
// practice ---> https://practice.geeksforgeeks.org/problems/optimal-binary-search-tree2214/1

// pattern -> MCM
// intuition -> we're taking the rth node as root, and calling recusion for left sub tree and right sub tree, but the array needs to be sortec for that, if it isn't provided sorted, we have to sort it oursleves

// NOTE -> we won't be needing keys for calculating this, we'll only use the freq array (ofc we need freq array), see how fascinating is that

// Another fkin note-> the intuition is quite difficult (esp. why we are collecting cummulating sum), for that you have to dry run from the smallest subproblem, you got that, ik

// recursion
int rec(int freq[], int i, int j, vector<int> &freq_prefix_sum)
{
    if (i > j) // no subarray/subtree left
        return 0;

    if (i == j)         // if only one node is in tree
        return freq[i]; // or freq[j]

    int fsum = freq_prefix_sum[j] - freq_prefix_sum[i] + freq[i];

    int min_result = INT_MAX;

    for (int root = i; root <= j; root++)
    {
        int temp = rec(freq, i, root - 1, freq_prefix_sum) + rec(freq, root + 1, j, freq_prefix_sum);

        if (temp < min_result)
            min_result = temp;
    }

    return min_result + fsum;
}

int optimalSearchTree(int keys[], int freq[], int n)
{
    // instead of collecting sum of freq i to j, we're using prefix sum array, it's more optimized, although using n size array
    vector<int> freq_prefix_sum{freq[0]}; // inserting the first key element

    for (int i = 1; i < n; i++)
        freq_prefix_sum.push_back(freq_prefix_sum.back() + freq[i]);

    return rec(freq, 0, n - 1, freq_prefix_sum);
}

//
//
// memoization
int mem(int freq[], int i, int j, vector<int> &freq_prefix_sum, vector<vector<int>> &dp)
{
    if (i > j)
        return 0;

    if (i == j)
        return freq[i];

    if (dp[i][j] != -1)
        return dp[i][j];

    int fsum = freq_prefix_sum[j] - freq_prefix_sum[i] + freq[i];

    int min_result = INT_MAX;

    for (int root = i; root <= j; root++)
    {
        int temp = mem(freq, i, root - 1, freq_prefix_sum, dp) + mem(freq, root + 1, j, freq_prefix_sum, dp);

        if (temp < min_result)
            min_result = temp;
    }

    return dp[i][j] = min_result + fsum;
}

int optimalSearchTree(int keys[], int freq[], int n)
{
    vector<int> freq_prefix_sum{freq[0]};

    for (int i = 1; i < n; i++)
        freq_prefix_sum.push_back(freq_prefix_sum.back() + freq[i]);

    vector<vector<int>> dp(n, vector<int>(n, -1));

    return mem(freq, 0, n - 1, freq_prefix_sum, dp);
}

//
//
//
// tabulation
int optimalSearchTree(int keys[], int freq[], int n)
{

    vector<int> freq_prefix_sum{freq[0]};

    for (int i = 1; i < n; i++)
        freq_prefix_sum.push_back(freq_prefix_sum.back() + freq[i]);

    vector<vector<int>> dp(n + 1, vector<int>(n, 0));

    for (int i = 0; i < n; i++)
        dp[i][i] = freq[i];

    for (int i = n - 1; i >= 0; i--)
    {
        for (int j = 0; j < n; j++)
        {
            if (i < j)
            {
                int fsum = freq_prefix_sum[j] - freq_prefix_sum[i] + freq[i];

                int min_result = INT_MAX;

                for (int root = i; root <= j; root++)
                {
                    int temp = dp[i][root - 1] + dp[root + 1][j];

                    if (temp < min_result)
                        min_result = temp;
                }

                dp[i][j] = min_result + fsum;
            }
        }
    }

    return dp[0][n - 1];
}

// idt it can be optimized more, and ig it is more than enough