#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int largestRectangleArea(const vector<int> &arr)
{
    int n = arr.size();
    int max_area = INT_MIN;
    stack<int> s;

    int i = 0;

    for (int i = 0; i <= n; i++) // make sure to runn the loop till i==n, so that we empty the stack
    {
        while (!s.empty() && (i == n || arr[s.top()] > arr[i]))
        {
            int length = arr[s.top()];
            s.pop();
            int width = s.empty() ? i : i - s.top() - 1;
            int this_area = length * width;
            max_area = max(max_area, this_area);
        }
        s.push(i);
    }

    return max_area;
}

int maxArea(vector<vector<int>> &arr)
{
    // reference ---> https://www.youtube.com/watch?v=9u2BJfmWNEg

    int m = arr.size();
    int n = arr[0].size();

    int max_area = largestRectangleArea(arr[0]);
    for (int i = 1; i < m; i++)
    {
        // cout << max_area << endl;
        for (int j = 0; j < n; j++)
        {
            if (arr[i][j] != 0)
                arr[i][j] += arr[i - 1][j];
            else
                arr[i][j] = 0;
        }

        max_area = max(max_area, largestRectangleArea(arr[i]));
    }
    return max_area;
}

int main()
{
    vector<vector<int>> arr{{0, 1, 1, 0},
                            {1, 1, 1, 1},
                            {1, 1, 1, 1},
                            {1, 1, 0, 0}};

    cout << maxArea(arr);
    return 0;
}