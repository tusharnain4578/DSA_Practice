#include <iostream>
using namespace std;

double pow_xn(double x, int n)
{
    double ans = 1;
    for (int i = 0; i < n; i++)
        ans *= x;

    return ans;
}

double findNthRootOfM(int n, double m)
{
    // Write your code here.
    double low, high;
    if (m < 1)
        low = m, high = 1;
    else
        low = 1, high = m;

    double eps = 1e-6;

    while ((high - low) > eps)
    {
        // cout << low << endl;
        double mid = (low + high) / 2;
        if (pow_xn(mid, n) < m)
            low = mid;
        else
            high = mid;
    }
    return low;
}

int main()
{
    cout << findNthRootOfM(2, 0.5);

    return 0;
}