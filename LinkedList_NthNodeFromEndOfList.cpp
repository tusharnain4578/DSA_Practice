#include <iostream>
using namespace std;
// practice ---> https://practice.geeksforgeeks.org/problems/nth-node-from-end-of-linked-list/1

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

// Below are two methods -> Bruteforce and Optimal

// Function to find the data of nth node from the end of a linked list.
// BRUTE FOrce
int getNthFromLast(Node *head, int n)
{
    if (!head)
        return -1;

    int listSize = 0;

    Node *temp = head;

    while (temp)
    {
        listSize++;
        temp = temp->next;
    }

    if (n > listSize)
        return -1;

    temp = head;

    int nthNode = listSize - n;

    while (nthNode--)
        temp = temp->next;

    return temp->data;
}

//**************************************************************
// Optimizak -> Slow and Fast Pointer approach
int getNthFromLast(Node *head, int n)
{
    if (!head)
        return -1;

    Node *slow = head, *fast = head;

    while (n != 1)
    {
        if (fast->next == NULL)
            return -1;

        fast = fast->next;
        n--;
    }

    while (fast->next)
    {
        slow = slow->next;
        fast = fast->next;
    }

    return slow->data;
}