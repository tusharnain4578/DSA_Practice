#include <iostream>
#include <stack>
using namespace std;
// practice ---> https://leetcode.com/problems/basic-calculator/

// LC HARD 🔥
// just + and - operations with only ( and ) brackets, there's a Basic Calculator II with * and / operations as well

int calculate(string s)
{
    int n = s.size();

    int result = 0, sum = 0;
    int sign = 1; // 1 for positive, -1 for negative

    stack<int> st;

    for (int i = 0; i < n; i++)
    {
        const char &currChar = s[i];

        if (isdigit(currChar))
        {
            sum = currChar - '0';

            while (i + 1 < n and isdigit(s[i + 1]))
            {
                sum = sum * 10 + (s[i + 1] - '0'); // collecting the continuous number digits
                cout << sum << "-" << endl;
                i++;
            }

            result += sum * sign;
        }
        else if (currChar == '+')
        {
            sign = 1;
        }
        else if (currChar == '-')
        {
            sign = -1;
        }
        else if (currChar == '(')
        {
            st.push(result);
            st.push(sign);

            result = 0;
            sign = 1;
        }
        else if (currChar == ')')
        {
            int sign_from_stack = st.top();
            st.pop();

            int result_from_stack = st.top();
            st.pop();

            result = result * sign_from_stack + result_from_stack;
        }
    }

    return result;
}