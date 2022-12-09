#include <iostream>
#include <vector>
using namespace std;
// practice ---> https://practice.geeksforgeeks.org/problems/friends-pairing-problem5425/1

// reference ---> https://www.youtube.com/watch?v=wOtRnD0f7Y

// recursive approach
int rec(int n)
{
    if (n <= 2)
        return n;

    int solo = rec(n - 1);
    int pairing = (n - 1) * rec(n - 2);

    return solo + pairing;
}

int countFriendsPairings(int n)
{
    return rec(n);
}

// Memoization approach
int mem(int n, vector<int> &dp)
{
    if (n <= 2)
        return n;

    if (dp[n] != -1)
        return dp[n];

    int solo = mem(n - 1, dp);
    int pairing = (n - 1) * mem(n - 2, dp);

    return dp[n] = solo + pairing;
}

int countFriendsPairings_mem(int n)
{
    vector<int> dp(n + 1, -1);
    return mem(n, dp);
}

// Tabulation approach
int countFriendsPairings_tab(int n)
{
    vector<int> dp(n + 1);

    // base case
    for (int i = 0; i <= 2; i++)
        dp[i] = i;

    for (int i = 3; i <= n; i++)
    {
        int solo = dp[i - 1];
        int pairing = (i - 1) * dp[i - 2];

        dp[i] = solo + pairing;
    }

    return dp[n];
}

// Space Optimized approach
int countFriendsPairings_SpaceOptimized(int n)
{
    if (n <= 2)
        return n;

    // base case
    int a = 0, b = 1, c = 2;

    for (int i = 3; i <= n; i++)
    {
        int solo = c;
        int pairing = (i - 1) * b;

        a = solo + pairing;

        // variable data interchanging
        b = c;
        c = a;
    }

    return a;
}

// GFG practice is asking for 1e9+7 modulo, solution given below

// Memoization approach
int mod = 1e9 + 7; // modulo
long long mem(int n, vector<long long> &dp)
{
    if (n <= 2)
        return n;

    if (dp[n] != -1)
        return dp[n];

    long long solo = mem(n - 1, dp);
    long long pairing = ((n - 1) % mod * mem(n - 2, dp) % mod) % mod;

    return dp[n] = (solo + pairing) % mod;
}

int countFriendsPairings(int n)
{
    vector<long long> dp(n + 1, -1);
    return mem(n, dp);
}