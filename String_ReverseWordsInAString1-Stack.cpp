#include <iostream>
#include <stack>
using namespace std;

// Brute Force
string reverseWords(string s)
{
    stack<string> st;
    s += " ";
    int n = s.size(); // make sure to use the s.size after s+=" "
    string ans;

    string temp;

    for (int i = 0; i < n; i++)
    {
        if (s[i] == ' ')
        {
            if (temp != "")
                st.push(temp);
            temp = "";
        }
        else
            temp += s[i];
    }

    while (st.size() > 1)
    {
        ans += st.top() + " ";

        st.pop();
    }
    ans += st.top(); // this is coz last word should not have a space after it.

    return ans;
}

int main()
{
    string str = "  hello    world  ";

    cout << "-" << reverseWords(str) << "-" << endl;

    return 0;
}