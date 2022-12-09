#include <iostream>
using namespace std;

// practice-- > https://leetcode.com/problems/powx-n/

double myPow(double x, int n)
{
    // reference--->https://www.youtube.com/watch?v=l0YC3876qxg
    double ans = 1;
    long long nn = n;
    if (nn < 0)
        nn *= -1;

    while (nn)
    {
        if (nn % 2)
        {
            ans *= x;
            nn--;
        }
        else //((n&1) == 0) ->bitwise condition for even
        {
            x *= x;
            nn /= 2;
        }
    }
    if (n < 0)
        ans = 1 / ans;
    return ans;
}

int main()
{
    cout << myPow(2, 0);
}