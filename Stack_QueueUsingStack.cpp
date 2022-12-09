#include <iostream>
#include <stack>
using namespace std;

class QueueUsingStack
{
    stack<int> input, output;

public:
    void Push(int x)
    {
        input.push(x);
    }
    void Pop()
    {
        if (output.empty())
        {
            while (!input.empty())
            {
                output.push(input.top());
                input.pop();
            }
        }
        output.pop();
    }
    int Top()
    {
        if (output.empty())
        {
            while (!input.empty())
            {
                output.push(input.top());
                input.pop();
            }
        }
        return output.top();
    }
    int Size()
    {
        return input.size() + output.size();
    }
};

int main()
{
    QueueUsingStack q;
    q.Push(3);
    q.Push(4);
    q.Pop();
    q.Push(5);
    cout << "The top of the queue is " << q.Top() << endl;
    cout << "The size of the queue is " << q.Size() << endl;
}