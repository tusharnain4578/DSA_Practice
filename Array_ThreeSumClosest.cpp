#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
// practice --> https://leetcode.com/problems/3sum-closest/

int threeSumClosest(vector<int> &nums, int target)
{
    // reference ---> https://www.youtube.com/watch?v=anuarmFjTGU
    int n = nums.size();
    sort(nums.begin(), nums.end());

    int diff = INT_MAX;
    int ans = 0;

    for (int i = 0; i < n - 2; i++)
    {
        int first = nums[i];

        int j = i + 1, k = n - 1;

        while (j < k)
        {
            if (first + nums[j] + nums[k] == target)
                return target;
            else if (abs(first + nums[j] + nums[k] - target) < diff)
            {
                diff = abs(first + nums[j] + nums[k] - target);
                ans = first + nums[j] + nums[k];
            }

            if (first + nums[j] + nums[k] < target)
                j++;
            else
                k--;
        }
    }
    return ans;
}