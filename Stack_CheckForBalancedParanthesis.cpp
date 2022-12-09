#include <iostream>
#include <stack>
using namespace std;

bool isValid(string s)
{
    stack<char> st;

    for (char &ch : s)
    {
        if (ch == '(' || ch == '[' || ch == '{')
            st.push(ch);
        else
        {
            if (st.empty())
                return false;
            char temp = st.top();
            st.pop();
            if (ch == ')' && temp == '(' || ch == ']' && temp == '[' || ch == '}' && temp == '{')
                continue;
            return false;
        }
    }
    return st.empty(); // it will return true, if stack's empty or false if it's not
}

int main()
{
    string s = "()[{}()]";
    if (isValid(s))
        cout << "True" << endl;
    else
        cout << "False" << endl;
}