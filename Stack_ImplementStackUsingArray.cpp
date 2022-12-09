#include <iostream>
using namespace std;

class Stack
{
    int *arr;
    int size;
    int top;

public:
    Stack(int max_size = 1000)
    {
        size = max_size;
        arr = new int(size);
        top = -1;
    }

    void Push(int x)
    {
        if (top != size - 1)
            arr[++top] = x;
    }

    int Pop()
    {
        if (top != -1)
            top--;
    }

    int Top()
    {
        return arr[top];
    }

    int Size()
    {
        return top + 1;
    }
};

int main()
{

    Stack s;
    s.Push(6);
    s.Push(3);
    s.Push(7);
    cout << "Top of stack is before deleting any element " << s.Top() << endl;
    cout << "Size of stack before deleting any element " << s.Size() << endl;
    s.Pop();
    cout << "Size of stack after deleting an element " << s.Size() << endl;
    cout << "Top of stack after deleting an element " << s.Top() << endl;
    return 0;
}