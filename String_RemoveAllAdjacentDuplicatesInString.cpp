#include <iostream>
#include <stack>
#include <algorithm>
using namespace std;
// practice ---> https://leetcode.com/problems/remove-all-adjacent-duplicates-in-string/

// a very similar problem, try it too -> https://leetcode.com/problems/make-the-string-great/

// Very classical and important problem

// approach 1 -> using STACK
string removeDuplicates(string s)
{
    int n = s.size();

    string ans;

    stack<char> st;

    for (const char &ch : s)
    {
        if (!st.empty() and st.top() == ch)
            st.pop();
        else
            st.push(ch);
    }

    while (!st.empty())
    {
        ans.push_back(st.top());
        st.pop();
    }

    reverse(ans.begin(), ans.end());

    return ans;
}

//
// approach 2 -> without Stack (why use stack, when you can just use string like that)
string removeDuplicates(string s)
{
    int n = s.size();

    string ans;

    for (const char &ch : s)
    {
        if (!ans.empty() and ans.back() == ch)
            ans.pop_back();
        else
            ans.push_back(ch);
    }

    return ans;
}