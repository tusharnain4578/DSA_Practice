#include <iostream>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

// In the case of even length numbers like 1,2,3,4,5,6
// This logic will point at 4 as middle element, if you want 3 as middle, just start the fast pointer from head->next, that's all

ListNode *middle(ListNode *head)
{
    // reference ---> https://www.youtube.com/watch?v=sGdwSH8RK-o
    ListNode *slow, *fast;
    slow = fast = head;

    // we would stop if fast and fast->next reach null, reason for fast->next because fast moves 2 steps.

    // condition will be same for both even and odd length lists
    while (fast != NULL && fast->next != NULL)
    {
        // fast goes 2 steps at a time
        fast = fast->next->next;

        // slow goes 1 step at a time
        slow = slow->next;
    }

    // slow will point at mid section
    return slow;
}

int main()
{
    ListNode *t1, *t2, *t3, *t4, *t5, *t6;
    t1 = new ListNode(1);
    t2 = new ListNode(2);
    t3 = new ListNode(3);
    t4 = new ListNode(4);
    t5 = new ListNode(5);
    t6 = new ListNode(6);
    t1->next = t2;
    t2->next = t3;
    t3->next = t4;
    t4->next = t5;
    t5->next = t6;
    t6->next = NULL;

    cout << middle(t1)->val;

    return 0;
}