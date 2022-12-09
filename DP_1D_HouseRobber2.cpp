#include <iostream>
#include <vector>
using namespace std;
// practice --> https://www.codingninjas.com/codestudio/problems/house-robber_839733

// first do DP_MaximumSumOfNonAdjacentElements.cpp

long long int maximumNonAdjacentSum_SpaceOptimized(vector<int> &nums, int start, int end)
{
    long long int prev1 = nums[start];
    long long int prev2 = 0;
    long long int curr = 0;
    for (int index = start + 1; index <= end; index++)
    {
        long long int pick = nums[index];

        if (index > 1)
            pick += prev2;

        long long int non_pick = prev1;

        curr = max(pick, non_pick);

        prev2 = prev1;
        prev1 = curr;
    }
    return prev1;
}

long long int houseRobber(vector<int> &valueInHouse)
{
    int n = valueInHouse.size();

    if (n == 1)
        return valueInHouse[0];

    long long int a = maximumNonAdjacentSum_SpaceOptimized(valueInHouse, 0, n - 2);
    long long int b = maximumNonAdjacentSum_SpaceOptimized(valueInHouse, 1, n - 1);

    return max(a, b);
}