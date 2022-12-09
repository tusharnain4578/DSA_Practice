#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;
// practice --> https://leetcode.com/problems/first-missing-positive/

// TC-> O(N), SC-> O(N)  //uses unoredered set
int firstMissingPositive(vector<int> &nums)
{
    int n = nums.size();
    unordered_set<int> us;

    // insert all positive elements into unordered set
    for (int i : nums)
        if (i > 0)
            us.insert(i);

    // now, the smallest missing positive number will always range in 1 to n
    // if from(1 to n) every element is present, then the missing element is n+1

    for (int i = 1; i <= n; i++)
        if (us.find(i) == us.end()) // if not found
            return i;

    return n + 1;
}

// TC-> O(N), SC-> O(1)
// kinda' like mapping elements with the same array
int firstMissingPositive(vector<int> &nums)
{
    // reference ---> https://www.youtube.com/watch?v=-lfHWWMmXXM
    int n = nums.size();

    for (int i = 0; i < n; i++)
    {
        if (nums[i] < 0)
            continue;

        int correctPos = nums[i] - 1;

        while (nums[i] >= 1 and nums[i] <= n and nums[i] != nums[correctPos])
        {
            swap(nums[i], nums[correctPos]);
            correctPos = nums[i] - 1;
        }
    }

    for (int i = 0; i < n; i++)
        if (i + 1 != nums[i])
            return i + 1;

    return n + 1;
}