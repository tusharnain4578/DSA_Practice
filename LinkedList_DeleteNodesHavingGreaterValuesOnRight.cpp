#include <iostream>
using namespace std;
// practice ---> https://practice.geeksforgeeks.org/problems/delete-nodes-having-greater-value-on-right/1

struct Node
{
    int data;
    Node *next;

    Node(int x)
    {
        data = x;
        next = NULL;
    }
};

// Reverse function for linked list
Node *reverse(Node *head)
{
    if (head == NULL or head->next == NULL)
        return head;

    Node *curr = head, *prev = NULL, *next = NULL;

    while (curr)
    {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    return prev;
}

// reference --> https://www.youtube.com/watch?v=cI3P6L6xgpY

// function for deleting nodes having greater values on right
Node *compute(Node *head)
{
    if (head == NULL or head->next == NULL)
        return head;

    head = reverse(head);

    int _max = head->data;

    Node *curr = head->next;
    Node *prev = head;

    while (curr)
    {
        if (curr->data >= _max)
        {
            _max = curr->data;
            prev = curr;
        }
        else
        {
            prev->next = curr->next;
        }

        curr = curr->next;
    }

    head = reverse(head);

    return head;
}