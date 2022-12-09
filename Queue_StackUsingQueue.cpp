#include <iostream>
#include <queue>
using namespace std;

// Funda -->  We'll need two queues.
//     1.Add x to q2.
//     2.Add all elements of q1 to q2
//     3.Swap q1 and q2

class StackUsingQueue
{
    queue<int> q1, q2;

public:
    void Push(int x)
    {
        q2.push(x);

        while (!q1.empty())
        {
            q2.push(q1.front());
            q1.pop();
        }
        swap(q1, q2);
    }

    void Pop()
    {
        if (!q1.empty())
            q1.pop();
    }

    int Top()
    {
        return q1.front();
    }

    int Size()
    {
        return q1.size();
    }
};

int main()
{
    StackUsingQueue s;
    s.Push(3);
    s.Push(2);
    s.Push(4);
    s.Push(1);
    cout << "Top of the stack: " << s.Top() << endl;
    cout << "Size of the stack before removing element : " << s.Size() << endl;
    s.Pop();
    cout << "Top of the stack after removing element: " << s.Top() << endl;
    cout << "Size of the stack after removing element: " << s.Size();
}