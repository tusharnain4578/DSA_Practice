#include <iostream>
using namespace std;
// practice --> https://practice.geeksforgeeks.org/problems/segregate-even-and-odd-nodes-in-a-linked-list5035/1

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

Node *divide(int N, Node *head)
{
    Node *even = new Node(-1);
    Node *odd = new Node(-1);
    Node *e = even, *o = odd;

    Node *curr = head;

    while (curr)
    {
        if (curr->data % 2 == 0)
        {
            e->next = curr;
            e = e->next;
        }
        else
        {
            o->next = curr;
            o = o->next;
        }

        curr = curr->next;
    }

    // so that the last element of the final list won't point to any other node
    o->next = NULL;

    // linking both lists, both of their next's because the first node is -1 in both
    e->next = odd->next;

    // returning even->next, because first node is -1;
    return even->next;
}

int main()
{
    Node *t1, *t2, *t3, *t4, *t5, *t6, *t7;
    t1 = new Node(17);
    t2 = new Node(15);
    t3 = new Node(8);
    t4 = new Node(9);
    t5 = new Node(2);
    t6 = new Node(4);
    t7 = new Node(6);
    t1->next = t2;
    t2->next = t3;
    t3->next = t4;
    t4->next = t5;
    t5->next = t6;
    t6->next = t7;
    t7->next = NULL;

    Node *ans = divide(7, t1);

    while (ans)
    {
        cout << ans->data << " ";
        ans = ans->next;
    }

    return 0;
}