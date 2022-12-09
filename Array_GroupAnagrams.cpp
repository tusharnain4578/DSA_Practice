#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;
// practice --> https://leetcode.com/problems/group-anagrams/

vector<vector<string>> groupAnagrams(vector<string> &strs)
{
    int n = strs.size();
    unordered_map<string, vector<string>> mp;
    vector<vector<string>> ans;

    for (string &str : strs)
    {
        string temp = str;
        sort(str.begin(), str.end());

        mp[str].push_back(temp);
    }

    for (auto x : mp)
        ans.push_back(x.second); // x.second is the vector of the sorted string

    return ans;
}