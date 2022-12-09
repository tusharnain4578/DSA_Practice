#include <iostream>
using namespace std;
// practice --> https://practice.geeksforgeeks.org/problems/sort-an-array-of-0s-1s-and-2s4231/1/

// Sorting of only 0, 1, and 2s
void dnfsort(int a[], int n)
{
    int low = 0;
    int mid = 0;
    int high = n - 1;

    while (mid <= high) // remeber it's while(mid <= high), not low<= high
    {
        if (a[mid] == 0)
            swap(a[mid++], a[low++]);
        else if (a[mid] == 1)
            mid++;
        else if (a[mid] == 2)
            swap(a[mid], a[high--]);
    }
}

int main()
{
    int arr[] = {0, 1, 1, 0, 1, 2, 1, 2, 0, 0, 0, 1};
    int n = sizeof(arr) / sizeof(arr[0]);

    dnfsort(arr, n);

    for (auto &&i : arr)
    {
        cout << i << " ";
    }

    return 0;
}

// if (a[mid] == 0)
//     swap(a[mid++], a[low++]); -> Don't try to do this mistake, use switch or if-else, other
// if (a[mid] == 1)        wise swapped element will again get swap
//     mid++;

// if (a[mid] == 2)
//     swap(a[mid], a[high--]);