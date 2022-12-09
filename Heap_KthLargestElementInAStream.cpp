#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// Leetcode
//  practice --> https://leetcode.com/problems/kth-largest-element-in-a-stream/
class KthLargest
{
    priority_queue<int, vector<int>, greater<int>> pq;
    int k;

public:
    KthLargest(int k, vector<int> &nums)
    {
        // reference ---> https://www.youtube.com/watch?v=8HR8Ak5zuus
        this->k = k;

        for (int &i : nums)
        {
            pq.push(i);

            if (pq.size() > k)
                pq.pop();
        }
    }

    int add(int val)
    {
        pq.push(val);

        if (pq.size() > k)
            pq.pop();

        return pq.top();
    }
};

// GFG
// practice --> https://practice.geeksforgeeks.org/problems/kth-largest-element-in-a-stream2220
vector<int> kthLargest(int k, int arr[], int n)
{
    vector<int> ans;

    priority_queue<int, vector<int>, greater<int>> pq;

    for (int i = 0; i < n; i++)
    {
        pq.push(arr[i]);

        if (pq.size() < k)
        {
            ans.push_back(-1);
        }
        else
        {
            if (pq.size() > k)
                pq.pop();

            ans.push_back(pq.top());
        }
    }
    return ans;
}