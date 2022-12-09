#include <iostream>
#include <vector>
using namespace std;
//  more optimised than the one with heaps(priority queue) - don't have code

// practice --> https://leetcode.com/problems/find-k-closest-elements/
vector<int> findClosestElements(vector<int> &arr, int k, int x)
{
    // reference ---> https://www.youtube.com/watch?v=IRtv7pdp8hQ
    vector<int> ans;

    int low = 0;
    int high = arr.size() - k;

    while (low < high) // when low and high are on the same element, that's our answer
    {
        int mid = (low + high) / 2;

        if (abs(x - arr[mid]) > abs(x - arr[mid + k]))
            low = mid + 1;
        else
            high = mid;
    }

    for (int i = low; i < low + k; i++)
        ans.push_back(arr[i]);

    return ans;
}