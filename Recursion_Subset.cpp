#include <iostream>
#include <vector>
using namespace std;
// practice --> https://leetcode.com/problems/subsets/
// This should be also exist in backtracking section, but... ehh

void solve(const vector<int> &v, int index, vector<int> &output, vector<vector<int>> &ans)
{
    if (index == v.size())
    {
        ans.push_back(output);
        return;
    }

    solve(v, index + 1, output, ans);
    output.push_back(v[index]);
    solve(v, index + 1, output, ans);
    output.pop_back();
}

vector<vector<int>> subsets(vector<int> &nums)
{
    vector<int> output;
    vector<vector<int>> ans;
    solve(nums, 0, output, ans);
    return ans;
}

int main()
{
    int n;
    cin >> n;
    vector<int> v;
    int x;
    for (int i = 0; i < n; i++)
    {
        cin >> x;
        v.push_back(x);
    }

    vector<vector<int>> ans = subsets(v);

    for (auto &&i : ans)
    {
        for (auto &&j : i)
        {
            cout << j << " ";
        }
        cout << endl;
    }

    return 0;
}