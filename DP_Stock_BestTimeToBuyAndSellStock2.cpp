#include <iostream>
#include <vector>
using namespace std;
// Buying and Selling allowed infinite times, but can't hold more than one stock

// practice --> https://leetcode.com/problems/best-time-to-buy-and-sell-stock-ii/

// Please revise in this order
// Recursion -> Memoization -> Tabulation -> Space Optimization

//
//
// Approaches ->

// Recursive Approach ------------------------------------------

int rec(vector<int> &prices, int index, int &n, int can_buy)
{
    if (index == n)
        return 0;

    int profit;

    if (can_buy)
    {
        int buying = -prices[index] + rec(prices, index + 1, n, 0);
        int not_buying = 0 + rec(prices, index + 1, n, 1);

        profit = max(buying, not_buying);
    }
    else
    {
        int selling = prices[index] + rec(prices, index + 1, n, 1);
        int not_selling = rec(prices, index + 1, n, 0);

        profit = max(selling, not_selling);
    }

    return profit;
}

int maxProfit_rec(vector<int> &prices)
{
    int n = prices.size();

    return rec(prices, 0, n, 1); // giving the authority to buy, that is can_bay is 1
}

// Recursive Approach ------------------------------------------

int mem(vector<int> &prices, int index, int &n, int can_buy, vector<vector<int>> &dp) // using int in can_buy instead of bool, because we have to initialize it with -1 in dp
{
    if (index == n)
        return 0;

    if (dp[index][can_buy] != -1)
        return dp[index][can_buy];

    int profit;

    if (can_buy)
    {
        int buying = -prices[index] + mem(prices, index + 1, n, 0, dp);
        int not_buying = 0 + mem(prices, index + 1, n, 1, dp);

        profit = max(buying, not_buying);
    }
    else
    {
        int selling = prices[index] + mem(prices, index + 1, n, 1, dp);
        int not_selling = mem(prices, index + 1, n, 0, dp);

        profit = max(selling, not_selling);
    }

    return dp[index][can_buy] = profit;
}

int maxProfit_mem(vector<int> &prices)
{
    int n = prices.size();

    vector<vector<int>> dp(n, vector<int>(2, -1)); // size 2 for only 0 and 1

    return mem(prices, 0, n, 1, dp);
}

// Tabulative Approach ------------------------------------------

int maxProfit_tab(vector<int> &prices)
{
    int n = prices.size();

    vector<vector<int>> dp(n + 1, vector<int>(2)); // size 2 for only 0 and 1

    // base case
    dp[n][0] = dp[n][1] = 0;

    for (int index = n - 1; index >= 0; index--)
    {
        for (int can_buy = 0; can_buy < 2; can_buy++)
        {
            int profit;

            if (can_buy)
            {
                int buying = -prices[index] + dp[index + 1][0];
                int not_buying = 0 + dp[index + 1][1];

                profit = max(buying, not_buying);
            }
            else
            {
                int selling = prices[index] + dp[index + 1][1];
                int not_selling = 0 + dp[index + 1][0];

                profit = max(selling, not_selling);
            }

            dp[index][can_buy] = profit;
        }
    }

    return dp[0][1];
}

// Space Optimized Approach ------------------------------------------

int maxProfit_SpaceOptimized(vector<int> &prices)
{
    int n = prices.size();

    vector<int> dp(2); // size 2 for only 0 and 1

    // base case
    dp[0] = dp[1] = 0;

    for (int index = n - 1; index >= 0; index--)
    {
        vector<int> temp(2);

        for (int can_buy = 0; can_buy < 2; can_buy++)
        {
            int profit;

            if (can_buy)
            {
                int buying = -prices[index] + dp[0];
                int not_buying = 0 + dp[1];

                profit = max(buying, not_buying);
            }
            else
            {
                int selling = prices[index] + dp[1];
                int not_selling = 0 + dp[0];

                profit = max(selling, not_selling);
            }

            temp[can_buy] = profit;
        }
        dp = temp;
    }

    return dp[1];
}