#include <iostream>
#include <stack>
using namespace std;

// reference ---> https://www.youtube.com/watch?v=SDTdWMuP5a8
// reference is also available in helper folder
// There are two solution, first is with stack, second is without stack which is better

//  stack solution
int longestValidParentheses(string s)
{
    //--------------------------------------------
    // Approach->
    //  ->create a stack and push -1 initially
    //  ->iterate over the string
    //  ->if there is a '(', push it in the stack
    //  ->if there is a ')', pop from the stack, after popping, if the stack becomes
    //  empty, push the founded ')' in the stack. If the stack is not empty, then just
    //   update the maxlength with i - st.top(), this is a valid parenthesis
    //--------------------------------------------
    stack<int> st;
    st.push(-1);

    int maxlength = 0;

    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == '(')
        {
            st.push(i);
        }
        else
        {
            st.pop();

            if (st.empty())
                st.push(i);
            else
                maxlength = max(maxlength, i - st.top());
        }
    }
    return maxlength;
}

// Second Approach (better) -> kinda' like some counting approach
int findMaxLen(string s)
{
    // In short, we just counting the valid parenthesis max length from left to right,
    // then from right to left
    // and return what's maximum

    int open = 0, close = 0;
    int maxlength = 0;

    // left to right traversal
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == '(')
            open++;
        else
            close++;

        if (open == close)
            maxlength = max(maxlength, 2 * open); // 2*open or 2*close they're equal
        else if (close > open)
            open = close = 0;
    }

    close = open = 0; // resetting values for other traversal from right to left

    // right to left traversal
    for (int i = s.size() - 1; i >= 0; i--)
    {
        if (s[i] == '(')
            open++;
        else
            close++;

        if (open == close)
            maxlength = max(maxlength, 2 * open); // 2*open or 2*close they're equal
        else if (open > close)
            open = close = 0;
    }

    return maxlength;
}