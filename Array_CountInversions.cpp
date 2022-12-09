#include <iostream>
using namespace std;
// practice --> https://practice.geeksforgeeks.org/problems/inversion-of-array-1587115620/1
long long int merge(long long arr[], int low, int high)
{
    // reference ---> https://www.youtube.com/watch?v=8ySvTntD2eY

    int mid = (low + high) / 2;
    long long int inversion_count = 0;
    int a1_size = mid - low + 1;
    int a2_size = high - mid;

    long long a1[a1_size], a2[a2_size];

    for (int i = 0; i < a1_size; i++)
        a1[i] = arr[low + i];

    for (int i = 0; i < a2_size; i++)
        a2[i] = arr[mid + 1 + i];

    int i = 0, j = 0;
    int k = low;

    while (i < a1_size && j < a2_size)
    {
        if (a1[i] <= a2[j]) // make sure to <= in a1[i] <= a2[j], because if elements are equal they are sorted
        {
            arr[k++] = a1[i++];
        }
        else
        {
            arr[k++] = a2[j++];
            inversion_count += a1_size - i; // stress stress stress here, do a hard dry run
        }
    }
    while (i < a1_size)
        arr[k++] = a1[i++];

    while (j < a2_size)
        arr[k++] = a2[j++];

    return inversion_count;
}

long long int mergesort(long long arr[], int low, int high)
{
    long long int inversion_count = 0;
    if (low < high)
    {
        int mid = (low + high) / 2;
        inversion_count += mergesort(arr, low, mid);
        inversion_count += mergesort(arr, mid + 1, high);
        inversion_count += merge(arr, low, high);
    }
    return inversion_count;
}

long long int inversionCount(long long arr[], long long N)
{
    // Your Code Here
    return mergesort(arr, 0, N - 1);
}

int main()
{
    long long arr[] = {468, 335, 1, 170, 225, 479, 359, 463, 465, 206, 146, 282, 328, 462, 492, 496, 443, 328, 437, 392, 105, 403, 154, 293, 383, 422, 217, 219, 396, 448, 227, 272, 39, 370, 413, 168, 300, 36, 395, 204, 312, 323};
    // long long arr[] = {5, 4, 3, 2, 1};
    int n = sizeof(arr) / sizeof(arr[0]);
    long long int ans = inversionCount(arr, n);
    cout << "The total inversions are " << ans << endl;

    return 0;
}