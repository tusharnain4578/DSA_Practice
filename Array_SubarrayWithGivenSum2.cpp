#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;
// practice --> https://practice.geeksforgeeks.org/problems/subarray-range-with-given-sum2804/1/

// handles negative numbers
// currently every online platform is only doing this for subarray count
int subArraySum(int arr[], int n, int sum)
{
    int count = 0;
    unordered_map<int, int> prefix_sum;
    int curr_sum = 0;

    for (int i = 0; i < n; i++)
    {
        curr_sum += arr[i];

        if (curr_sum == sum)
            count++;

        // keep both if seperated, not like if-else
        if (prefix_sum.find(curr_sum - sum) != prefix_sum.end())
            count += prefix_sum[curr_sum - sum];

        // accumulate prefix sum always, not in some else condition
        prefix_sum[curr_sum]++;
    }

    return count;
}

int main()
{
    int arr[]{10, 2, -2, -20, 10};
    int n = sizeof(arr) / sizeof(arr[0]);

    int ans = subArraySum(arr, n, -10);

    cout << ans << endl;

    return 0;
}