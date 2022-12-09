#include <iostream>
using namespace std;

// practice GFG ---> https://practice.geeksforgeeks.org/problems/move-all-negative-elements-to-end1813/1

void segregateElements(int arr[], int n)
{
    int temp[n];
    int j = 0;
    for (int i = 0; i < n; i++)
        if (arr[i] >= 0)
            temp[j++] = arr[i];

    for (int i = 0; i < n; i++)
        if (arr[i] < 0)
            temp[j++] = arr[i];

    copy(temp, temp + n, arr);
}

// Use this one if order doesn't matter, it's space complexity is O(1)

// void segregateElements(int arr[], int n)
// {
//     // Your code goes here
//     int i = 0, j = n - 1;

//     // placing i to negative number from biggining

//     // placing j to positive number from end

//     while (i < j)
//     {

//         while (i < j && arr[i] >= 0)
//             i++;

//         while (i < j && arr[j] < 0)
//             j--;

//         swap(arr[i], arr[j]);
//         i++;
//         j--;
//     }
// }

int main()
{
    int arr[]{-1, -7, 2, 1, 3, 11, 6, -5};
    int n = sizeof(arr) / sizeof(arr[0]);

    segregateElements(arr, n);
    for (auto &&i : arr)
    {
        cout << i << " ";
    }

    return 0;
}