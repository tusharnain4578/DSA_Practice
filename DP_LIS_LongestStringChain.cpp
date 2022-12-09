#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// practice --> https://leetcode.com/problems/longest-string-chain/

//
//
// Approaches ->

// Tabulation Approach ------------------------------------------

bool comp(const string &a, const string &b) // comparator
{
    return b.size() > a.size();
}

bool is_valid(const string &a, const string &b) // a is shorter, b is larger
{
    if (b.size() != a.size() + 1)
        return false;

    int i = 0, j = 0;

    while (j < b.size())
    {
        if (a[i] == b[j])
            i++, j++;
        else
            j++;
    }

    if (i == a.size() and j == b.size())
        return true;

    return false;
}

int longestStrChain(vector<string> &words)
{
    int n = words.size();
    vector<int> dp(n);
    int res;

    dp[0] = 1;

    sort(words.begin(), words.end(), comp); // sorting the words array according to words size

    for (int index = 1; index < n; index++)
    {
        int ans = 1;

        for (int i = 0; i < index; i++)
        {
            if (is_valid(words[i], words[index]))
                ans = max(ans, dp[i] + 1);
        }

        dp[index] = ans;
    }

    res = *max_element(dp.begin(), dp.end());

    for (auto ii : dp)
        cout << ii << " ";
    cout << endl;

    return res;
}