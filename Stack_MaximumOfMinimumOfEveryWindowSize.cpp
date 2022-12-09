#include <iostream>
#include <vector>
#include <stack>
using namespace std;

// This function is taking the vector by reference and doing operations on it on place
vector<int> nextSmallerIndex(int *arr, int n)
{
    stack<int> s;
    vector<int> ans(n);
    for (int i = n - 1; i >= 0; i--)
    {
        while (!s.empty() && arr[s.top()] >= arr[i])
            s.pop();

        if (s.empty())
            ans[i] = n;
        else
            ans[i] = s.top();

        s.push(i);
    }
    return ans; // this contains only indeces
}

vector<int> prevSmallerIndex(int *arr, int n)
{
    stack<int> s;
    vector<int> ans;
    for (int i = 0; i < n; i++)
    {
        while (!s.empty() && arr[s.top()] >= arr[i])
            s.pop();

        if (s.empty())
            ans.push_back(-1);
        else
            ans.push_back(s.top());

        s.push(i);
    }

    return ans; // this contains only indeces
}

vector<int> maxOfMin(int arr[], int n)
{
    // reference ---> https://www.youtube.com/watch?v=CK8PIAF-m2E

    vector<int> ans(n, -1);

    vector<int> prev = prevSmallerIndex(arr, n);
    vector<int> next = nextSmallerIndex(arr, n);

    for (int i = 0; i < n; i++)
    {
        int window_size = next[i] - prev[i] - 2; //-2 for just synching it with the array indeces 0, and all

        ans[window_size] = max(ans[window_size], arr[i]);
    }

    // After iteration, there will be some index left out

    for (int i = n - 2; i >= 0; i--)
        ans[i] = max(ans[i], ans[i + 1]);

    return ans;
}

int main()
{
    int arr[]{10, 20, 30, 50, 10, 70, 30};
    int N = sizeof(arr) / sizeof(arr[0]);

    vector<int> ans = maxOfMin(arr, N);

    for (int &i : ans)
        cout << i << " ";
    return 0;
}