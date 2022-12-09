#include <iostream>
#include <vector>
using namespace std;
// practice --> https://leetcode.com/problems/max-consecutive-ones/
int findMaxConsecutiveOnes(vector<int> &nums)
{
    int count = 0;
    int ans = 0;

    for (int const &i : nums)
    {
        if (i == 1)
            count++;
        else
            count = 0;

        ans = max(count, ans);
    }
    return ans;
}

int main()
{
    vector<int> nums{1, 1, 0, 1, 1, 1};
    cout << findMaxConsecutiveOnes(nums);
    return 0;
}