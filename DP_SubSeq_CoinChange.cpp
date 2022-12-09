#include <iostream>
#include <vector>
using namespace std;
// practice (recommended) ---> https://practice.geeksforgeeks.org/problems/coin-change2448/1
//  practice --> https://www.codingninjas.com/codestudio/problems/ways-to-make-coin-change_630471

// using space optimized solution of Minimum coin exchange
// just return 1, if you completed the target sum, otherwise 0
long minCoins_SpaceOptimized(int *coins, int n, int V)
{

    vector<long> dp(V + 1); // dp

    for (long index = 0; index < n; index++)
    {
        vector<long> temp(V + 1);

        for (long target = 0; target <= V; target++)
        {
            if (index == 0)
            {
                if (target % coins[index] == 0)
                    temp[target] = 1;
                else
                    temp[target] = 0;
            }
            else
            {
                long pick = coins[index] <= target ? temp[target - coins[index]] : 0;
                long non_pick = dp[target];

                temp[target] = pick + non_pick;
            }
        }
        dp = temp;
    }

    long ans = dp[V];
    // if(ans >= 1e9) return -1;
    // else return ans;

    return ans;
}

long countWaysToMakeChange(int *denominations, int n, int value)
{
    return minCoins_SpaceOptimized(denominations, n, value);
}