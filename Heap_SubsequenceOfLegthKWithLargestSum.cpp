#include <iostream>
#include <vector>
#include <queue>
#include <unordered_set>
using namespace std;
// practice ---> https://leetcode.com/problems/find-subsequence-of-length-k-with-the-largest-sum/

//  reference ---> https://www.youtube.com/watch?v=MVfLl6oo7OU
vector<int> maxSubsequence(vector<int> &nums, int k)
{

    int n = nums.size();

    vector<int> ans;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    for (int i = 0; i < n; i++)
    {
        pq.push(make_pair(nums[i], i));

        if (pq.size() > k)
            pq.pop();
    }

    unordered_set<int> s;

    while (!pq.empty())
        s.insert(pq.top().second), pq.pop();

    for (int i = 0; i < n; i++)
        if (s.find(i) != s.end())
            ans.push_back(nums[i]);

    return ans;
}

int main()
{
    vector<int> v{2, 1, 3, 3};
    int k = 2;

    vector<int> ans = maxSubsequence(v, k);

    for (int &i : ans)
        cout << i << " ";

    return 0;
}