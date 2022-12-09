#include <iostream>
using namespace std;
// practice --> https://practice.geeksforgeeks.org/problems/merge-sort/1
//  Merges two subarrays of a[].
//  First subarray is a[low..mid]
//  Second subarray is a[mid+1..high]
void merge(int a[], int low, int mid, int high)
{
    int a1Size = mid - low + 1;
    int a2Size = high - mid;

    // Create temp arrays
    int a1[a1Size], a2[a2Size];

    // Copy data to temp arrays a1[] and a2[]
    for (int i = 0; i < a1Size; i++)
        a1[i] = a[low + i];
    for (int i = 0; i < a2Size; i++)
        a2[i] = a[mid + 1 + i];

    int i = 0;   // Initial index of first sub-array
    int j = 0;   // Initial index of second sub-array
    int k = low; // Initial index of merged array

    // Merge the temp arrays back into a[low..high]
    while (i < a1Size && j < a2Size)
    {
        if (a1[i] < a2[j])
            a[k] = a1[i++];
        else
            a[k] = a2[j++];
        k++;
    }
    // Copy the remaining elements of
    // a1[], if there are any
    while (i < a1Size)
        a[k++] = a1[i++];
    // Copy the remaining elements of
    // a2[], if there are any
    while (j < a2Size)
        a[k++] = a2[j++];
}

// low is for left index and end is
// high index of the sub-array
// of a to be sorted */
void mergesort(int a[], int low, int high)
{
    if (low < high)
    {
        int mid = (low + high) / 2;
        mergesort(a, low, mid);
        mergesort(a, mid + 1, high);
        merge(a, low, mid, high);
    }
}
void displayArray(int a[], int n)
{
    for (int i = 0; i < n; i++)
        cout << a[i] << " ";
}
int main()
{
    int a[]{4, 1, 3, 9, 7};
    int size = sizeof(a) / sizeof(a[0]);
    mergesort(a, 0, size - 1);
    displayArray(a, size);

    return 0;
}