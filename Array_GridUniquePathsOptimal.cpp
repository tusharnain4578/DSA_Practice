#include <iostream>
#include <cmath>
using namespace std;
// practice --> https://leetcode.com/problems/unique-paths/

int uniquePaths(int m, int n)
{
    // reference ---> https://www.youtube.com/watch?v=t_f0nwwdg5o

    int N = n + m - 2; //(m+n-2) means m-1 + n-1 // we are using m-1 and n-1, becaues m-1 and n-1 are the moves

    // just whover is the minimum, took one less from it

    int r = min(m - 1, n - 1);

    // Now just calculate nCr
    double res = 1;

    for (int i = 1; i <= r; i++)
        res = res * (N - r + i) / i;
    return (int)res;
}

int main()
{
    int m = 5;
    int n = 5;

    cout << uniquePaths(7, 3);

    return 0;
}

// This weill also work
// int uniquePaths(int m, int n)
// {
//     int N = m + n - 2, R = min(m - 1, n - 1);

//     double ans = 1;

//     for (int i = 1; i <= R; i++)
//     {
//         ans = ans * (N--) / i;
//     }
//     return ans;
// }