#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
// practice ---> https://practice.geeksforgeeks.org/problems/array-removals/1

// aka Minimum removals from array to make max-min <= k

// the dp solution is taking O(N^2) time and O(N^2) space
// there is more optimized approach using binary search which takeso(N*log(N)) time and constant space, you can find that solution in the Binary Search Section of this folder

// reference ---> https://www.youtube.com/watch?v=kqdoUDVXFik

// recursion
int rec(vector<int> &a, int i, int j, int const &k)
{
    if (i >= j)
        return 0;

    if (a[j] - a[i] <= k)
        return 0;

    int remove_from_i = 1 + rec(a, i + 1, j, k);
    int remove_from_j = 1 + rec(a, i, j - 1, k);

    return min(remove_from_i, remove_from_j);
}

int removals_rec(vector<int> &a, int k)
{
    int n = a.size();

    sort(a.begin(), a.end());

    return rec(a, 0, n - 1, k);
}

// memoization
int mem(vector<int> &a, int i, int j, int const &k, vector<vector<int>> &dp)
{
    if (i >= j)
        return 0;

    if (a[j] - a[i] <= k)
        return 0;

    if (dp[i][j] != -1)
        return dp[i][j];

    int remove_from_i = 1 + mem(a, i + 1, j, k, dp);
    int remove_from_j = 1 + mem(a, i, j - 1, k, dp);

    return dp[i][j] = min(remove_from_i, remove_from_j);
}

int removals_mem(vector<int> &a, int k)
{
    int n = a.size();

    sort(a.begin(), a.end());

    vector<vector<int>> dp(n, vector<int>(n, -1));

    return mem(a, 0, n - 1, k, dp);
}
