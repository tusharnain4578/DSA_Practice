#include <iostream>
using namespace std;

int findMin(int arr[], int n)
{
    // reference ---> https://www.youtube.com/watch?v=Kcj2NGnuSNg
    // reference highly highly recommended, even if you know it.

    int low = 0, high = n - 1;
    int mid;

    if (arr[low] <= arr[high])
    {
        return arr[low]; // if array is not rotated, first element is the smallest element
    }
    while (low <= high)
    {

        mid = (low + high) / 2;
        if (arr[mid] > arr[mid + 1])
            return arr[mid + 1];
        else if (arr[mid] < arr[mid - 1])
            return arr[mid];
        else if (arr[low] <= arr[mid])
            low = mid + 1;
        else if (arr[mid + 1] <= arr[high])
            high = mid - 1;
    }
    return -1;
}

int main()
{
    int arr[]{4, 5, 1, 2, 3};
    int size = sizeof(arr) / sizeof(arr[0]);

    cout << findMin(arr, size);

    return 0;
}