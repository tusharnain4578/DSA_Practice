#include <iostream>
using namespace std;
// practice ---> https://practice.geeksforgeeks.org/problems/reverse-a-doubly-linked-list/1

struct Node
{
    int data;
    Node *next;
    Node *prev;
    Node(int x)
    {
        data = x;
        next = NULL;
        prev = NULL;
    }
};

Node *reverseDLL(Node *head)
{
    Node *curr = head, *prev = NULL, *next;

    while (curr)
    {
        next = curr->next;
        curr->next = prev;

        // additional line for connecting doubly linked list prev pointer
        curr->prev = next;

        prev = curr;
        curr = next;
    }

    return prev;
}