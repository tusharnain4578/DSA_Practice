#include <iostream>
#include <vector>
#include <numeric>
using namespace std;
// practice ---> https://practice.geeksforgeeks.org/problems/mobile-numeric-keypad5456/1

// reference --> https://www.youtube.com/watch?v=xaKENHcJts4
// Kind'a like DP with BFS

// but... the dfs can be only used with rec and mem, for tabulation there's another approach which is mentioned in bottom of this file, which is btw faster than the dfs, isn't that fascinating, it's obvious

// recursion
long long rec(int i, int j, int n, vector<vector<short>> &keypad)
{
    if (i < 0 or j < 0 or i >= 4 or j >= 3 or keypad[i][j] == -1)
        return 0;

    if (n == 1)
        return 1;

    // There are 5 possibilities,1 is to press it self, and 4 is other 4 directions
    long long itself = rec(i, j, n - 1, keypad);
    long long up = rec(i - 1, j, n - 1, keypad);
    long long down = rec(i + 1, j, n - 1, keypad);
    long long left = rec(i, j - 1, n - 1, keypad);
    long long right = rec(i, j + 1, n - 1, keypad);

    return itself + up + down + left + right;
}

long long getCount(int N)
{
    vector<vector<short>> keypad{{1, 2, 3}, {4, 5, 6}, {7, 8, 9}, {-1, 0, -1}};

    long long ans = 0;

    for (int i = 0; i < 4; i++)
        for (int j = 0; j < 3; j++)
            ans += rec(i, j, N, keypad);

    return ans;
}

//
//
// memoization

// NOTE* -> Although there are three parameters are changing i.e, i, j and n.
// but, think, think harder, i and j representing a single number from the keypad, so instead of 3d dp, we can use 2d dp i.e, dp[10][N] where 10 is total valid keypad numbers

// although 3d dp will also work as same, because in 2d, we will do dp[10][N]
// and in 3d we will do d[4][3][k], i.e, 4x3 = 12, so dp[12][k], they're same

// you can do either ways, they are same, imma going with 2D

long long mem(int i, int j, int n, vector<vector<short>> &keypad, vector<vector<long long>> &dp)
{
    if (i < 0 or j < 0 or i >= 4 or j >= 3 or keypad[i][j] == -1)
        return 0;

    if (n == 1)
        return 1;

    if (dp[keypad[i][j]][n] != -1)
        return dp[keypad[i][j]][n];

    long long itself = mem(i, j, n - 1, keypad, dp);
    long long up = mem(i - 1, j, n - 1, keypad, dp);
    long long down = mem(i + 1, j, n - 1, keypad, dp);
    long long left = mem(i, j - 1, n - 1, keypad, dp);
    long long right = mem(i, j + 1, n - 1, keypad, dp);

    return dp[keypad[i][j]][n] = itself + up + down + left + right;
}

long long getCount(int N)
{
    vector<vector<short>> keypad{{1, 2, 3}, {4, 5, 6}, {7, 8, 9}, {-1, 0, -1}};

    long long ans = 0;

    vector<vector<long long>> dp(10, vector<long long>(N + 1, -1));

    for (int i = 0; i < 4; i++)
        for (int j = 0; j < 3; j++)
            ans += mem(i, j, N, keypad, dp);

    return ans;
}

//
//
//
//
//
//
//
//
//
// The above memoizaition cannot be directly converted into tabulation
// even if somehow it did, its not worth it,
// but....
// here, this method is very much intuitive and simple to think of for tabulation
// reference --> https://www.youtube.com/watch?v=IN3uTs8afz4

// This one is the faster approach
// also, we don't need to create a keypad matrix here

// tabulation
long long getCount(int N)
{
    // making the data graph for each number
    vector<vector<int>> dataGraph{
        {0, 8},          // for 0
        {1, 2, 4},       // for 1
        {1, 2, 3, 5},    // for 2
        {2, 3, 6},       // for 3
        {1, 4, 5, 7},    // for 4
        {2, 4, 5, 6, 8}, // for 5
        {3, 5, 6, 9},    // for 6
        {4, 7, 8},       // for 7
        {5, 7, 8, 9, 0}, // for 8
        {6, 8, 9}};      // for 9

    vector<vector<long long>> dp(N + 1, vector<long long>(10));

    for (int i = 0; i < 10; i++)
        dp[1][i] = 1;

    for (int i = 2; i <= N; i++)
        for (int j = 0; j < 10; j++)
            for (const int &k : dataGraph[j])
                dp[i][j] += dp[i - 1][k];

    // just the sum of the last row of dp table
    return accumulate(dp[N].begin(), dp[N].end(), (long long)0);
}

// Space Optimized -> Constant Space, i.e, O(1) Space 🔥🔥🔥
long long getCount(int N)
{
    // making the data graph for each number
    vector<vector<int>> dataGraph{
        {0, 8},
        {1, 2, 4},
        {1, 2, 3, 5},
        {2, 3, 6},
        {1, 4, 5, 7},
        {2, 4, 5, 6, 8},
        {3, 5, 6, 9},
        {4, 7, 8},
        {5, 7, 8, 9, 0},
        {6, 8, 9}};

    vector<long long> dp(10);

    for (int i = 0; i < 10; i++)
        dp[i] = 1;

    for (int i = 2; i <= N; i++)
    {
        vector<long long> temp(10);

        for (int j = 0; j < 10; j++)
        {
            for (const int &k : dataGraph[j])
                temp[j] += dp[k];
        }

        dp = temp;
    }

    return accumulate(dp.begin(), dp.end(), (long long)0);
}