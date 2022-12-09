#include <iostream>
using namespace std;
// practice --> https://practice.geeksforgeeks.org/problems/maximum-difference-of-zeros-and-ones-in-binary-string4111/1

// Kadane

// reference ---> https://www.youtube.com/watch?v=_V6VKhBSg2c

int maxSubstring(string S)
{
    int currSum = 0;
    int maxSum = INT_MIN;

    for (const auto &ch : S)
    {
        int x = ch == '0' ? 1 : -1;

        currSum += x;

        if (currSum > maxSum)
            maxSum = currSum;

        if (currSum < 0)
            currSum = 0;
    }

    return maxSum;
}