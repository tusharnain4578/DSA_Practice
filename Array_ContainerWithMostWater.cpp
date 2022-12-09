#include <iostream>
#include <vector>
using namespace std;
// practice --> https://leetcode.com/problems/container-with-most-water/
int maxArea(vector<int> &height)
{
    // reference ---> https://www.youtube.com/watch?v=ZHQg07n_tbg
    int l = 0;
    int r = height.size() - 1;
    int max_area = 0;
    while (l < r)
    {
        int this_area = (r - l) * min(height[l], height[r]);

        max_area = max(this_area, max_area);

        if (height[l] < height[r])
            l++;
        else
            r--;
    }
    return max_area;
}

int main()
{
    vector<int> heights{1, 8, 6, 2, 5, 4, 8, 3, 7};

    cout << maxArea(heights);

    return 0;
}