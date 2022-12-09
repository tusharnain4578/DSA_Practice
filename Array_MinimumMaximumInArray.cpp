#include <iostream>
using namespace std;
#define ll long long

// Simple approach, more than enough
pair<long long, long long> _getMinMax(long long a[], int n)
{
    pair<long long, long long> p;

    p.first = p.second = a[0];

    for (int i = 1; i < n; i++)
    {
        if (a[i] < p.first)
            p.first = a[i];
        else if (a[i] > p.second)
            p.second = a[i];
    }
    return p;
}

// a little bit optimized approach

// must watch to understand why this approach is best
// ---> https://www.youtube.com/watch?v=7CffAoGhKpo

// gfg article to see the comparisons in this approach
//--> https://www.geeksforgeeks.org/maximum-and-minimum-in-an-array/

// practice --> https://practice.geeksforgeeks.org/problems/find-minimum-and-maximum-element-in-an-array4428/1/
pair<long long, long long> getMinMax(long long a[], int n)
{
    pair<long long, long long> mypair;

    int i = 0;

    if (n % 2 == 0)
    {
        if (a[0] < a[1])
        {
            mypair.first = a[0];
            mypair.second = a[1];
        }
        else
        {
            mypair.first = a[1];
            mypair.second = a[0];
        }
        i += 2;
    }
    else // alternative for odd checking, (n & 1) will return true, if n is odd
    {
        mypair.first = mypair.second = a[0];
        i++;
    }
    while (i < n)
    {
        if (a[i] < a[i + 1])
        {
            if (a[i] < mypair.first)
            {
                mypair.first = a[i];
            }
            if (a[i + 1] > mypair.second)
            {
                mypair.second = a[i + 1];
            }
        }
        else
        {
            if (a[i + 1] < mypair.first)
            {
                mypair.first = a[i + 1];
            }
            if (a[i] > mypair.second)
            {
                mypair.second = a[i];
            }
        }
        i += 2;
    }

    return mypair;
}

int main()
{
    long long arr[]{3, 2, 1, 56, 10000, 167};
    pair<ll, ll> mp = getMinMax(arr, 6);
    cout << mp.first << " " << mp.second << endl;
    return 0;
}