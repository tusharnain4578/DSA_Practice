#include <iostream>
#include <vector>
using namespace std;

// This is the O(N*log(N)) approach, in which we are using the lower_bound function which is taking O(log(N)) in the sorted array temp.
// Note that the vector temp, in which we are collecting the lis, is not actually the lis, it's just storing the elements, temp's size will be the lis size
// This approach will only work to get the size of lis

// practice ---> https://practice.geeksforgeeks.org/problems/longest-increasing-subsequence/0

// reference to this approach --> https://www.youtube.com/watch?v=MYHajVcnXSA

int longestSubsequence(int n, int a[])
{
    vector<int> temp;

    temp.push_back(a[0]);

    for (int i = 1; i < n; i++)
    {
        if (a[i] > temp.back())
        {
            temp.push_back(a[i]);
        }
        else
        {
            int index = lower_bound(temp.begin(), temp.end(), a[i]) - temp.begin();
            temp[index] = a[i];
        }
    }

    return temp.size();
}