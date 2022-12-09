#include <iostream>
#include <vector>
using namespace std;
// practice ---> https://practice.geeksforgeeks.org/problems/maximum-sum-rectangle2948/1

// Using Kadane's algorithm to find maxim sun contiguous subarray

// reference--> https://www.youtube.com/watch?v=kKEX4P53MyY

// util function for kadane's
int maxSumSubarray(vector<int> &arr)
{
    int currSum = 0, maxSum = INT_MIN;
    for (int const &i : arr)
    {
        currSum += i;

        if (currSum > maxSum)
            maxSum = currSum;

        if (currSum < 0)
            currSum = 0;
    }

    return maxSum;
}

int maximumSumRectangle(int R, int C, vector<vector<int>> M)
{

    int maxRectangle = INT_MIN;

    for (int i = 0; i < R; i++)
    {
        vector<int> temp(C);

        for (int j = i; j < R; j++)
        {
            for (int k = 0; k < C; k++)
            {
                temp[k] += M[j][k];
            }

            maxRectangle = max(maxRectangle, maxSumSubarray(temp));
        }
    }

    return maxRectangle;
}