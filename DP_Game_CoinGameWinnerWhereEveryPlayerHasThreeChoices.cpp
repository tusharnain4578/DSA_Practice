#include <iostream>
#include <vector>
using namespace std;
// practice--->https://practice.geeksforgeeks.org/problems/geek-and-its-game-of-coins4043/1

// reference --> https://www.youtube.com/watch?v=pDr7wDufgVc

// Note -> reference is highly extremely recommended, even if you understand, just fkin watch it

// Some key notes from reference ->
//  A will win only if
//  -> A loses for (n - x) coins
//  -> A loses for (n - y) coins
//  -> A loses for (n - 1) coins
//
// if any of these is true, A wins

// recursion
int rec(int n, const int &x, const int &y)
{
    if (n == 0)
        return 0;
    if (n == 1)
        return 1;

    // Note-> (only for gfg, only in top-down) -> the gfg practice only work when we execute the n-1 case in last, idk why, all other platforms are working well, ig something wrong in this gfg practice
    int option1 = 1 <= n ? rec(n - 1, x, y) : 1;
    int option2 = x <= n ? rec(n - x, x, y) : 1;
    int option3 = y <= n ? rec(n - y, x, y) : 1;

    if (option1 == 0 or option2 == 0 or option3 == 0) // if we lost in any of the previous state, then we are winning in this state
        return 1;

    return 0;
}

int findWinner(int N, int X, int Y)
{
    return rec(N, X, Y);
}

// memoization
int mem(int n, const int &x, const int &y, vector<int> &dp)
{
    if (n == 0)
        return 0;
    if (n == 1)
        return 1;

    if (dp[n] != -1)
        return dp[n];

    int option1 = 1 <= n ? mem(n - 1, x, y, dp) : 1;
    int option2 = x <= n ? mem(n - x, x, y, dp) : 1;
    int option3 = y <= n ? mem(n - y, x, y, dp) : 1;

    if (option1 == 0 or option2 == 0 or option3 == 0)
        return dp[n] = 1;

    return dp[n] = 0;
}

int findWinner(int N, int X, int Y)
{
    vector<int> dp(N + 1, -1);
    return mem(N, X, Y, dp);
}

// tabulation
int findWinner(int N, int X, int Y)
{
    vector<int> dp(N + 1);

    // base cases
    dp[0] = 0;
    dp[1] = 1;

    for (int n = 2; n <= N; n++)
    {
        int option1 = 1 <= n ? dp[n - 1] : 1;
        int option2 = X <= n ? dp[n - X] : 1;
        int option3 = Y <= n ? dp[n - Y] : 1;

        if (option1 == 0 or option2 == 0 or option3 == 0)
            dp[n] = 1;
        else
            dp[n] = 0;
    }

    return dp[N];
}
// can't be more optimized, ig
//
//
//
//
//
//
//

// Tip-> if either one of the option is 0, we wins
// we are calculating every option, and then making the decision, instead what we could do is bind every option in if condition, and return win if we get los in any case
// like below

int rec(int n, const int &x, const int &y)
{
    if (n == 0)
        return 0;
    if (n == 1)
        return 1;

    if (1 <= n and rec(n - 1, x, y) == 0)
        return 1;
    if (x <= n and rec(n - x, x, y) == 0)
        return 1;
    if (y <= n and rec(n - y, x, y) == 0)
        return 1;

    return 0;
}
int findWinner(int N, int X, int Y)
{
    return rec(N, X, Y);
}

// if we do this in tabulation, this will be the fastest solution imo
int findWinner(int N, int X, int Y)
{
    vector<int> dp(N + 1);

    // base cases
    dp[0] = 0;
    dp[1] = 1;

    for (int n = 2; n <= N; n++)
    {
        if (1 <= n and dp[n - 1] == 0)
            dp[n] = 1;
        else if (X <= n and dp[n - X] == 0)
            dp[n] = 1;
        else if (Y <= n and dp[n - Y] == 0)
            dp[n] = 1;
        else
            dp[n] = 0;
    }

    return dp[N];
}