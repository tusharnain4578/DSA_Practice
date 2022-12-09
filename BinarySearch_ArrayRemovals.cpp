#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
// practice ---> https://practice.geeksforgeeks.org/problems/array-removals/1

// reference --> https://www.youtube.com/watch?v=kqdoUDVXFik

int removals(vector<int> &a, int k)
{
    int n = a.size();

    sort(a.begin(), a.end());

    int ans = n - 1; // worst case answer

    for (int i = 0; i < n; i++)
    {
        int searchKey = a[i] + k;

        int j = upper_bound(a.begin() + i, a.end(), searchKey) - a.begin() - 1;

        ans = min(ans, n - (j - i + 1));
    }

    return ans;
}