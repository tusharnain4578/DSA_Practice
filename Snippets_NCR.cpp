#include <iostream>
#include <cmath>
using namespace std;

// Dynamic programming approach is also availabl

int ncr(int n, int r)
{
    double res = 1;

    for (int i = 1; i <= r; i++)
        res = res * (n - r + i) / i;

    return (int)res;
}
int main()
{
    int n, r;
    cin >> n >> r;
    cout << ncr(n, r);

    return 0;
}

//
int findCatalan(int n)
{
}