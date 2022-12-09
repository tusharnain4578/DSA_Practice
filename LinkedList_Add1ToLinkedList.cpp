#include <iostream>
using namespace std;
// practice --> https://practice.geeksforgeeks.org/problems/add-1-to-a-number-represented-as-linked-list/1

// Linked List
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

void reverse(Node *&head)
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

Node *addOne(Node *head)
{
    // same approach used in Array_PlusOne.cpp
    reverse(head);

    Node *curr = head;

    while (curr != NULL)
    {
        if (curr->data == 9)
        {
            curr->data = 0;
        }
        else
        {
            curr->data++;
            break;
        }
        curr = curr->next;
    }

    if (curr == NULL)
    {
        Node *newNode = new Node(1);
        newNode->next = head;
        head = newNode;
    }
    else
    {
        reverse(head);
    }
    return head;
}