#include <iostream>
#include <stack>
using namespace std;

void insertAtBottom(stack<int> &st, int x)
{
    // reference ---> https://www.youtube.com/watch?v=vFP5MfBv8S0
    if (st.empty())
        st.push(x);
    else
    {
        int a = st.top();
        st.pop();
        insertAtBottom(st, x);
        st.push(a);
    }
}

void reverseStack(stack<int> &st)
{
    if (st.empty())
        return;

    int a = st.top();
    st.pop();
    reverseStack(st);
    insertAtBottom(st, a);
}

void printStack(stack<int> st)
{
    while (!st.empty())
    {
        cout << st.top() << endl;
        st.pop();
    }
}

int main()
{
    stack<int> st;
    st.push(1), st.push(2), st.push(3), st.push(4);
    reverseStack(st);
    printStack(st);

    return 0;
}