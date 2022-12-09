#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

void countsort(int a[], int n)
{
    int max = *max_element(a, a + n);
    int count[max + 1];
    memset(count, 0, sizeof(count));

    for (int i = 0; i < n; i++)
        ++count[a[i]];

    // adding consecutively to detect positions of numbers
    for (int i = 1; i < max + 1; i++)
        count[i] += count[i - 1];

    int newArr[n];
    memset(newArr, 0, sizeof(newArr));
    // Scanning original array from right to left
    for (int i = n - 1; i >= 0; i--)
    {
        int in = --count[a[i]];
        newArr[in] = a[i];
    }

    copy(newArr, newArr + n, a);
}

int main()
{
    int a[]{4, 3, 5, 2, 1};
    countsort(a, 5);
    for (auto &&i : a)
    {
        cout << i << " ";
    }

    return 0;
}