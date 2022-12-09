#include <iostream>
#include <stack>
using namespace std;

// practice --> https://practice.geeksforgeeks.org/problems/sort-a-stack/1
void insertAtCorrectPosition(stack<int> &st, int x)
{
    // reference ---> https://www.youtube.com/watch?v=XNAv8NrAwng
    // Totally same as reversing stack, just 2 lines are different
    if (st.empty() || st.top() < x)
        st.push(x);
    else
    {
        int a = st.top();
        st.pop();
        insertAtCorrectPosition(st, x);
        st.push(a);
    }
}

void sortStack(stack<int> &st)
{
    if (st.empty())
        return;

    int a = st.top();
    st.pop();
    sortStack(st);
    insertAtCorrectPosition(st, a);
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
    st.push(5), st.push(1), st.push(3), st.push(2);
    sortStack(st);
    printStack(st);

    return 0;
}