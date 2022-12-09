#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;
// practice --> https://practice.geeksforgeeks.org/problems/largest-subarray-with-0-sum/1/
int maxLen(vector<int> &A, int n)
{
    // reference ---> https://www.youtube.com/watch?v=xmguZ6GbatA
    unordered_map<int, int> mp;
    int ans = 0;
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += A[i];

        if (sum == 0)
            ans = i + 1;
        else if (mp.find(sum) != mp.end()) // it means that the we got this sum before, which clearly means that somewhere in between - and +, makes 0, like -2+2=0
            ans = max(ans, i - mp[sum]);
        else // notice -> only store in map, in this else block
            mp[sum] = i;
    }
    return ans;
}

// int main()
// {
//     vector<int> v{15, -2, 2, -8, 1, 7, 10, 23};
//     cout << maxLen(v, v.size());
//     return 0;
// }

//
//
//
// following is the version to get indeces of largest subarray with 0 sum
pair<int, int> largestSubarrayWith0Sum(vector<int> const &arr)
{
    int n = arr.size();

    pair<int, int> indeces;
    int maxLen = 0;

    unordered_map<int, int> mp;

    int sum = 0;

    for (int i = 0; i < n; i++)
    {
        sum += arr[i];

        if (sum == 0)
        {
            if (i - 0 + 1 > maxLen)
            {
                indeces = {0, i};
                maxLen = i - 0 + 1;
            }
        }
        else if (mp.count(sum))
        {
            if (i - mp[sum] + 1 > maxLen)
            {
                indeces = {mp[sum] + 1, i};
                maxLen = i - mp[sum];
            }
        }
        else
        {
            mp[sum] = i;
        }
    }
    cout << maxLen << endl;
    return indeces;
}

int main()
{
    vector<int> v{0, -13, -10};
    pair<int, int> p = largestSubarrayWith0Sum(v);

    cout << p.first << " " << p.second;
    return 0;
}