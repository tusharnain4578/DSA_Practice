#include <iostream>
#include <algorithm> //for max_element
#include <cstring>   //for memset
using namespace std;

void countsort(int a[], int n)
{
    int max = *max_element(a, a + n);
    int hash[max + 1];
    memset(hash, 0, sizeof(hash));
    for (int i = 0; i < n; i++)
        ++hash[a[i]];

    int i = 0, j = 0;
    while (i < max + 1)
    {
        if (hash[i] > 0)
        {
            a[j++] = i;
            hash[i]--;
        }
        else
            i++;
    }
}

void displayArray(int a[], int n)
{
    for (int i = 0; i < n; i++)
        cout << a[i] << " ";
}

int main()
{
    int a[]{6, 5, 4, 2, 3, 1};
    int size = sizeof(a) / sizeof(a[0]);
    countsort(a, size);
    displayArray(a, size);
    return 0;
}