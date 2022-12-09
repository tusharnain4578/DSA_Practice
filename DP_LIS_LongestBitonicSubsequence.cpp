#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// practice --> https://practice.geeksforgeeks.org/problems/longest-bitonic-subsequence0824/1/

//
//
// Approaches ->

// Tabulation ------------------------------------------

int LongestBitonicSequence(vector<int> nums)
{
    int n = nums.size();

    vector<int> lis(n); // longest inccreasing subsequence
    lis[0] = 1;

    for (int index = 1; index < n; index++)
    {
        int ans = 1;
        for (int i = 0; i < index; i++)
            if (nums[i] < nums[index])
                ans = max(ans, lis[i] + 1);

        lis[index] = ans;
    }

    vector<int> lds(n); // longest decreasing subsequence
    lds[n - 1] = 1;

    // lds calculation can only be done from back

    for (int index = n - 2; index >= 0; index--)
    {
        int ans = 1;
        for (int i = n - 1; i > index; i--)
            if (nums[i] < nums[index])
                ans = max(ans, lds[i] + 1);

        lds[index] = ans;
    }

    int lbs_size = 0; // longest bitonic subsequence size

    for (int i = 0; i < n; i++)
        lbs_size = max(lbs_size, lis[i] + lds[i] - 1);

    return lbs_size;
}