#include <bits/stdc++.h>
using namespace std;

pair<int, int> largestSubarrayWith0Sum(vector<int> const &arr)
{
    int n = arr.size();

    pair<int, int> indeces{-1, -1};
    int maxLen = 0;

    unordered_map<int, int> mp;

    int sum = 0;

    for (int i = 0; i < n; i++)
    {
        sum += arr[i];

        if (sum == 0)
        {
            if (i - 0 > maxLen)
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
    return indeces;
}

int main()
{
    vector<int> arr{0, -13, -10};
    pair<int, int> p = largestSubarrayWith0Sum(arr);

    cout << p.first << " " << p.second << endl;

    return 0;
}