#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// practice --> https://practice.geeksforgeeks.org/problems/merge-k-sorted-arrays
class node
{
public:
    int val, val_pos, arr_pos;
    node(int val, int val_pos, int arr_pos) : val(val), val_pos(val_pos), arr_pos(arr_pos) {}
};

class comp
{
public:
    bool operator()(node &a, node &b)
    {
        return a.val > b.val;
    }
};

// Function to merge k sorted arrays.
vector<int> mergeKArrays(vector<vector<int>> arr, int K)
{
    // reference ---> https://www.youtube.com/watch?v=l8CuET0jlDU
    vector<int> ans;

    priority_queue<node, vector<node>, comp> pq;

    for (int i = 0; i < arr.size(); i++)
    {
        node temp(arr[i][0], 0, i);
        pq.push(temp);
    }

    while (!pq.empty())
    {
        node curr = pq.top();
        pq.pop();
        ans.push_back(curr.val);

        if (curr.val_pos + 1 < arr[curr.arr_pos].size())
        {
            node temp(arr[curr.arr_pos][curr.val_pos + 1], curr.val_pos + 1, curr.arr_pos);
            pq.push(temp);
        }
    }

    return ans;
}