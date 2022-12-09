#include <iostream>
using namespace std;

// practice ---> https://practice.geeksforgeeks.org/problems/remove-duplicate-elements-from-sorted-array/1/#
int removeDuplicates(int arr[], int n)
{
    int in = 0;
    for (int i = 0; i < n - 1; i++)
        if (arr[i] != arr[i + 1])
            arr[in++] = arr[i];

    arr[in++] = arr[n - 1];
    return in;
}

int main()
{
    int a[]{1, 1, 2, 2, 2, 3, 3, 4, 5, 5, 5, 5};
    int j = removeDuplicates(a, 12);
    for (int i = 0; i < j; i++)
        cout << a[i] << " ";

    return 0;
}