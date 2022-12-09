#include <iostream>
#include <vector>
using namespace std;
int mod = 1e9 + 7; // for modulo operation

// practice ---> https://practice.geeksforgeeks.org/problems/ncr1019/1

// reference --> https://www.youtube.com/watch?v=CMaZ69P1bAc

// recursive solution
int nCr_rec(int n, int r)
{
    if (n == r or r == 0)
        return 1;
    else if (r > n)
        return 0;

    // recursive formula explained --> https://discuss.codechef.com/t/need-some-explanation-on-the-combinatorics-formula-ncr-n-1cr-n-1cr-1/13834
    return nCr_rec(n - 1, r - 1) + nCr_rec(n - 1, r);

    // for modulo
    //  return (nCr_rec(n - 1, r - 1) + nCr_rec(n - 1, r)) % mod;
}

// memoized solution
int mem(int n, int r, vector<vector<int>> &dp)
{
    if (n == r or r == 0)
        return 1;
    else if (r > n)
        return 0;

    if (dp[n][r] != -1)
        return dp[n][r];

    return dp[n][r] = mem(n - 1, r - 1, dp) + mem(n - 1, r, dp);

    // for modulo
    //  return dp[n][r] = (mem(n - 1, r - 1, dp) + mem(n - 1, r, dp))%mod;
}
int nCr_mem(int n, int r)
{
    vector<vector<int>> dp(n + 1, vector<int>(r + 1, -1));

    return mem(n, r, dp);
}

// tabulation approach
int nCr_tebulated(int n, int r)
{
    vector<vector<int>> dp(n + 1, vector<int>(r + 1));

    for (int _n = 0; _n <= n; _n++)
    {
        for (int _r = 0; _r <= r; _r++)
        {
            if (_n == _r or _r == 0)
                dp[_n][_r] = 1;
            else if (_r > _n)
                dp[_n][_r] = 0;
            else
            {
                dp[_n][_r] = dp[_n - 1][_r - 1] + dp[_n - 1][_r];

                // for modulo
                // dp[_n][_r] = (dp[_n - 1][_r - 1] + dp[_n - 1][_r])%mod;
            }
        }
    }

    return dp[n][r];
}

// Space Optimized approach
// but we can further optimize this approach into a single 1d array, just take a look at it, we don't need 2 arrays
int nCr_SpaceOptimized(int n, int r)
{
    vector<int> dp(r + 1);

    for (int _n = 0; _n <= n; _n++)
    {
        vector<int> temp(r + 1);
        for (int _r = 0; _r <= r; _r++)
        {
            if (_n == _r or _r == 0)
                temp[_r] = 1;
            else if (_r > _n)
                temp[_r] = 0;
            else
            {
                temp[_r] = dp[_r - 1] + dp[_r];

                // for modulo
                // temp[_r] = (dp[_r - 1] + dp[_r])%mod;
            }
        }

        dp = temp;
    }

    return dp[r];
}

// Much better optimized approach is using the iterative method, that is this

unsigned long int binomialCoeff(unsigned int n, unsigned int k)
{
    unsigned long int res = 1;

    // Since C(n, k) = C(n, n-k)
    if (k > n - k)
        k = n - k;

    // Calculate value of [n*(n-1)*---*(n-k+1)] / [k*(k-1)*---*1]
    for (int i = 0; i < k; ++i)
    {
        res *= (n - i);
        res /= (i + 1);
    }

    return res;
}
