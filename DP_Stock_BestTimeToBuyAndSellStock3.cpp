#include <iostream>
#include <vector>
using namespace std;

// practice --> https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iii/
//
//
//
// Buying and Selling allowed for only 2 times

// 3d DP

// Please revise in this order
// Recursion -> Memoization -> Tabulation -> Space Optimization
//
// Entire same code as BestTimeToBuyAndSellStock2 but with transaction arguments
//
//
// Approaches ->

// Recursive Approach ------------------------------------------

int rec(vector<int> &prices, int index, int &n, int can_buy, int transaction)
{
    if (index == n or transaction == 0)
        return 0;

    int profit;

    if (can_buy)
    {
        int buying = -prices[index] + rec(prices, index + 1, n, 0, transaction);
        int not_buying = 0 + rec(prices, index + 1, n, 1, transaction);

        profit = max(buying, not_buying);
    }
    else
    {
        int selling = prices[index] + rec(prices, index + 1, n, 1, transaction - 1);
        int not_selling = rec(prices, index + 1, n, 0, transaction);

        profit = max(selling, not_selling);
    }

    return profit;
}

int maxProfit_rec(vector<int> &prices)
{
    int n = prices.size();

    return rec(prices, 0, n, 1, 2); // giving the authority to buy, that is can_bay is 1
}

// Memoized Approach ------------------------------------------

int mem(vector<int> &prices, int index, int &n, int can_buy, int transaction, vector<vector<vector<int>>> &dp)
{
    if (index == n or transaction == 0)
        return 0;

    if (dp[index][can_buy][transaction] != -1)
        return dp[index][can_buy][transaction];

    int profit;

    if (can_buy)
    {
        int buying = -prices[index] + mem(prices, index + 1, n, 0, transaction, dp);
        int not_buying = 0 + mem(prices, index + 1, n, 1, transaction, dp);

        profit = max(buying, not_buying);
    }
    else
    {
        int selling = prices[index] + mem(prices, index + 1, n, 1, transaction - 1, dp);
        int not_selling = mem(prices, index + 1, n, 0, transaction, dp);

        profit = max(selling, not_selling);
    }

    return dp[index][can_buy][transaction] = profit;
}

int maxProfit_mem(vector<int> &prices)
{
    int n = prices.size();

    vector<vector<vector<int>>> dp(n, vector<vector<int>>(2, vector<int>(3, -1))); // 3d DP

    return mem(prices, 0, n, 1, 2, dp);
}

// Tabulative Approach ------------------------------------------

int maxProfit_tab(vector<int> &prices)
{
    int n = prices.size();

    vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(2, vector<int>(3))); // 3d DP

    // watch TUF video of this topic, you'll get the best idea to make the base case

    // base cases
    // tip, just initialize the entire dp with 0, in the vector, initialization
    for (int can_buy = 0; can_buy < 2; can_buy++)
    {
        for (int transaction = 0; transaction < 3; transaction++)
        {
            dp[n][can_buy][transaction] = 0;
        }
    }

    for (int index = 0; index < n; index++)
    {
        for (int can_buy = 0; can_buy < 2; can_buy++)
        {
            dp[index][can_buy][0] = 0;
        }
    }

    for (int index = n - 1; index >= 0; index--)
    {
        for (int can_buy = 0; can_buy < 2; can_buy++)
        {
            for (int transaction = 1; transaction < 3; transaction++) // transaction 0 is handled in base case, that's why for loop is starting from 1
            {
                int profit;

                if (can_buy)
                {
                    int buying = -prices[index] + dp[index + 1][0][transaction];
                    int not_buying = 0 + dp[index + 1][1][transaction];

                    profit = max(buying, not_buying);
                }
                else
                {
                    int selling = prices[index] + dp[index + 1][1][transaction - 1];
                    int not_selling = dp[index + 1][0][transaction];

                    profit = max(selling, not_selling);
                }

                dp[index][can_buy][transaction] = profit;
            }
        }
    }

    return dp[0][1][2];
}

// Space Optimized Approach
// Constant Space 🔥🔥🔥🔥🔥
// ------------------------------------------

int maxProfit_SpaceOptimized(vector<int> &prices)
{
    int n = prices.size();

    vector<vector<int>> dp(2, vector<int>(3, 0));

    // base cases
    // tip, just initialize the entire dp with 0, in the vector, initialization
    for (int can_buy = 0; can_buy < 2; can_buy++)
    {
        for (int transaction = 0; transaction < 3; transaction++)
        {
            dp[can_buy][transaction] = 0;
        }
    }

    for (int can_buy = 0; can_buy < 2; can_buy++)
    {
        dp[can_buy][0] = 0;
    }

    for (int index = n - 1; index >= 0; index--)
    {
        vector<vector<int>> temp(2, vector<int>(3));

        for (int can_buy = 0; can_buy < 2; can_buy++)
        {

            for (int transaction = 1; transaction < 3; transaction++) // transaction 0 is handled in base case, that's why for loop is starting from 1
            {
                int profit;

                if (can_buy)
                {
                    int buying = -prices[index] + dp[0][transaction];
                    int not_buying = 0 + dp[1][transaction];

                    profit = max(buying, not_buying);
                }
                else
                {
                    int selling = prices[index] + dp[1][transaction - 1];
                    int not_selling = dp[0][transaction];

                    profit = max(selling, not_selling);
                }

                temp[can_buy][transaction] = profit;
            }
        }
        dp = temp;
    }

    return dp[1][2];
}

