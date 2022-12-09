#include <iostream>
#include <vector>
using namespace std;
// practice --> https://leetcode.com/problems/combination-sum/
void func(vector<int> &v, int index, int targetSum, vector<vector<int>> &ans, vector<int> &ds)
{
    // reference --> https://www.youtube.com/watch?v=cn9Fi3u692g
    if (index == v.size())
    {
        if (targetSum == 0)
        {
            ans.push_back(ds);
        }
        return;
    }
    if (targetSum < 0)
        return;
    // not picking
    func(v, index + 1, targetSum, ans, ds);

    ds.push_back(v[index]);

    func(v, index, targetSum - v[index], ans, ds);
    ds.pop_back();
}

vector<vector<int>> combinationSum(vector<int> &candidates, int target)
{
    vector<vector<int>> ans;
    vector<int> ds;
    func(candidates, 0, target, ans, ds);
    return ans;
}

int main()
{
    vector<int> v{2, 3, 6, 7};
    int target = 7;
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