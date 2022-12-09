#include <iostream>
#include <vector>
using namespace std;
// practice ---> https://practice.geeksforgeeks.org/problems/egg-dropping-puzzle-1587115620/1

// reference
// 1st this -> https://www.youtube.com/watch?v=UvksR0hR9nA 🔥🔥
// then this -> https://www.youtube.com/watch?v=S49zeUjeUL0

// recursion
int rec(int eggs, int floors)
{
    if (eggs == 1)
        return floors;

    if (floors == 0 or floors == 1)
        return floors;

    int ans = INT_MAX;

    for (int x = 1; x <= floors; x++)
    {
        int onBreak = rec(eggs - 1, x - 1);
        int onSurvive = rec(eggs, floors - x);

        int this_ans = 1 + max(onBreak, onSurvive); // +1 to count the trual

        ans = min(ans, this_ans);
    }

    return ans;
}

int eggDrop(int n, int k) // n eggs, and k floors
{
    return rec(n, k);
}

// memoization
int mem(int eggs, int floors, vector<vector<int>> &dp)
{
    if (eggs == 1)
        return floors;

    if (floors == 0 or floors == 1)
        return floors;

    if (dp[eggs][floors] != -1)
        return dp[eggs][floors];

    int ans = INT_MAX;

    for (int x = 1; x <= floors; x++)
    {
        int onBreak = mem(eggs - 1, x - 1, dp);
        int onSurvive = mem(eggs, floors - x, dp);

        int this_ans = 1 + max(onBreak, onSurvive); // +1 to count the trual

        ans = min(ans, this_ans);
    }

    return dp[eggs][floors] = ans;
}

int eggDrop(int n, int k) // n eggs, and k floors
{
    vector<vector<int>> dp(n + 1, vector<int>(k + 1, -1));
    return mem(n, k, dp);
}

// tabulation
int eggDrop(int n, int k) // n eggs, and k floors
{
    vector<vector<int>> dp(n + 1, vector<int>(k + 1));

    // base case 1st
    for (int i = 0; i <= k; i++)
        dp[1][i] = i;

    // base case 2nd
    for (int i = 0; i <= n; i++)
    {
        dp[i][0] = 0;
        dp[i][1] = 1;
    }

    for (int eggs = 2; eggs <= n; eggs++)
    {
        for (int floors = 2; floors <= k; floors++)
        {
            int ans = INT_MAX;

            for (int x = 1; x <= floors; x++)
            {
                int onBreak = dp[eggs - 1][x - 1];
                int onSurvive = dp[eggs][floors - x];

                int this_ans = 1 + max(onBreak, onSurvive); // +1 to count the trual

                ans = min(ans, this_ans);
            }

            dp[eggs][floors] = ans;
        }
    }

    return dp[n][k];
}

// Space Optimized
int eggDrop(int n, int k) // n eggs, and k floors
{
    vector<int> dp(k + 1);

    // base case 1st
    for (int i = 0; i <= k; i++)
        dp[i] = i;

    // base case 2nd
    dp[0] = 0;
    dp[1] = 1;

    for (int eggs = 2; eggs <= n; eggs++)
    {
        // have to initialize this also
        vector<int> temp(k + 1);
        temp[0] = 0, temp[1] = 1;

        for (int floors = 2; floors <= k; floors++)
        {
            int ans = INT_MAX;

            for (int x = 1; x <= floors; x++)
            {
                int onBreak = dp[x - 1];
                int onSurvive = temp[floors - x];

                int this_ans = 1 + max(onBreak, onSurvive); // +1 to count the trual

                ans = min(ans, this_ans);
            }

            temp[floors] = ans;
        }
        dp = temp;
    }

    return dp[k];
}