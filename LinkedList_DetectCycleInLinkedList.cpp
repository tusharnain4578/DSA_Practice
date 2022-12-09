#include <iostream>
using namespace std;

// practice --> https://leetcode.com/problems/linked-list-cycle/
struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
// This technique of using slow and fast pointer is call Floyd Cycle Detection
bool hasCycle(ListNode *head)
{
    ListNode *slow, *fast;
    slow = fast = head;

    // we would stop if fast and fast->next reach null, reason for fast->next because fast moves 2 steps.
    while (fast != NULL && fast->next != NULL)
    {
        // fast goes 2 steps at a time
        fast = fast->next->next;

        // slow goes 1 step at a time
        slow = slow->next;

        // if they meet, its coz of loop in the list
        if (fast == slow)
            return true;
    }
    return false;
}

int main()
{
    ListNode *t1, *t2, *t3, *t4, *t5;
    t1 = new ListNode(1);
    t2 = new ListNode(2);
    t3 = new ListNode(3);
    t4 = new ListNode(4);
    t5 = new ListNode(5);
    t1->next = t2;
    t2->next = t3;
    t3->next = t4;
    t4->next = t5;
    t5->next = NULL;

    cout << hasCycle(t1);

    return 0;
}