#include <iostream>
#include <stack>
using namespace std;

void insertToBottom(stack<int> &st, int el)
{
    if (st.empty())
    {
        st.push(el);
        return;
    }
    int topel = st.top();
    st.pop();

    insertToBottom(st, el);

    st.push(topel);
}

void reverse(stack<int> &st)
{
    if (st.empty())
        return;

    int topel = st.top();
    st.pop();
    reverse(st);

    insertToBottom(st, topel);
}

int main()
{
    stack<int> st;
    for (int i = 0; i < 10; i++)
        st.push(i + 1);

    reverse(st);

    while (!st.empty())
    {
        cout << st.top() << " ";
        st.pop();
    }

    return 0;
}