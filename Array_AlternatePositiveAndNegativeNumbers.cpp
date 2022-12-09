#include <iostream>
#include <vector>
using namespace std;

// practice --> https://practice.geeksforgeeks.org/problems/array-of-alternate-ve-and-ve-nos1401/1

// Read Carefully ->

// Hello there! Future me. Wassup!

// There can be 2 demands in this poblem ->

// 1. Alternate positive and negative numbers while maintaining order. This can only be done in O(N) time with O(N) space.

// 2. Do the same task without maintaining order. We can do this with O(N) time and O(1) space.

// Both solutions are given below

// NOTE - We can't do this task with maintained order in O(1) space. Basically, once a wise man said- to gain something, we gotta lose someting. LOL! I'm weird.

// Method No. 1 (Order maintained, with O(N) space)
void rearrange1(int arr[], int n)
{
    // reference --> https://www.youtube.com/watch?v=a0XKJhM4KcA
    vector<int> pos, neg;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] < 0)
            neg.push_back(arr[i]);
        else
            pos.push_back(arr[i]);
    }

    int i = 0; // pointer for positive array
    int j = 0; // pointer for negative array
    int k = 0; // pointer for main array

    // while loop until one of both(pos or neg) are not traversed
    while (i < pos.size() && j < neg.size())
    {
        if (k % 2 == 0)
            arr[k] = pos[i++];
        else
            arr[k] = neg[j++];

        k++;
    }
    while (i < pos.size())
        arr[k++] = pos[i++];

    while (j < neg.size())
        arr[k++] = neg[j++];
}

// Method No. 2 (Order not maintained, with O(1) space)
void rearrange2(int arr[], int n)
{
    // reference ---> https://www.youtube.com/watch?v=zUPMACE0uBs

    // placing all positive elements to left side and all negative elements to right side of the array

    int i = 0, j = n - 1;

    while (i < j)
    {
        while (i < j && arr[i] >= 0)
            i++;

        while (i < j && arr[j] < 0)
            j--;

        if (i < j)
            swap(arr[i], arr[j]);
    }
    // after above while loop, the i will point to the first negative element in the array
    // i will traverse negative, so we will make j to traverse positive now

    j = 0;
    while (i < n && j < n)
    {
        swap(arr[j], arr[i]);
        j += 2;
        i++;
    }
}

int main()
{
    int arr[]{9, 4, -2, -1, 5, 0, -5, -3, 2};
    int size = sizeof(arr) / sizeof(arr[0]);

    rearrange2(arr, size);

    for (auto &&i : arr)
    {
        cout << i << " ";
    }

    return 0;
}