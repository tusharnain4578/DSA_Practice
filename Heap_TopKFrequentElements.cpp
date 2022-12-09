#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>
using namespace std;

// practice --> https://leetcode.com/problems/top-k-frequent-elements/
vector<int> topKFrequent(vector<int> &nums, int k)
{
    // reference ---> https://www.youtube.com/watch?v=3YFFqwzxosU
    unordered_map<int, int> m;
    vector<int> ans;

    for (int i = 0; i < nums.size(); i++)
        m[nums[i]]++;

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    for (auto i : m)
    {
        pq.push(make_pair(i.second, i.first));

        if (pq.size() > k)
            pq.pop();
    }

    while (!pq.empty())
    {
        ans.push_back(pq.top().second);
        pq.pop();
    }
    return ans;
}