#include <iostream>
#include <vector>
using namespace std;

// Please revise in this order
// Recursion -> Memoization -> Tabulation -> Space Optimization

// fibMemoization With Space Complexity O(2n)
int fibRecursive(int n)
{
    if (n <= 1)
        return n;

    return fibRecursive(n - 1) + fibRecursive(n - 2);
}

// fibMemoization With Space Complexity O(2n)
int fibMemoization(int n, vector<int> &dp)
{
    if (n <= 1)
        return n;

    if (dp[n] != -1)
        return dp[n];

    return dp[n] = fibMemoization(n - 1, dp) + fibMemoization(n - 2, dp);
}

// FibTabulation With Space Complexity O(n)
int fibTabaulation(int n)
{
    vector<int> dp(n + 1, -1);
    if (n <= 1)
        return n;

    dp[0] = 0;
    dp[1] = 1;
    for (int i = 2; i <= n; i++)
        dp[i] = dp[i - 1] + dp[i - 2];

    return dp[n];
}

// FibTabulation With Space Complexity O(1)
int OptfibTabaulation(int n)
{
    if (n <= 1)
        return n;

    int n1 = 0, n2 = 1;
    int res;
    for (int i = 2; i <= n; i++)
    {
        res = n1 + n2;
        n1 = n2;
        n2 = res;
    }
    return res;
}

int main()
{
    int n;
    cin >> n;
    // vector<int> dp(n + 1, -1);
    // cout << fibMemoization(n, dp)<<endl;
    // cout << fibTabaulation(n)<<endl;;
    cout << OptfibTabaulation(n);

    return 0;
}