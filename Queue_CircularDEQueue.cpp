#include <iostream>
using namespace std;

class queue
{
    int size;
    int f, r;
    int *q;

public:
    queue(int n) : size(n)
    {
        q = new int[n];
        f = r = -1;
    }
    void frontenqueue(int n)
    {
        if ((r + 1) % size == f)
        {
            cout << "overflow!!" << endl;
            return;
        }
        if (f == -1)
            f = r = 0;
        else if (f == 0)
            f = size - 1;
        else
            f--;

        q[f] = n;
    }
    void rearenqueue(int n)
    {
        if ((r + 1) % size == f)
        {
            cout << "overflow!!" << endl;
            return;
        }
        if (r == -1)
            f = r = 0;
        else
            r = (r + 1) % size;

        q[r] = n;
    }
    void frontdequeue()
    {
        if (f == -1)
            cout << "underflow!!" << endl;
        else if (f == r)
            f = r = -1;
        else
            f = (f + 1) % size;
    }
    void reardequeue()
    {
        if (r == -1)
            cout << "underflow!!" << endl;
        else if (r == f)
            f = r = -1;
        else if (r == 0)
            r = size - 1;
        else
            r--;
    }
    void display()
    {
        int t = f;
        while (t != r)
        {
            cout << q[t] << " ";
            t = (t + 1) % size;
        }
        cout << q[t] << endl;
    }
};

int main()
{
    queue q(7);

    q.rearenqueue(1);
    q.rearenqueue(2);
    q.rearenqueue(3);
    q.frontenqueue(5);
    q.frontenqueue(6);
    q.frontenqueue(7);
    q.frontenqueue(8);

    q.reardequeue();
    q.frontdequeue();
    q.display();

    return 0;
}