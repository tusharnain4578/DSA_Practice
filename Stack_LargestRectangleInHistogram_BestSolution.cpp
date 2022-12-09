#include <iostream>
#include <vector>
#include <stack>
using namespace std;
// practice --> https://leetcode.com/problems/largest-rectangle-in-histogram/

int largestRectangleArea(vector<int> &heights)
{
    // https://www.youtube.com/watch?v=lkVB_PgF8Q0&t=1099s
    int n = heights.size();
    stack<int> s;
    int max_area = INT_MIN;

    for (int i = 0; i <= n; i++) // make sure to runn the loop till i==n, so that we empty the stack
    {
        while (!s.empty() && (i == n || heights[s.top()] > heights[i]))
        {
            int length = heights[s.top()];
            s.pop();
            int width = s.empty() ? i : i - s.top() - 1;
            int this_area = length * width;
            max_area = max(max_area, this_area);
        }
        s.push(i);
    }

    return max_area;
}

int main()
{
    vector<int> heights{2, 1, 5, 6, 2, 3};
    cout << largestRectangleArea(heights);

    return 0;
}