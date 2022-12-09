#include <iostream>
#include <vector>
using namespace std;

void solve(const vector<int> &v, int index, int target, vector<int> &ds, vector<vector<int>> &ans)
{
    // reference ---> https://www.youtube.com/watch?v=cn9Fi3u692g
    if (index == v.size())
    {
        if (target == 0)
            ans.push_back(ds);

        return;
    }
    if (target < 0)
        return;

    // not picking
    solve(v, index + 1, target, ds, ans);

    // picking
    ds.push_back(v[index]);
    solve(v, index, target - v[index], ds, ans);
    ds.pop_back();
}

vector<vector<int>> combinationSum(vector<int> &candidates, int target)
{
    vector<int> ds;
    vector<vector<int>> ans;
    solve(candidates, 0, target, ds, ans);
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