#include <iostream>
using namespace std;

// practice --> https://leetcode.com/problems/powx-n/
double pow(double x, long long n)
{
    // reference --> https://www.youtube.com/watch?v=G9DbBGLIyPM
    if (n == 0)
        return 1;

    double sub_problem = pow(x, n / 2);

    if (n % 2)
        return x * sub_problem * sub_problem;
    else
        return sub_problem * sub_problem;
}

double getPower(double x, long long n)
{

    if (n < 0)
        return (double)(1) / pow(x, -n);
    else
        return pow(x, n);
}

int main()
{
    cout << getPower(-2, -2);
    return 0;
}