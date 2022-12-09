#include <iostream>
#include <vector>
using namespace std;
// practice ---> https://practice.geeksforgeeks.org/problems/interleaved-strings/1

// recursion
bool rec(int m, int n, int len, const string &A, const string &B, const string &C)
{
    if (len == 0)
        return true;

    bool a = false, b = false;

    if (m - 1 >= 0 and A[m - 1] == C[len - 1])
        a = rec(m - 1, n, len - 1, A, B, C);

    if (n - 1 >= 0 and B[n - 1] == C[len - 1])
        b = rec(m, n - 1, len - 1, A, B, C);

    return a or b;
}

bool isInterleave(string A, string B, string C)
{
    int ASize = A.size(), BSize = B.size(), CSize = C.size();

    if (ASize + BSize != CSize)
        return false;

    vector<vector<int>> dp(ASize + 1, vector<int>(BSize + 1, -1));

    return rec(ASize, BSize, CSize, A, B, C);
}

// memoization
bool mem(int m, int n, int len, const string &A, const string &B, const string &C, vector<vector<int>> &dp)
{
    if (len == 0)
        return true;

    if (dp[m][n] != -1)
        return dp[m][n];

    bool a = false, b = false;

    if (m - 1 >= 0 and A[m - 1] == C[len - 1])
        a = mem(m - 1, n, len - 1, A, B, C, dp);

    if (n - 1 >= 0 and B[n - 1] == C[len - 1])
        b = mem(m, n - 1, len - 1, A, B, C, dp);

    return dp[m][n] = a or b;
}

bool isInterleave(string A, string B, string C)
{
    int ASize = A.size(), BSize = B.size(), CSize = C.size();

    if (ASize + BSize != CSize)
        return false;

    vector<vector<int>> dp(ASize + 1, vector<int>(BSize + 1, -1));

    return mem(ASize, BSize, CSize, A, B, C, dp);
}

// tabulation
bool isInterleave(string A, string B, string C)
{
    int ASize = A.size(), BSize = B.size(), CSize = C.size();

    if (ASize + BSize != CSize)
        return false;

    vector<vector<int>> dp(ASize + 1, vector<int>(BSize + 1));

    for (int m = 1; m <= ASize; m++)
    {
        for (int n = 1; n <= BSize; n++)
        {
            bool a = false, b = false;

            if (m - 1 >= 0 and A[m - 1] == C[len - 1])
                a = mem(m - 1, n, len - 1, A, B, C, dp);

            if (n - 1 >= 0 and B[n - 1] == C[len - 1])
                b = mem(m, n - 1, len - 1, A, B, C, dp);

            return dp[m][n] = a or b;
        }
    }

    return mem(ASize, BSize, CSize, A, B, C, dp);
}