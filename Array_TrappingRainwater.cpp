#include <iostream>
#include <vector>
using namespace std;
// practice --> https://leetcode.com/problems/trapping-rain-water/

// Note>>> There are two approaches, first is of O(N) time and O(N) space, this approach is pretty easy, where we just create 2 arrays for left max and right max, and can simply count all the trapped watter

// Second approach is on O(N) time and O(1) space which use 2 pointer approach, this approach is also present in this file

// O(N) space approach
int trap(vector<int> &height)
{
    // reference ---> https://www.youtube.com/watch?v=UZG3-vZlFM4
    int n = height.size();
    int ans = 0;

    vector<int> left(n), right(n);

    left[0] = height[0]; // array for max in left
    for (int i = 1; i < n; i++)
        left[i] = max(height[i], left[i - 1]);

    right[n - 1] = height[n - 1]; // array for max in right
    for (int i = n - 2; i >= 0; i--)
        right[i] = max(height[i], right[i + 1]);

    for (int i = 0; i < n; i++)
    {
        int curr = min(left[i], right[i]) - height[i];
        ans += curr;
    }

    return ans;
}

// O(1) space approach -> better approach
int _trap(vector<int> &height)
{
    // reference ---> https://www.youtube.com/watch?v=m18Hntz4go8

    int l = 0, r = height.size() - 1;

    int left_max = height[0];
    int right_max = height[height.size() - 1];
    int ans = 0;

    while (l <= r) // note-> * while(l<=r)
    {
        if (height[l] < height[r])
        {
            if (height[l] >= left_max)
                left_max = height[l];
            else
                ans += left_max - height[l];

            l++;
        }
        else
        {
            if (height[r] >= right_max)
                right_max = height[r];
            else
                ans += right_max - height[r];

            r--;
        }
    }
    return ans;
}

int main()
{
    vector<int> heights{4, 2, 0, 3, 2, 5};
    cout << trap(heights);

    return 0;
}