#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
// practice ---> https://leetcode.com/problems/minimum-difficulty-of-a-job-schedule/

// reference --> https://www.youtube.com/watch?v=mBZEFR3LSNs

// recursion
int rec(vector<int> &jd, int &n, int index, int daysLeft)
{
    if (daysLeft == 1)
        return *max_element(begin(jd) + index, end(jd));

    int maxDifficultyTillNow = INT_MIN;
    int result = INT_MAX;

    for (int i = index; i <= n - daysLeft; i++)
    {
        maxDifficultyTillNow = max(maxDifficultyTillNow, jd[i]);
        result = min(result, maxDifficultyTillNow + rec(jd, n, i + 1, daysLeft - 1));
    }

    return result;
}

int minDifficulty_rec(vector<int> &jobDifficulty, int d)
{
    int n = jobDifficulty.size();

    if (n < d)
        return -1;

    return rec(jobDifficulty, n, 0, d);
}

// memoization
int mem(vector<int> &jd, int &n, int index, int daysLeft, vector<vector<int>> &dp)
{
    if (daysLeft == 1)
        return *max_element(begin(jd) + index, end(jd));

    if (dp[index][daysLeft] != -1)
        return dp[index][daysLeft];

    int maxDifficultyTillNow = INT_MIN;
    int result = INT_MAX;

    for (int i = index; i <= n - daysLeft; i++)
    {
        maxDifficultyTillNow = max(maxDifficultyTillNow, jd[i]);
        result = min(result, maxDifficultyTillNow + mem(jd, n, i + 1, daysLeft - 1, dp));
    }

    return dp[index][daysLeft] = result;
}

int minDifficulty_mem(vector<int> &jobDifficulty, int d)
{
    int n = jobDifficulty.size();

    if (n < d)
        return -1;

    vector<vector<int>> dp(n, vector<int>(d + 1, -1));

    return mem(jobDifficulty, n, 0, d, dp);
}

// tabulation
int minDifficulty_tab(vector<int> &jobDifficulty, int d)
{
    // nothing just reference jd for jobDifficulty, as its such a long name
    vector<int> &jd = jobDifficulty;

    int n = jd.size();

    if (n < d)
        return -1;

    vector<vector<int>> dp(n, vector<int>(d + 1));

    // base case
    for (int i = 0; i < n; i++)
        dp[i][1] = *max_element(begin(jd) + i, end(jd));

    for (int index = n - 1; index >= 0; index--)
    {
        for (int daysLeft = 2; daysLeft <= d; daysLeft++)
        {
            int maxDifficultyTillNow = INT_MIN;
            int result = INT_MAX;

            for (int i = index; i <= n - daysLeft; i++)
            {
                maxDifficultyTillNow = max(maxDifficultyTillNow, jd[i]);
                result = min(result, maxDifficultyTillNow + dp[i + 1][daysLeft - 1]);
            }

            dp[index][daysLeft] = result;
        }
    }

    return dp[0][d];
}

// Can't be more optimized ig