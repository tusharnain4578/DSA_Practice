#include <iostream>
using namespace std;
// practice --> https://practice.geeksforgeeks.org/problems/remove-duplicate-element-from-sorted-linked-list/1

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

// // TC->O(N) and SC->O(1)
Node *removeDuplicates(Node *head)
{
    Node *curr = head;

    while (curr and curr->next)
    {
        if (curr->data == curr->next->data)
            curr->next = curr->next->next;
        else
            curr = curr->next;
    }

    return head;
}