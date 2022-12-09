// Elements occurance more than N/2
// Boyer Moore's Voting Algorithm applied
#include <iostream>
#include <vector>
using namespace std;
// practice --> https://leetcode.com/problems/majority-element/
int majorityElement(vector<int> &nums)
{
    // reference ----> https://www.youtube.com/watch?v=YXywKwT9EKA

    int count = 0;
    int ans = -1;
    int n = nums.size();

    for (int i = 0; i < n; i++)
    {
        if (nums[i] == ans)
            count++;
        else if (count == 0)
        {
            ans = nums[i];
            count = 1;
        }
        else
            count--;
    }

    return ans;
}

int main()
{
    vector<int> nums{2, 2, 1, 1, 1, 2, 2};
    cout << majorityElement(nums);

    return 0;
}