#include <iostream>
using namespace std;
// practice --> https://practice.geeksforgeeks.org/problems/cyclically-rotate-an-array-by-one2614/1/
void rotate(int arr[], int n)
{
    int last_element = arr[n - 1];

    int i;
    for (i = n - 1; i > 0; i--)
        arr[i] = arr[i - 1];

    arr[i] = last_element;
}

int main()
{
    int arr[]{1, 2, 3, 4, 5};
    int n = sizeof(arr) / sizeof(arr[0]);
    rotate(arr, n);
    for (auto &&i : arr)
    {
        cout << i << " ";
    }

    return 0;
}