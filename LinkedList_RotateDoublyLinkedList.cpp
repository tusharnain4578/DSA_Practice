#include <iostream>
using namespace std;
// practice ---> https://practice.geeksforgeeks.org/problems/rotate-doubly-linked-list-by-p-nodes/1

class Node
{
public:
    int data;
    Node *next, *prev;

    Node(int x)
    {
        data = x;
        next = NULL;
        prev = NULL;
    }
};

Node *rotateDLL(Node *start, int p)
{
    Node *temp = start;
    Node *newHead = new Node(-1);
    Node *ptr = newHead;

    int i = 0;
    while (i < p - 1)
    {
        temp = temp->next;
        i++;
    }

    ptr->next = temp->next;
    ptr->next->prev = NULL;
    temp->next = NULL;

    while (ptr->next)
    {
        ptr = ptr->next;
    }
    ptr->next = start;
    start->prev = ptr;

    return newHead->next;
}