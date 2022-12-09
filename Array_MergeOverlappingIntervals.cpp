#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// practice --> https://leetcode.com/problems/merge-intervals/
vector<vector<int>> merge(vector<vector<int>> &intervals)
{
    // reference ---> https://www.youtube.com/watch?v=EnCh0tLzfGQ

    vector<vector<int>> res;
    if (intervals.empty())
        return res;

    sort(intervals.begin(), intervals.end());

    vector<int> curr = intervals[0];

    for (int i = 1; i < intervals.size(); i++)
    {
        if (curr[1] >= intervals[i][0])
            curr[1] = max(curr[1], intervals[i][1]);
        else
        {
            res.push_back(curr);
            curr = intervals[i];
        }
    }
    res.push_back(curr); // One interval will be left, you can dry run
    return res;
}

int main()
{
    vector<vector<int>> intervals{{1, 3}, {2, 6}, {8, 10}, {15, 18}};

    vector<vector<int>> ans = merge(intervals);

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