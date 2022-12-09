#include <iostream>
#include <vector>
using namespace std;

bool is_palindrom(const string &s, int start, int end)
{
    while (start <= end)
        if (s[start++] != s[end--])
            return false;

    return true;
}

void solve(const string &s, int index, vector<string> &ds, vector<vector<string>> &ans)
{
    // reference ---> https://www.youtube.com/watch?v=WBgsABoClE0

    if (index == s.length())
    {
        ans.push_back(ds);
        return;
    }
    for (int i = index; i < s.length(); i++)
    {
        if (is_palindrom(s, index, i))
        {
            ds.push_back(s.substr(index, i - index + 1));
            solve(s, i + 1, ds, ans);
            ds.pop_back();
        }
    }
}

vector<vector<string>> partition(string s)
{
    vector<string> ds;
    vector<vector<string>> ans;
    solve(s, 0, ds, ans);
    return ans;
}

int main()
{
    string s = "aabb";
    vector<vector<string>> ans = partition(s);
    for (auto &&i : ans)
    {
        for (auto &&j : i)
            cout << j << " ";
        cout << endl;
    }

    return 0;
}