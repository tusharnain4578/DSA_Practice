#include <iostream>
using namespace std;

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

void splitList(Node *head, Node **head1_ref, Node **head2_ref)
{
    // referece ---> https://www.youtube.com/watch?v=VdGIR91xlaM

    Node *slow = head, *fast = head->next;

    // There are two reasons why we are initializing fast pointer with head->next instead of head,
    // 1. In case of even sized list, like 1,2,3,4,5,6 -> we need the 3 as middle, not 4
    // Recommend FindMiddleElement Programme
    //
    // 2. If we, initialize the fast with head, then the following while condition will not run(just look at the while condition)
    //
    // Mostly becaue of part 1

    while (fast != head and fast->next != head)
    {
        slow = slow->next;
        fast = fast->next->next;
    }

    *head1_ref = head;
    *head2_ref = slow->next;

    slow->next = *head1_ref;

    Node *temp = *head2_ref;

    while (temp->next != head)
        temp = temp->next;

    temp->next = *head2_ref;
}