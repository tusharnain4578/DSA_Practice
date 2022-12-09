#include <iostream>
#include <vector>
#include <stack>
using namespace std;

vector<int> nextSmallerElement(const vector<int> &arr)
{
    int n = arr.size();
    vector<int> ans(n, -1);
    stack<int> s;
    for (int i = n - 1; i >= 0; i--)
    {
        while (!s.empty() and arr[s.top()] >= arr[i])
            s.pop();

        if (!s.empty())
            ans[i] = s.top();

        s.push(i);
    }
    return ans;
}

vector<int> prevSmallerElement(const vector<int> &arr)
{
    int n = arr.size();
    vector<int> ans;
    stack<int> s;
    for (int i = 0; i < n; i++)
    {
        while (!s.empty() and arr[s.top()] >= arr[i])
            s.pop();

        if (!s.empty())
            ans.push_back(s.top());
        else
            ans.push_back(-1);

        s.push(i);
    }
    return ans;
}

int largestRectangleArea(vector<int> &heights)
{
    // reference ---> https://www.youtube.com/watch?v=lJLcqDsmYfg
    int n = heights.size();
    stack<int> s;
    int max_area = INT_MIN;
    vector<int> leftSmall = prevSmallerElement(heights);
    vector<int> rightSmall = nextSmallerElement(heights);

    for (int i = 0; i < n; i++)
    {
        int l = heights[i];

        if (rightSmall[i] == -1)
            rightSmall[i] = n;

        int b = rightSmall[i] - leftSmall[i] - 1;

        int this_area = l * b;

        max_area = max(max_area, this_area);
    }
    return max_area;
}

int main()
{
    vector<int> heights{2, 1, 5, 6, 2, 3};
    cout << largestRectangleArea(heights);

    return 0;
}

// Brute Force
// int largestRectangleArea(vector<int> &heights)
// {
//     int n = heights.size();
//     int ans = INT_MIN;
//     for (int i = 0; i < n; i++)
//     {
//         int mini = INT_MAX;
//         for (int j = i; j < n; j++)
//         {
//             for (int k = i; k <= j; k++)
//                 mini = min(mini, heights[k]);
//             ans = max(ans, mini * (j - i + 1));
//         }
//     }
//     return ans;
// }