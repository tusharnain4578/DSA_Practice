#include <iostream>
using namespace std;

struct Node
{
    int data;
    struct Node *next;

    Node(int x)
    {
        data = x;
        next = NULL;
    }
};

void print(Node *head)
{
    while (head)
    {
        cout << head->data << " ";
        head = head->next;
    }
}

void reverse(Node *head)
{
    Node *prev = NULL, *nxt;

    while (head)
    {
        nxt = head->next;
        head->next = prev;
        prev = head;
        head = nxt;
    }

    head = prev;
}

int main()
{
    Node *t = new Node(1);
    t->next = new Node(2);
    t->next->next = new Node(3);

    reverse(t);

    print(t);

    return 0;
}