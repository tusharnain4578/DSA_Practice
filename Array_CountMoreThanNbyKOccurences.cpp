#include <iostream>
#include <unordered_map>
using namespace std;
// practice ---> https://practice.geeksforgeeks.org/problems/count-element-occurences/1

// Function to find all elements in array that appear more than n/k times.
int countOccurence(int arr[], int n, int k)
{
    unordered_map<int, int> mp;

    int x = n / k;
    int count = 0;

    for (int i = 0; i < n; i++)
    {
        mp[arr[i]]++;

        if (mp[arr[i]] > x)
        {
            count++;
            mp[arr[i]] = INT_MIN; // so that we won't count it again
        }
    }

    return count;
}