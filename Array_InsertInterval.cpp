#include <iostream>
#include <vector>
using namespace std;
// practice --> https://leetcode.com/problems/insert-interval/

vector<vector<int>> insert(vector<vector<int>> &intervals, vector<int> &newInterval)
{
    int i = 0, n = intervals.size();
    vector<vector<int>> ans;

    while (i < n and intervals[i][1] < newInterval[0])
        ans.push_back(intervals[i++]);

    while (i < n and intervals[i][0] <= newInterval[1])
    {
        newInterval[0] = min(newInterval[0], intervals[i][0]);
        newInterval[1] = max(newInterval[1], intervals[i][1]);
        i++;
    }
    ans.push_back(newInterval);

    while (i < n)
        ans.push_back(intervals[i++]);

    return ans;
}

// Below approach will also work, its al little tiny different

// vector<vector<int>> insert(vector<vector<int>> &intervals, vector<int> &newInterval)
// {
//     vector<vector<int>> ans;

//     int i = 0, n = intervals.size();

//     while (i < n and newInterval[0] > intervals[i][1])
//         ans.push_back(intervals[i++]);

//     if (i < n)
//         newInterval[0] = min(newInterval[0], intervals[i][0]);

//     while (i < n and newInterval[1] >= intervals[i][0])
//     {
//         newInterval[1] = max(newInterval[1], intervals[i][1]);
//         i++;
//     }

//     ans.push_back(newInterval);

//     while (i < n)
//         ans.push_back(intervals[i++]);

//     return ans;
// }