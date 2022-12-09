#include <iostream>
#include <vector>
using namespace std;
// practice ---> https://practice.geeksforgeeks.org/problems/reach-a-given-score-1587115621/1

// recursion
long long int rec(long long int sum, int ch_index, vector<int> &choice)
{
    if (sum == 0)
        return 1;

    if (ch_index < 0)
        return 0;

    long long int take = 0;

    if (choice[ch_index] <= sum)
        take = rec(sum - choice[ch_index], ch_index, choice);

    long long int non_take = rec(sum, ch_index - 1, choice);

    return take + non_take;
}

long long int count_rec(long long int n)
{
    vector<int> choice{3, 5, 10};
    int choice_size = choice.size();

    return rec(n, choice_size - 1, choice);
}

// memoization
long long int mem(long long int sum, int ch_index, vector<int> &choice, vector<vector<int>> &dp)
{
    if (sum == 0)
        return 1;

    if (ch_index < 0)
        return 0;

    if (dp[sum][ch_index] != -1)
        return dp[sum][ch_index];

    long long int take = 0;

    if (choice[ch_index] <= sum)
        take = mem(sum - choice[ch_index], ch_index, choice, dp);

    long long int non_take = mem(sum, ch_index - 1, choice, dp);

    return dp[sum][ch_index] = take + non_take;
}

long long int count_mem(long long int n)
{
    vector<int> choice{3, 5, 10};
    int choice_size = choice.size();

    vector<vector<int>> dp(n + 1, vector<int>(choice_size, -1));

    return mem(n, choice_size - 1, choice, dp);
}

// tabulation
long long int count(long long int n)
{
    vector<int> choice{3, 5, 10};
    int choice_size = choice.size();

    vector<vector<int>> dp(n + 1, vector<int>(choice_size + 1));

    // base case
    for (int i = 0; i <= choice_size; i++)
        dp[0][i] = 1;
    for (int i = 0; i <= n; i++)
        dp[i][0] = 0;

    for (int sum = 1; sum <= n; sum++)
    {
        for (int ch_index = 1; ch_index <= choice_size; ch_index++)
        {
            long long int take = 0;

            if (choice[ch_index - 1] <= sum)
                take = dp[sum - choice[ch_index - 1]][ch_index];

            long long int non_take = dp[sum][ch_index - 1];

            dp[sum][ch_index] = take + non_take;
        }
    }

    return dp[n][choice_size];
}

// can't optimize more, it can but that's not worth it ig.