//         METHOD 2
// **************************************************
// **************************************************
// **************************************************
// **************************************************
// *************** BETTER APPROACH*******************
// ************WITH DP[N][4] Memoization*************
// **************************************************
// **The above approach is also fine, but you can****
// **********practice this if you want***************
// **************************************************
// **************************************************

// Here you don't neet can_buy variable, the transaction variable will do that
//
// Intuition
// 2 transactions allowed
//
// if 0 -> 3
// Buy  Sell  Buy  Sell
//  0    1     2    3
// If you observe carefully, we're only buying on 0,2 i.e, on even number and selling only on 1, 3 i.e, on odd number
// And we will set the base case of (transaction == 4)
//
//
//

// Approaches ->

// Recursive Approach ------------------------------------------

int rec(vector<int> &prices, int index, int &n, int transaction)
{
    if (index == n or transaction == 4)
        return 0;

    int profit;

    if (transaction % 2 == 0)
    {
        int buying = -prices[index] + rec(prices, index + 1, n, transaction + 1);
        int not_buying = 0 + rec(prices, index + 1, n, transaction);

        profit = max(buying, not_buying);
    }
    else
    {
        int selling = prices[index] + rec(prices, index + 1, n, transaction + 1);
        int not_selling = rec(prices, index + 1, n, transaction);

        profit = max(selling, not_selling);
    }

    return profit;
}

int maxProfit_rec(vector<int> &prices)
{
    int n = prices.size();

    return rec(prices, 0, n, 0);
}

// Memoized Approach ------------------------------------------

int mem(vector<int> &prices, int index, int &n, int transaction, vector<vector<int>> &dp)
{
    if (index == n or transaction == 4)
        return 0;

    if (dp[index][transaction] != -1)
        return dp[index][transaction];

    int profit;

    if (transaction % 2 == 0)
    {
        int buying = -prices[index] + mem(prices, index + 1, n, transaction + 1, dp);
        int not_buying = 0 + mem(prices, index + 1, n, transaction, dp);

        profit = max(buying, not_buying);
    }
    else
    {
        int selling = prices[index] + mem(prices, index + 1, n, transaction + 1, dp);
        int not_selling = mem(prices, index + 1, n, transaction, dp);

        profit = max(selling, not_selling);
    }

    return dp[index][transaction] = profit;
}

int maxProfit_mem(vector<int> &prices)
{
    int n = prices.size();

    vector<vector<int>> dp(n, vector<int>(4, -1)); // 3d DP

    return mem(prices, 0, n, 0, dp);
}

// Tabulative Approach ------------------------------------------

int maxProfit_tab(vector<int> &prices)
{
    int n = prices.size();

    vector<vector<int>> dp(n + 1, vector<int>(5)); // 4 + 1 = 5, 1 extra for base case

    // watch TUF video of this topic, you'll get the best idea to make the base case

    // base cases
    for (int transaction = 0; transaction <= 4; transaction++)
        dp[n][transaction] = 0;

    for (int index = 0; index <= n; index++)
        dp[index][4] = 0;

    for (int index = n - 1; index >= 0; index--)
    {

        for (int transaction = 3; transaction >= 0; transaction--)
        {
            int profit;

            if (transaction % 2 == 0)
            {
                int buying = -prices[index] + dp[index + 1][transaction + 1];
                int not_buying = 0 + dp[index + 1][transaction];

                profit = max(buying, not_buying);
            }
            else
            {
                int selling = prices[index] + dp[index + 1][transaction + 1];
                int not_selling = dp[index + 1][transaction];

                profit = max(selling, not_selling);
            }

            dp[index][transaction] = profit;
        }
    }

    return dp[0][0];
}

// Space Optimization Approach ------------------------------------------
// Constant Space 🔥🔥🔥🔥🔥

int maxProfit_SpaceOptimized(vector<int> &prices)
{
    int n = prices.size();

    vector<int> dp(5, 0), temp(5, 0);

    // just initialize the linear dp with 0

    for (int index = n - 1; index >= 0; index--)
    {
        for (int transaction = 3; transaction >= 0; transaction--)
        {
            int profit;

            if (transaction % 2 == 0)
            {
                int buying = -prices[index] + dp[transaction + 1];
                int not_buying = 0 + dp[transaction];

                profit = max(buying, not_buying);
            }
            else
            {
                int selling = prices[index] + dp[transaction + 1];
                int not_selling = dp[transaction];

                profit = max(selling, not_selling);
            }

            temp[transaction] = profit;
        }
        dp = temp;
    }

    return dp[0];
}

// Single Array Space Optimization Approach ------------------------------------------
// Constant Space 🔥🔥🔥🔥🔥

int maxProfit_SingleArraySpaceOptimization(vector<int> &prices)
{
    int n = prices.size();

    vector<int> dp(5, 0);

    // base case
    // just initialize the linear dp with 0

    for (int index = n - 1; index >= 0; index--)
    {
        for (int transaction = 3; transaction >= 0; transaction--)
        {
            int profit;

            if (transaction % 2 == 0)
            {
                int buying = -prices[index] + dp[transaction + 1];
                int not_buying = 0 + dp[transaction];

                profit = max(buying, not_buying);
            }
            else
            {
                int selling = prices[index] + dp[transaction + 1];
                int not_selling = dp[transaction];

                profit = max(selling, not_selling);
            }

            dp[transaction] = profit;
        }
    }

    return dp[0];
}