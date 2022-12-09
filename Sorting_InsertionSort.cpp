#include <iostream>
using namespace std;

// practice --> https://practice.geeksforgeeks.org/problems/insertion-sort/1
void insertionSort(int arr[], int n)
{
    // code here
    for (int i = 1; i < n; i++)
    {
        int key = arr[i];
        int j = i - 1;

        while (j >= 0 and key < arr[j])
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

int main()
{
    int arr[]{9, 4, 8, 4, 2, 5, 8, 0};
    int n = sizeof(arr) / sizeof(arr[0]);

    insertionSort(arr, n);

    for (int &i : arr)
        cout << i << " ";

    return 0;
}