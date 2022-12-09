#include <iostream>
#include <queue>
using namespace std;

// practice --> https://practice.geeksforgeeks.org/problems/minimum-cost-of-ropes-1587115620/1#
long long minCost(long long arr[], long long n)
{
    // reference --> https://www.youtube.com/watch?v=mRtq1ucnjJg
    long long ans = 0;

    priority_queue<long long, vector<long long>, greater<long long>> pq;

    for (int i = 0; i < n; i++)
        pq.push(arr[i]);

    while (pq.size() > 1)
    {
        long long a = pq.top();
        pq.pop();
        long long b = pq.top();
        pq.pop();
        ans += a + b;
        pq.push(a + b);
    }

    return ans;
}