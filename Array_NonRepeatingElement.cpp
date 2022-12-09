#include <iostream>
#include <unordered_map>
using namespace std;

// practice --> https://practice.geeksforgeeks.org/problems/non-repeating-element3958/1/
int firstNonRepeating(int arr[], int n)
{
    // Complete the function
    unordered_map<int, int> m;

    for (int i = 0; i < n; i++)
        m[arr[i]]++;

    for (int i = 0; i < n; i++)
        if (m[arr[i]] == 1)
            return arr[i];

    return -1;
}

int main()
{
    // int arr[]{-1, 2, -1, 3, 2};
    int arr[]{-1, 2, -1, 3, 2};
    int size = sizeof(arr) / sizeof(arr[0]);
    cout << firstNonRepeating(arr, size);

    return 0;
}