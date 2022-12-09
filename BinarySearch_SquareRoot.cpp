#include <iostream>
using namespace std;

double sqrt(int x)
{
    int low, high;

    low = 1, high = x / 2; // because square root of a number can't be more than half of it
    int result = 0;
    while (low <= high)
    {
        int mid = (low + high) / 2;

        if (mid * mid == x)
            return mid;
        else if (mid * mid < x)
        {
            low = mid + 1;
            result = mid;
        }
        else
            high = mid - 1;
    }
    return result;
}

int main()
{
    cout << sqrt(8);
    return 0;
}