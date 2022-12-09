#include <iostream>
#include <vector>
using namespace std;
// practice ---> https://practice.geeksforgeeks.org/problems/painting-the-fence3727/1

// reference --> https://www.youtube.com/watch?v=5eFh5CC-8KY

// recursion
long long countWays(int n, int k)
{
    if (n == 1)
        return k;
    else if (n == 2)
        return k * k;

    long long same = countWays(n - 2, k) * (k - 1);
    long long diff = countWays(n - 1, k) * (k - 1);

    return same + diff;
}

// memoization
long long mem(int n, int k, vector<long long> &dp)
{
    if (n == 1)
        return k;
    else if (n == 2)
        return k * k;

    if (dp[n] != -1)
        return dp[n];

    long long same = mem(n - 2, k, dp) * (k - 1);
    long long diff = mem(n - 1, k, dp) * (k - 1);

    return dp[n] = same + diff;
}

long long countWays(int n, int k)
{
    vector<long long> dp(n + 1, -1);

    return mem(n, k, dp);
}

// tabulation
long long countWays(int n, int k)
{
    vector<long long> dp(n + 1);

    // base case
    dp[1] = k;
    dp[2] = k * k;

    for (int i = 3; i <= n; i++)
    {
        long long same = dp[i - 2] * (k - 1);
        long long diff = dp[i - 1] * (k - 1);

        dp[i] = same + diff;
    }

    return dp[n];
}

// Space Optimized Solution
long long countWays(int n, int k)
{

    // base case
    long long a = k;
    long long b = k * k;

    if (n == 1)
        return a;
    else if (n == 2)
        return b;

    for (int i = 3; i <= n; i++)
    {
        long long same = a * (k - 1);
        long long diff = b * (k - 1);

        a = b;
        b = same + diff;
    }

    return b;
}