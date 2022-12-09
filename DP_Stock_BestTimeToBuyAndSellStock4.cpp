#include <iostream>
#include <vector>
using namespace std;

// Total K transactions

// Based on the 2nd method from the Stock3 Solution
// Read 229th line of Stock3 solution cpp file
//
//

// Approaches ->

// Recursive Approach ------------------------------------------

int rec(vector<int> &prices, int index, int &n, int transaction)
{
    if (index == n or transaction == -1)
        return 0;

    int profit;

    if (transaction % 2 == 0)
    {
        int selling = prices[index] + rec(prices, index + 1, n, transaction - 1);
        int not_selling = rec(prices, index + 1, n, transaction);

        profit = max(selling, not_selling);
    }
    else
    {
        int buying = -prices[index] + rec(prices, index + 1, n, transaction - 1);
        int not_buying = 0 + rec(prices, index + 1, n, transaction);

        profit = max(buying, not_buying);
    }

    return profit;
}

int maxProfit_rec(int k, vector<int> &prices)
{
    int n = prices.size();

    return rec(prices, 0, n, k * 2 - 1); /// k*2 becuase each transaction includes two factors, buy and sell, and -1 because of 0 based indexing
}

// Memoized Approach ------------------------------------------

int mem(vector<int> &prices, int index, int &n, int transaction, vector<vector<int>> &dp)
{
    if (index == n or transaction == -1)
        return 0;

    if (dp[index][transaction] != -1)
        return dp[index][transaction];

    int profit;

    if (transaction % 2 == 0)
    {
        int selling = prices[index] + mem(prices, index + 1, n, transaction - 1, dp);
        int not_selling = mem(prices, index + 1, n, transaction, dp);

        profit = max(selling, not_selling);
    }
    else
    {
        int buying = -prices[index] + mem(prices, index + 1, n, transaction - 1, dp);
        int not_buying = 0 + mem(prices, index + 1, n, transaction, dp);

        profit = max(buying, not_buying);
    }

    return dp[index][transaction] = profit;
}

int maxProfit_mem(int k, vector<int> &prices)
{
    int n = prices.size();

    vector<vector<int>> dp(n, vector<int>(k * 2, -1)); // 3d DP

    return mem(prices, 0, n, k * 2 - 1, dp);
}

// Tabulative Approach ------------------------------------------

int maxProfit_tab(int k, vector<int> &prices)
{
    int n = prices.size();

    vector<vector<int>> dp(n + 1, vector<int>(k * 2 + 1)); // 4 + 1 = 5, 1 extra for base case

    // watch TUF video of this topic, you'll get the best idea to make the base case

    // base cases
    for (int transaction = 0; transaction <= k * 2; transaction++)
        dp[n][transaction] = 0;

    for (int index = 0; index <= n; index++)
        dp[index][0] = 0;

    for (int index = n - 1; index >= 0; index--)
    {

        for (int transaction = 1; transaction <= k * 2; transaction++)
        {
            int profit;

            // checking of (transaction -1) because transaction is starting from 1 in loop, but we have to check from 0
            if ((transaction - 1) % 2 == 0)
            {
                int selling = prices[index] + dp[index + 1][transaction - 1];
                int not_selling = dp[index + 1][transaction];

                profit = max(selling, not_selling);
            }
            else
            {
                int buying = -prices[index] + dp[index + 1][transaction - 1];
                int not_buying = 0 + dp[index + 1][transaction];

                profit = max(buying, not_buying);
            }

            dp[index][transaction] = profit;
        }
    }

    return dp[0][k * 2];
}

// Space Optimization Approach ------------------------------------------

int maxProfit_SpaceOptimized(int k, vector<int> &prices)
{
    int n = prices.size();

    vector<int> dp(k * 2 + 1, 0), temp(k * 2 + 1, 0);

    // base case
    // just initialize the linear dp with 0

    for (int index = n - 1; index >= 0; index--)
    {
        for (int transaction = 1; transaction <= k * 2; transaction++)
        {
            int profit;

            if ((transaction + 1) % 2 == 0)
            {
                int selling = prices[index] + dp[transaction - 1];
                int not_selling = dp[transaction];

                profit = max(selling, not_selling);
            }
            else
            {
                int buying = -prices[index] + dp[transaction - 1];
                int not_buying = 0 + dp[transaction];

                profit = max(buying, not_buying);
            }

            temp[transaction] = profit;
        }
        dp = temp;
    }

    return dp[k * 2];
}

// Single Array Space Optimization Approach ------------------------------------------

int maxProfit_SingleArraySpaceOptimization(int k, vector<int> &prices)
{
    int n = prices.size();

    vector<int> dp(k * 2 + 1, 0);

    // base case
    // just initialize the linear dp with 0

    for (int index = n - 1; index >= 0; index--)
    {
        for (int transaction = 1; transaction <= k * 2; transaction++)
        {
            int profit;

            if ((transaction - 1) % 2 == 0)
            {
                int selling = prices[index] + dp[transaction - 1];
                int not_selling = dp[transaction];

                profit = max(selling, not_selling);
            }
            else
            {
                int buying = -prices[index] + dp[transaction - 1];
                int not_buying = 0 + dp[transaction];

                profit = max(buying, not_buying);
            }

            dp[transaction] = profit;
        }
    }

    return dp[k * 2];
}