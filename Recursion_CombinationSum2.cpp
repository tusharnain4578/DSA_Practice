#include <iostream>
#include <vector>
using namespace std;

void solve(const vector<int> &v, int index, int target, vector<int> &ds, vector<vector<int>> &ans, bool pre)
{

    if (index == v.size())
    {
        if (target == 0)
            ans.push_back(ds);

        return;
    }
    if (target < 0)
        return;

    // not picking
    solve(v, index + 1, target, ds, ans, false);

    if (index > 0 && v[index] == v[index - 1] && pre == false)
        return;

    // picking
    ds.push_back(v[index]);
    solve(v, index + 1, target - v[index], ds, ans, true);
    ds.pop_back();
}

vector<vector<int>> combinationSum(vector<int> &candidates, int target)
{

    vector<int> ds;
    vector<vector<int>> ans;
    solve(candidates, 0, target, ds, ans, false);
    return ans;
}

int main()
{
    int n, target;
    cin >> n >> target;
    vector<int> v;
    int x;
    for (int i = 0; i < n; i++)
    {
        cin >> x;
        v.push_back(x);
    }

    vector<vector<int>> ans = combinationSum(v, target);

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