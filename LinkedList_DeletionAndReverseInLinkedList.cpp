#include <iostream>
using namespace std;
// practice --> https://practice.geeksforgeeks.org/problems/deletion-and-reverse-in-linked-list/1

struct Node
{
    int data;
    struct Node *next;
};

/* Function to delete a given node from the list */
void deleteNode(struct Node **head, int key)
{
    Node *curr = *head;
    while (curr->next)
    {
        if (curr->next->data == key)
        {
            curr->next = curr->next->next;
            break;
        }

        curr = curr->next;
    }
}

/* Function to reverse the linked list */
void reverse(struct Node **head_ref)
{
    Node *curr = *head_ref, *prev = NULL, *next;
    Node *head = *head_ref;

    while (curr->next != head)
    {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }

    curr->next = prev;
    prev = curr;
    head->next = prev;

    *head_ref = curr;
}