#include <iostream>
#include <vector>
using namespace std;
// practice ---> https://practice.geeksforgeeks.org/problems/palindromic-patitioning4845/1

// utility function to check if the string from i to j is a palindrome or not
bool isPalindrome(const string &str, int i, int j)
{
    while (i < j)
    {
        if (str[i++] != str[j--])
            return false;
    }
    return true;
}

// recursion
int rec(const string &str, int i, int j)
{
    if (i >= j or isPalindrome(str, i, j))
        return 0;

    int min_result = INT_MAX; // minimum cuts

    for (int k = i; k < j; k++)
    {
        int temp = 1 + rec(str, i, k) + rec(str, k + 1, j);

        if (temp < min_result)
            min_result = temp;
    }

    return min_result;
}

int palindromicPartition(string str)
{
    int n = str.size();

    return rec(str, 0, n - 1);
}

//
//
//
// memoization
int mem(const string &str, int i, int j, vector<vector<int>> &dp)
{
    if (i >= j or isPalindrome(str, i, j))
        return 0;

    if (dp[i][j] != -1)
        return dp[i][j];

    int min_result = INT_MAX; // minimum cuts

    for (int k = i; k < j; k++)
    {
        int temp = 1 + mem(str, i, k, dp) + mem(str, k + 1, j, dp);

        if (temp < min_result)
            min_result = temp;
    }

    return dp[i][j] = min_result;
}

int palindromicPartition(string str)
{
    int n = str.size();

    vector<vector<int>> dp(n, vector<int>(n, -1));

    return mem(str, 0, n - 1, dp);
}

//
//
//
// tabulation
int palindromicPartition(string str)
{
    int n = str.size();

    vector<vector<int>> dp(n, vector<int>(n, 0));

    for (int i = n - 1; i >= 0; i--)
    {
        for (int j = 0; j < n; j++)
        {
            if (isPalindrome(str, i, j))
                dp[i][j] = 0;
            else if (i < j)
            {
                int min_result = INT_MAX;

                for (int k = i; k < j; k++)
                {
                    int temp = 1 + dp[i][k] + dp[k + 1][j];

                    if (temp < min_result)
                        min_result = temp;
                }

                dp[i][j] = min_result;
            }
        }
    }

    return dp[0][n - 1];
}

// The above approaches was the MCM pattern, it's time complexity is O(N^4), yes, 3 loops and 1 loop for checking for palindrome. Which might works some platform (like in gfg, it works), but might not work in some platform (like leetcode). We have to optimize it to up O(N^3), the approach from striver's video

// reference --> https://www.youtube.com/watch?v=_H8V5hJUGd0

// Optimized approach
// in this approach, we're not using i and j, we'll just use single variable i to iterate over string

// recursion

int _rec(const string &str, int &n, int i)
{
    if (i == n)
        return 0;

    int min_result = INT_MAX;

    for (int k = i; k < n; k++)
    {
        if (isPalindrome(str, i, k))
        {
            int temp = 1 + _rec(str, n, k + 1);

            if (temp < min_result)
                min_result = temp;
        }
    }

    return min_result;
}

int palindromicPartition(string str)
{
    int n = str.size();

    return _rec(str, n, 0) - 1; // -1 because this approach is making a cut at end of the string also, so it gives an extra cut, we need to remove that 1 extra cut. The cause of extra cut is the base case
}
//
//
//
// memoization

int _mem(const string &str, int &n, int i, vector<int> &dp)
{
    if (i == n)
        return 0;

    if (dp[i] != -1)
        return dp[i];

    int min_result = INT_MAX;

    for (int k = i; k < n; k++)
    {
        if (isPalindrome(str, i, k))
        {
            int temp = 1 + _mem(str, n, k + 1, dp);

            if (temp < min_result)
                min_result = temp;
        }
    }

    return dp[i] = min_result;
}

int palindromicPartition(string str)
{
    int n = str.size();

    vector<int> dp(n, -1);

    return _mem(str, n, 0, dp) - 1;
}

// tabulation
int palindromicPartition(string str)
{
    int n = str.size();

    vector<int> dp(n + 1);
    dp[n] = 0;

    for (int i = n - 1; i >= 0; i--)
    {
        int min_result = INT_MAX;

        for (int k = i; k < n; k++)
        {
            if (isPalindrome(str, i, k))
            {
                int temp = 1 + dp[k + 1];

                if (temp < min_result)
                    min_result = temp;
            }
        }

        dp[i] = min_result;
    }

    return dp[0] - 1; // -1 for, you know what, you know
}

// PRO TIP
// The calcultion of the isPalindrome function every time, affecting the time complexity. What we can do is store the isPalindrome status from i to j of the string into some 2d matrix (you got it), and precompute that matrix, it will reduce time complexity, and yeah it'll use some extra space, but this is worth mentioning

// below is the approach with precomputing the isPalindrome matrix (it's the approach of the above function (right above to it))

// Note -> To create isPalin 2d matrix, we will use the approach from Count Palindromes from DP_Strings_CountPalindromes.cpp

void isPalinUtility(const string &s, vector<vector<bool>> &isPalin)
{
    int n = s.size();

    for (int i = n - 1; i >= 0; i--)
    {
        for (int j = i; j < n; j++)
        {
            if (i == j) // for single character //base case ya' know
                isPalin[i][j] = true;
            else if (i + 1 == j) // for 2 size string //kinda like base case
                isPalin[i][j] = s[i] == s[j] ? true : false;
            else
            {
                if (s[i] == s[j])
                    isPalin[i][j] = isPalin[i + 1][j - 1];
                else
                    isPalin[i][j] = false;
            }
        }
    }
}

int palindromicPartition(string str)
{
    int n = str.size();

    vector<int> dp(n + 1);
    dp[n] = 0;

    vector<vector<bool>> isPalin(n, vector<bool>(n, false));
    isPalinUtility(str, isPalin);

    for (int i = n - 1; i >= 0; i--)
    {
        int min_result = INT_MAX;

        for (int k = i; k < n; k++)
        {
            if (isPalin[i][k])
            {
                int temp = 1 + dp[k + 1];

                if (temp < min_result)
                    min_result = temp;
            }
        }

        dp[i] = min_result;
    }

    return dp[0] - 1;
}

// Now it's N^2 time, you can even compare on leetcode