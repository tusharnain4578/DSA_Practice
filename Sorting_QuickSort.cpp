#include <iostream>
using namespace std;
// practice --> https://practice.geeksforgeeks.org/problems/quick-sort/1
int partition(int a[], int low, int high)
{
    int pivot = a[low];
    int i = low;
    int j = high;

    while (i < j)
    {
        while (a[i] <= pivot)
            i++;
        while (a[j] > pivot)
            j--;

        if (i < j)
            swap(a[i], a[j]);
    }
    swap(a[j], a[low]);
    return j;
}

void quickSort(int a[], int low, int high)
{
    if (low < high)
    {
        int pi = partition(a, low, high);
        quickSort(a, low, pi - 1);
        quickSort(a, pi + 1, high);
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
    quickSort(a, 0, size - 1);
    displayArray(a, size);
    return 0;
}