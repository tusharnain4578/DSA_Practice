#include <iostream>
using namespace std;

// practice --> https://practice.geeksforgeeks.org/problems/heap-sort/1#
void maxHeapify(int a[], int n, int i)
{
    int largest = i;
    int lchild = 2 * i + 1; // Left Child
    int rchild = 2 * i + 2; // Right Child

    if (lchild < n && a[lchild] > a[largest])
        largest = lchild;
    if (rchild < n && a[rchild] > a[largest])
        largest = rchild;

    // If largest is updated, swap that with a[i], and heapify further corresponding heap
    if (i != largest)
    {
        swap(a[i], a[largest]);
        maxHeapify(a, n, largest);
    }
}

void heapsort(int a[], int n)
{
    // Create Heap
    for (int i = n / 2 - 1; i >= 0; i--)
        maxHeapify(a, n, i);

    for (int i = n - 1; i > 0; i--)
    {
        // Swap first and last
        swap(a[i], a[0]);

        // Heapify reduces heap again
        maxHeapify(a, i, 0);
    }
}

int main()
{
    int a[]{5, 4, 3, 1, 2};
    int size = sizeof(a) / sizeof(a[0]);
    heapsort(a, size);
    for (auto i : a)
        cout << i << " ";

    return 0;
}