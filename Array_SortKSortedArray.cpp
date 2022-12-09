#include <iostream>
#include <vector>
#include <queue>
using namespace std;
// practice ---> https://practice.geeksforgeeks.org/problems/nearly-sorted-1587115620/1

vector<int> nearlySorted(int arr[], int n, int K)
{
    priority_queue<int, vector<int>, greater<int>> pq;

    // Here we stored the sorted array in the vector, but you can also do it in-place using an variable index
    //-------> in place approach mentioned below
    vector<int> ans;

    for (int i = 0; i < n; i++)
    {
        pq.push(arr[i]);

        if (pq.size() > K)
        {
            ans.push_back(pq.top());
            pq.pop();
        }
    }

    while (!pq.empty())
    {
        ans.push_back(pq.top());
        pq.pop();
    }

    return ans;
}

//
//
//
//
//
// IN PLACE APPROACH
//
void _nearlySorted(int arr[], int n, int K)
{
    priority_queue<int, vector<int>, greater<int>> pq;

    // Here we stored the sorted array in the vector, but you can also do it in-place using an variable index

    int index = 0;

    for (int i = 0; i < n; i++)
    {
        pq.push(arr[i]);

        if (pq.size() > K)
        {
            arr[index++] = pq.top();
            pq.pop();
        }
    }

    while (!pq.empty())
    {
        arr[index++] = pq.top();
        pq.pop();
    }
}

int main()
{
    int n = 7, K = 3, arr[]{6, 5, 3, 2, 8, 10, 9};

    _nearlySorted(arr, n, K);

    for (auto i : arr)
        cout << i << " ";

    return 0;
}