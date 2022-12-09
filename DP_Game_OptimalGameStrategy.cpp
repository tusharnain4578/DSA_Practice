#include <iostream>
#include <vector>
using namespace std;
// practice ---> https://practice.geeksforgeeks.org/problems/optimal-strategy-for-a-game-1587115620/1

// reference --> https://www.youtube.com/watch?v=ww4V7vRIzSk&t=637s

// recursion

long long rec(int arr[], int i, int j)
{
    if (i == j)        // only one coin left
        return arr[i]; // or return arr[j]

    if (i > j) // no coin left
        return 0;

    long long on_picking_i = arr[i] + min(rec(arr, i + 2, j), rec(arr, i + 1, j - 1));
    long long on_picking_j = arr[j] + min(rec(arr, i + 1, j - 1), rec(arr, i, j - 2));

    return max(on_picking_i, on_picking_j);
}

long long maximumAmount(int arr[], int n)
{
    return rec(arr, 0, n - 1);
}

// memoization

long long mem(int arr[], int i, int j, vector<vector<int>> &dp)
{
    if (i == j)
        return arr[i];

    if (i > j)
        return 0;

    if (dp[i][j] != -1)
        return dp[i][j];

    long long on_picking_i = arr[i] + min(mem(arr, i + 2, j, dp), mem(arr, i + 1, j - 1, dp));
    long long on_picking_j = arr[j] + min(mem(arr, i + 1, j - 1, dp), mem(arr, i, j - 2, dp));

    return dp[i][j] = max(on_picking_i, on_picking_j);
}

long long maximumAmount(int arr[], int n)
{
    vector<vector<int>> dp(n, vector<int>(n, -1));
    return mem(arr, 0, n - 1, dp);
}

// tabulation
// note -> the intuition behind the bottom up is quite heavy, i understand if for now but you have to plot the dp table to understand it

long long maximumAmount(int arr[], int n)
{
    vector<vector<int>> dp(n + 2, vector<int>(n, 0));

    for (int i = 0; i < n; i++) // no need to put this base case separately, just in inner loop, change (i < j) to (i <= j)
        dp[i][i] = arr[i];

    for (int i = n - 1; i >= 0; i--)
    {
        for (int j = 0; j < n; j++)
        {

            if (i < j)
            {
                long long on_picking_i = arr[i] + min(dp[i + 2][j], dp[i + 1][j - 1]);

                long long on_picking_j = arr[j] + min(dp[i + 1][j - 1], dp[i][j - 2]);

                dp[i][j] = max(on_picking_i, on_picking_j);
            }
        }
    }

    return dp[0][n - 1];
}

// Space Optimized

long long maximumAmount(int arr[], int n)
{
    vector<int> dp1(n, 0), dp2(n, 0), dp3(n, 0);

    for (int i = n - 1; i >= 0; i--)
    {
        for (int j = 0; j < n; j++)
        {

            if (i <= j)
            {
                long long on_picking_i = arr[i] + min(dp1[j], dp2[j - 1]);

                long long on_picking_j = arr[j] + min(dp2[j - 1], dp3[j - 2]);

                dp3[j] = max(on_picking_i, on_picking_j);
            }
        }

        dp1 = dp2;
        dp2 = dp3;
    }

    return dp3[n - 1];
}

// can't be more optimized
// the intuition is very easy for memoization but have to swirl your head more for bottom up.
// But once you're used to it, its piece of cake