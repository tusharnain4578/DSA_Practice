#include <iostream>
using namespace std;

// practice --> https://practice.geeksforgeeks.org/problems/remove-loop-in-linked-list/1#

// structure of linked list node :
struct Node
{
    int data;
    Node *next;

    Node(int val)
    {
        data = val;
        next = NULL;
    }
};

// Using Floyd Cycle Detection Algo
void removeLoop(Node *head)
{
    // first complete Find The Starting Point Of Cycle In The Linked List

    // reference ---> https://www.youtube.com/watch?v=qsPoOVAHV_I
    Node *slow, *fast, *entry;
    slow = fast = entry = head;

    while (fast and fast->next)
    {
        slow = slow->next;
        fast = fast->next->next;

        if (slow == fast)
            break;
    }

    if (fast == slow)
    {

        if (entry == slow) // special edge case for the cycle of last element points to first element, that means if the starting point of the loop/cycle is the first element(head)
        {
            while (slow->next != entry)
                slow = slow->next;
        }
        else
        {
            while (entry->next != slow->next)
            {
                entry = entry->next;
                slow = slow->next;
            }
        }
        slow->next = NULL;
    }
}

int main()
{
    Node *t1, *t2, *t3, *t4, *t5;

    t1 = new Node(1);
    t2 = new Node(2);
    t3 = new Node(3);
    t4 = new Node(4);
    t5 = new Node(5);

    t1->next = t2;
    t2->next = t3;
    t3->next = t4;
    t4->next = t5;
    t5->next = t3;

    removeLoop(t1);

    while (t1)
    {
        cout << t1->data << " ";
        t1 = t1->next;
    }

    return 0;
}