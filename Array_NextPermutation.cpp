#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// practice --> https://leetcode.com/problems/next-permutation/
void nextPermutation(vector<int> &nums)
{
    // reference ---> https://www.youtube.com/watch?v=umhrBhdLkaY

    int index_1 = -1, index_2;
    int n = nums.size();
    for (int i = n - 1; i > 0; i--)
    {
        if (nums[i - 1] < nums[i])
        {
            index_1 = i - 1;
            break;
        }
    }

    if (index_1 == -1)
    {
        // sort(nums.begin(), nums.end());
        reverse(nums.begin(), nums.end());
        return;
    }

    for (int i = n - 1; i > index_1; i--)
    {
        if (nums[i] > nums[index_1])
        {
            index_2 = i;
            break;
        }
    }

    swap(nums[index_1], nums[index_2]);

    sort(nums.begin() + index_1 + 1, nums.end());
}

int main()
{
    vector<int> nums{3, 2, 1};
    nextPermutation(nums);

    for (auto &&i : nums)
    {
        cout << i << " ";
    }

    return 0;
}