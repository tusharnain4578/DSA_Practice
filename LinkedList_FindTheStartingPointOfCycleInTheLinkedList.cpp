#include <iostream>
using namespace std;

// practice --> https://leetcode.com/problems/linked-list-cycle-ii/
struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

// Using Floyd Cycle Detection
ListNode *detectCycle(ListNode *head)
{
    // refernce --> https://www.youtube.com/watch?v=QfbOhn0WZ88
    ListNode *fast, *slow, *entry;
    fast = slow = entry = head;

    while (fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;

        if (fast == slow)
        {
            // Instead of a 3rd variable 'entry', we can also use the fast pointer
            while (entry != slow) // here slow and fast are interchangable because they're same btw
            {
                slow = slow->next;
                entry = entry->next;
            }
            return entry;
        }
    }
    return NULL;
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

    ListNode *res = detectCycle(t1);

    if (res)
        cout << res->val << endl;
    else
        cout << "NULL" << endl;

    return 0;
}