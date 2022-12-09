#include <iostream>
#include <vector>
#include <stack>
using namespace std;

// practice --> https://practice.geeksforgeeks.org/problems/the-celebrity-problem/1#
int celebrity(vector<vector<int>> &M, int n)
{
    // reference ---> https://www.youtube.com/watch?v=9u2BJfmWNEg

    stack<int> s;

    for (int i = 0; i < n; i++)
        s.push(i);

    while (s.size() > 1) // This condition is because the last element left in the stack can be the celeb or no one else is
    {
        int a = s.top();
        s.pop();

        int b = s.top();
        s.pop();

        if (M[a][b] == 1) // If a knows b, unconsider a
            s.push(b);
        else // b knows a, unconsider b
            s.push(a);
    }

    int ans = s.top();

    // Now, we just have to confirm if this element is the celeb, if this is not celeb, then no one is, and we'll have to return -1

    for (int i = 0; i < n; i++) // row check
        if (M[ans][i] != 0)
            return -1;

    int ct = 0;
    for (int i = 0; i < n; i++) // column check
        if (M[i][ans] == 1)
            ct++;

    if (ct != n - 1)
        return -1;

    return ans;
}

int main()
{
    vector<vector<int>> M{{0, 1, 0},
                          {0, 0, 0},
                          {0, 1, 0}};

    cout << celebrity(M, M.size());

    return 0;
}