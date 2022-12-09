#include <iostream>
#include <vector>
using namespace std;

// practice --> https://practice.geeksforgeeks.org/problems/number-of-coins1824/1/

// Please revise in this order
// Recursion -> Memoization -> Tabulation -> Space Optimization

//
//
// Approaches ->

// Recursive Approach ------------------------------------------

int rec(vector<int> &coins, int index, int V)
{
    if (index == 0)
    {
        if (V % coins[index] == 0)
            return V / coins[index];

        return 1e9;
    }

    // adding one, because we're including this 1 coin
    int pick = coins[index] <= V ? 1 + rec(coins, index, V - coins[index]) : 1e9;
    int non_pick = rec(coins, index - 1, V);

    return min(pick, non_pick);
}

int minCoins_rec(vector<int> coins, int V)
{
    int n = coins.size();
    int ans = rec(coins, n - 1, V);

    // if(ans >= 1e9) return -1;
    // else return ans;
    return ans >= 1e9 ? -1 : ans;
}

// Memoized Approach ------------------------------------------

int mem(vector<int> &coins, int index, int V, vector<vector<int>> &dp)
{
    if (index == 0)
    {
        if (V % coins[index] == 0)
            return V / coins[index];

        return 1e9;
    }

    if (dp[index][V] != -1)
        return dp[index][V];

    // adding one, because we're including this 1 coin
    int pick = coins[index] <= V ? 1 + mem(coins, index, V - coins[index], dp) : 1e9;
    int non_pick = mem(coins, index - 1, V, dp);

    // if(ans >= 1e9) return -1;
    // else return ans;
    return dp[index][V] = min(pick, non_pick);
}

int minCoins_mem(vector<int> coins, int V)
{
    int n = coins.size();

    vector<vector<int>> dp(n, vector<int>(V + 1, -1)); // dp

    int ans = mem(coins, n - 1, V, dp);

    return ans >= 1e9 ? -1 : ans;
}

// Tabulated Approach ------------------------------------------

int minCoins_tab(vector<int> coins, int V)
{
    int n = coins.size();

    vector<vector<int>> dp(n, vector<int>(V + 1)); // dp

    for (int index = 0; index < n; index++)
    {
        for (int target = 0; target <= V; target++)
        {
            if (index == 0)
            {
                if (target % coins[index] == 0)
                    dp[index][target] = target / coins[index];
                else
                    dp[index][target] = 1e9;
            }
            else
            {
                int pick = coins[index] <= target ? 1 + dp[index][target - coins[index]] : 1e9;
                int non_pick = dp[index - 1][target];

                dp[index][target] = min(pick, non_pick);
            }
        }
    }

    int ans = dp[n - 1][V];
    // if(ans >= 1e9) return -1;
    // else return ans;

    return ans >= 1e9 ? -1 : ans;
}

// SpaceOptimized Approach ------------------------------------------

int minCoins_SpaceOptimized(vector<int> coins, int V)
{
    int n = coins.size();

    vector<int> dp(V + 1); // dp

    for (int index = 0; index < n; index++)
    {
        vector<int> temp(V + 1);

        for (int target = 0; target <= V; target++)
        {
            if (index == 0)
            {
                if (target % coins[index] == 0)
                    temp[target] = target / coins[index];
                else
                    temp[target] = 1e9;
            }
            else
            {
                int pick = coins[index] <= target ? 1 + temp[target - coins[index]] : 1e9;
                int non_pick = dp[target];

                temp[target] = min(pick, non_pick);
            }
        }
        dp = temp;
    }

    int ans = dp[V];
    // if(ans >= 1e9) return -1;
    // else return ans;

    return ans >= 1e9 ? -1 : ans;
}