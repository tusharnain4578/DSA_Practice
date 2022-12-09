#include <iostream>
#include <stack>
using namespace std;

class MinStack
{
    // reference --->  https://www.youtube.com/watch?v=QTrNy-0Og7E
    stack<long long> *s;
    long long min_;

public:
    MinStack()
    {
        s = new stack<long long>();
        min_ = INT64_MAX;
    }

    void push(int val)
    {
        if (s->empty())
        {
            s->push(val);
            min_ = val;
        }
        else
        {
            if (val < min_)
            {
                s->push(2 * (long)val - min_); // encrypting 2x-min
                min_ = val;
            }
            else
                s->push(val);
        }
    }

    void pop()
    {
        if (s->empty())
            return;
        if (s->top() < min_)
            min_ = 2 * min_ - s->top(); // Decrypting 2x - (2x-min) = min, we'll get the value back;
        s->pop();
    }

    int top()
    {
        if (s->top() < min_)
            return min_;

        return s->top();
    }

    int getMin()
    {
        return min_;
    }

    void displayStack()
    {
        while (!s->empty())
        {
            cout << top() << " ";
            pop();
        }
    }
};

int main()
{
    MinStack m;
    m.push(5);
    m.push(12);
    m.push(13);
    m.push(4);
    m.pop();
    cout << m.getMin() << endl;
    // m.pop();
    m.displayStack();

    return 0;
}