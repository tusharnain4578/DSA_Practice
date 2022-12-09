#include <iostream>
#include <climits>
using namespace std;
// practice --> https://practice.geeksforgeeks.org/problems/kadanes-algorithm-1587115620/1/
//  Maximum sum contigous subarray // VVVVVV Imp
int maxSumSubArray(int a[], int n)
{
    int currSum = 0;
    int maxSum = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        currSum += a[i];
        if (currSum > maxSum)
            maxSum = currSum;

        if (currSum < 0)
            currSum = 0;
    }
    return maxSum;
}

int main()
{
    int a[]{5, 2, -4, -2, 6, -1};
    int size = sizeof(a) / sizeof(a[0]);
    cout << maxSumSubArray(a, size);

    return 0;
}