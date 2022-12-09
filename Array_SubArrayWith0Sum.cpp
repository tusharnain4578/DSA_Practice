#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

// practice --> https://practice.geeksforgeeks.org/problems/subarray-with-0-sum-1587115621/1/
bool subArrayExists(int arr[], int n)
{
    // reference ---> https://www.youtube.com/watch?v=QtbFXZrEZYc

    // Here we were asked to tell if there exist a subarray with 0 sum, i.e, true or false, so we can just use unordered_set
    // If we were asked to tell the indexes for the subarry, we could have used unordered_map
    // refer to this file in this folder, Array_LongestSubarrayWith0Sum.cpp

    int sum = 0;
    unordered_set<int> s;
    for (int i = 0; i < n; i++)
    {
        sum += arr[i];

        if (sum == 0 || s.find(sum) != s.end())
            return true;
        else
            s.insert(sum);
    }
    return false;
}

int main()
{
    int arr[]{4, 2, -3, 1, 6};
    // int arr[]{4, 2, 0, 1, 6};
    int size = sizeof(arr) / sizeof(arr[0]);

    cout << subArrayExists(arr, size);

    return 0;
}