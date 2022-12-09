#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
// practice ---> https://leetcode.com/problems/earliest-possible-day-of-full-bloom/

// reference --> https://www.youtube.com/watch?v=vMz0wIN5yRY

// LC Hard

bool comp(const pair<int, int> p1, const pair<int, int> p2)
{
    return p2.second < p1.second;
}

int earliestFullBloom(vector<int> &plantTime, vector<int> &growTime)
{
    vector<pair<int, int>> arr;

    int n = plantTime.size();

    for (int i = 0; i < n; i++)
        arr.push_back(make_pair(plantTime[i], growTime[i]));

    sort(arr.begin(), arr.end(), comp);

    int ans = 0, start = 0;

    for (int i = 0; i < n; i++)
    {
        start += arr[i].first;
        ans = max(ans, start + arr[i].second);
    }

    return ans;
}
