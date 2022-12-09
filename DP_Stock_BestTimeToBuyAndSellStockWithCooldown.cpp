#include <iostream>
#include <vector>
using namespace std;

//
//

// Approaches ->

// Recursive Approach ------------------------------------------

int rec(vector<int> prices, int index, int &n, int can_buy)
{
    if (index >= n)
        return 0;

    int profit;

    if (can_buy)
    {
        int buying = -prices[index] + rec(prices, index + 1, n, 0);
        int not_buying = rec(prices, index + 1, n, 1);

        profit = max(buying, not_buying);
    }
    else
    {
        int selling = +prices[index] + rec(prices, index + 2, n, 1);
        int not_selling = rec(prices, index + 1, n, 0);

        profit = max(selling, not_selling);
    }

    return profit;
}

int maxProfit_rec(vector<int> &prices)
{
    int n = prices.size();

    return rec(prices, 0, n, 1);
}

// Memoized Approach ------------------------------------------

int mem(vector<int> prices, int index, int &n, int can_buy, vector<vector<int>> &dp)
{
    if (index >= n)
        return 0;

    if (dp[index][can_buy] != -1)
        return dp[index][can_buy];

    int profit;

    if (can_buy)
    {
        int buying = -prices[index] + mem(prices, index + 1, n, 0, dp);
        int not_buying = mem(prices, index + 1, n, 1, dp);

        profit = max(buying, not_buying);
    }
    else
    {
        int selling = +prices[index] + mem(prices, index + 2, n, 1, dp);
        int not_selling = mem(prices, index + 1, n, 0, dp);

        profit = max(selling, not_selling);
    }

    return dp[index][can_buy] = profit;
}

int maxProfit_mem(vector<int> &prices)
{
    int n = prices.size();

    vector<vector<int>> dp(n, vector<int>(2, -1));

    return mem(prices, 0, n, 1, dp);
}

// Tabulated Approach ------------------------------------------

int maxProfit_tab(vector<int> &prices)
{
    int n = prices.size();

    vector<vector<int>> dp(n + 2, vector<int>(2)); // n+2, because we're gonna look for index+2

    dp[n][0] = dp[n][1] = 0;
    dp[n + 1][0] = dp[n + 1][1] = 0;

    for (int index = n - 1; index >= 0; index--)
    {
        for (int can_buy = 0; can_buy < 2; can_buy++)
        {
            int profit;

            if (can_buy)
            {
                int buying = -prices[index] + dp[index + 1][0];
                int not_buying = dp[index + 1][1];

                profit = max(buying, not_buying);
            }
            else
            {
                int selling = +prices[index] + dp[index + 2][1];
                int not_selling = dp[index + 1][0];

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

    vector<int> dp1(2, 0);
    vector<int> dp2(2, 0);

    for (int index = n - 1; index >= 0; index--)
    {
        vector<int> temp(2);
        for (int can_buy = 0; can_buy < 2; can_buy++)
        {
            int profit;

            if (can_buy)
            {
                int buying = -prices[index] + dp1[0];
                int not_buying = dp1[1];

                profit = max(buying, not_buying);
            }
            else
            {
                int selling = +prices[index] + dp2[1];
                int not_selling = dp1[0];

                profit = max(selling, not_selling);
            }

            temp[can_buy] = profit;
        }
        dp2 = dp1;
        dp1 = temp;
    }

    return dp1[1];
}