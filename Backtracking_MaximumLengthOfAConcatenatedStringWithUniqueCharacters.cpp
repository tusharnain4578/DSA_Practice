#include <iostream>
#include <vector>
using namespace std;
// practice ---> https://leetcode.com/problems/maximum-length-of-a-concatenated-string-with-unique-characters/

// LC Medium

void _backtracking_function(vector<string> &arr, int index, vector<bool> vis, int currLen, int &maxLen)
{
    if (index < 0)
    {
        maxLen = max(maxLen, currLen);
        return;
    }

    const string &str = arr[index];

    vector<bool> temp_vis = vis;

    bool flag = false;
    for (const char &ch : str)
    {
        if (temp_vis[ch - 'a'])
        {
            flag = true;
            break;
        }

        temp_vis[ch - 'a'] = true;
    }

    if (flag == false)
        _backtracking_function(arr, index - 1, temp_vis, currLen + arr[index].size(), maxLen); // take

    _backtracking_function(arr, index - 1, vis, currLen, maxLen); // not take
}

int maxLength(vector<string> &arr)
{
    int n = arr.size();
    vector<bool> vis(26, false);
    int ans = 0;

    _backtracking_function(arr, n - 1, vis, 0, ans);

    return ans;
}