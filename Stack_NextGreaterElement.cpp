#include <iostream>
#include <vector>
#include <stack>
using namespace std;

vector<int> nextGreaterElement(const vector<int> &v)
{
    int n = v.size();
    vector<int> ans(n, -1);
    stack<int> st;

    for (int i = 2 * n - 1; i >= 0; i--)
    {
        while (!st.empty() && st.top() <= v[i % n])
            st.pop();

        if (i < n && !st.empty())
            ans[i] = st.top();

        st.push(v[i % n]);
    }
    return ans;
}

int main()
{
    vector<int> v{3, 10, 4, 2, 1, 2, 6, 1, 7, 2, 9};
    vector<int> ans = nextGreaterElement(v);

    for (auto &i : ans)
        cout << i << " ";
    return 0;
}