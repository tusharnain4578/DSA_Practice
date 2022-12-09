// Only one transaction is allowed
#include <iostream>
#include <vector>
using namespace std;
// Buying and Selling can only be done once

// practice --> https://leetcode.com/problems/best-time-to-buy-and-sell-stock/

int maxProfit(vector<int> &prices)
{
    // reference --> https://www.youtube.com/watch?v=2FROyvnnrrM
    int min_price = prices[0];
    int profit = 0;
    for (int i = 1; i < prices.size(); i++)
    {
        if (prices[i] < min_price)
            min_price = prices[i];
        else if (prices[i] - min_price > profit)
            profit = prices[i] - min_price;
    }
    return profit;
}
int main()
{
    vector<int> prices{7, 1, 5, 3, 6, 4};
    cout << maxProfit(prices);

    return 0;
}