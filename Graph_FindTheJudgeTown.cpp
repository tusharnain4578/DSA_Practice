#include <iostream>
#include <vector>
using namespace std;
// practice --> https://leetcode.com/problems/find-the-town-judge/

int findJudge(int n, vector<vector<int>> &trust)
{
    // reference ---> https://www.youtube.com/watch?v=V_MPL5O-hDw

    vector<int> data(n + 1, 0);

    for (auto &x : trust)
    {
        data[x[0]]--;
        data[x[1]]++;
    }

    for (int i = 1; i < data.size(); i++)
        if (data[i] == n - 1)
            return i;

    return -1;
}