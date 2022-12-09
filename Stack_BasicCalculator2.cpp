#include <iostream>
#include <stack>
using namespace std;
// practice ---> https://leetcode.com/problems/basic-calculator-ii/

// just +, -, *, / operations with only ( and ) brackets,

// reference --> https://www.youtube.com/watch?v=sfM4DjMfhw4

int calculate(string s)
{
    int n = s.size();

    char operation = '+';

    int currNumber = 0;

    stack<int> st;

    for (int i = 0; i < n; i++)
    {
        char const &ch = s[i];

        if (isdigit(ch))
        {
            currNumber = currNumber * 10 + (ch - '0');
        }

        if (!isdigit(ch) and !iswspace(ch) or i == n - 1)
        {
            if (operation == '+')
                st.push(+currNumber);
            else if (operation == '-')
                st.push(-currNumber);
            else if (operation == '*')
            {
                int stackTop = st.top();
                st.pop();

                st.push(currNumber * stackTop);
            }
            else if (operation == '/')
            {
                int stackTop = st.top();
                st.pop();

                st.push(stackTop / currNumber);
            }

            currNumber = 0;
            operation = ch;
        }
    }

    int ans = 0;

    while (!st.empty())
    {
        ans += st.top();
        st.pop();
    }

    return ans;
}

int main()
{
    cout << calculate("3+2*2") << endl;

    return 0;
}