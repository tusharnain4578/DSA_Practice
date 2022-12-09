#include <iostream>
#include <vector>
#include <queue>
using namespace std;
// practice --> https://leetcode.com/problems/kth-largest-element-in-an-array/
int findKthLargest(vector<int> &nums, int k)
{
    // reference ---> https://www.youtube.com/watch?v=g5mmW0GOTx8
    priority_queue<int, vector<int>, greater<int>> pq;

    for (int &i : nums)
    {
        pq.push(i);

        if (pq.size() > k)
            pq.pop();
    }

    return pq.top();
}