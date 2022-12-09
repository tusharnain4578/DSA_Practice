#include <iostream>
#include <vector>
#include <deque>
using namespace std;

// practice --> https://leetcode.com/problems/sliding-window-maximum/
vector<int> maxSlidingWindow(vector<int> &nums, int k)
{
    // reference ---> https://www.youtube.com/watch?v=4JstGzs6Q9I
    int n = nums.size();
    vector<int> ans;
    deque<int> dq; // We are only inserting indeces in the deque not actual values
    for (int i = 0; i < k; i++)
    {
        while (!dq.empty() and nums[dq.back()] < nums[i])
            dq.pop_back();

        dq.push_back(i);
    }
    // cout << nums[dq.front()] << endl;
    ans.push_back(nums[dq.front()]);

    for (int i = k; i < n; i++)
    {
        if (dq.front() == i - k)
            dq.pop_front();

        while (!dq.empty() and nums[dq.back()] < nums[i])
            dq.pop_back();

        dq.push_back(i);
        ans.push_back(nums[dq.front()]);
    }

    return ans;
}

int main()
{
    vector<int> nums{1, 3, -1, -3, 5, 3, 6, 7};
    vector<int> ans = maxSlidingWindow(nums, 3);

    for (auto i : ans)
        cout << i << " ";
    return 0;
}

// Brute force approach O(nk)
// vector<int> slidingWindowMaximum(int arr[],int n,int k){
//     vector<int> ans;
//     for(int i=0;i<n-k+1;i++){
//         int mx = arr[i];
//         for(int j = i;j<i+k;j++){
//             mx = max(arr[j],mx);
//         }
//         ans.push_back(mx);
//     }
//     return ans;
// }