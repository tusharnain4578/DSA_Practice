// RadixSort uses count sort as subroutine
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

void countsort(int a[], int n, int exp)
{
    int count[10];
    memset(count, 0, sizeof(count));
    for (int i = 0; i < n; i++)
        ++count[(a[i] / exp) % 10];

    // update count consecutively for storeing element's position
    for (int i = 1; i < 10; i++)
        count[i] += count[i - 1];

    int newArr[n];
    memset(newArr, 0, sizeof(newArr));

    for (int i = n - 1; i >= 0; i--)
    {
        int in = --count[(a[i] / exp) % 10];
        newArr[in] = a[i];
    }
    copy(newArr, newArr + n, a);
}

void radixsort(int a[], int n)
{
    int max = *max_element(a, a + n);

    for (int i = 1; max / i > 0; i *= 10)
        countsort(a, n, i);
}

int main()
{
    int a[]{6, 3, 2, 4, 1, 5};
    radixsort(a, 6);
    for (auto &&i : a)
    {
        cout << i << " ";
    }

    return 0;
}