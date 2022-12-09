#include <iostream>
#include <vector>
using namespace std;
// practice ---> https://practice.geeksforgeeks.org/problems/bbt-counter4914/1

// reference (GFG article) --> https://www.geeksforgeeks.org/count-balanced-binary-trees-height-h/

// recursion
long long rec(int h)
{
    if (h == 0 or h == 1)
        return 1;

    // int both_side_equal = rec(h - 1) * rec(h - 1);
    // int left_heavy = rec(h - 1) * rec(h - 2);
    // int right_heavy = rec(h - 2) * rec(h - 1);

    // return both_side_equal + left_heavy + right_heavy;

    // left_heavy and right_heavy are same so we can just take 2*left_heavy or 2*right_heavy

    // so

    // return rec(h - 1) * rec(h - 1) + 2 * rec(h - 1) * rec(h - 2);

    // or even more simplified

    return rec(h - 1) * (rec(h - 1) + 2 * rec(h - 2));
}

long long int countBT_rec(int h)
{
    return rec(h);
}

// memoization
long long mem(int h, vector<long long> &dp)
{
    if (h == 0 or h == 1)
        return 1;

    if (dp[h] != -1)
        return dp[h];

    return dp[h] = mem(h - 1, dp) * (mem(h - 1, dp) + 2 * mem(h - 2, dp));
}

long long int countBT_mem(int h)
{
    vector<long long> dp(h + 1, -1);
    return mem(h, dp);
}

// tabulation
long long int countBT(int h)
{
    vector<long long> dp(h + 1);

    dp[0] = dp[1] = 1;

    for (int i = 2; i <= h; i++)
        dp[i] = dp[i - 1] * (dp[i - 1] + 2 * dp[i - 2]);

    return dp[h];
}

// Space Optimized -> 3 variables
// cannot be more optimized ig
long long int countBT(int h)
{
    long long a, b, c;

    for (int i = 2; i <= h; i++)
    {
        c = b * (b + 2 * a);

        a = b;
        b = c;
    }
    return c; // or b
}

//
//
//
// recursive solution with 1e9+7 mod

int mod = 1e9 + 7;
long long _rec(int h)
{
    if (h == 0 or h == 1)
        return 1;

    return _rec(h - 1) % mod * (_rec(h - 1) % mod + 2 * _rec(h - 2) % mod) % mod;
}

long long int _countBT(int h)
{
    return _rec(h);
}