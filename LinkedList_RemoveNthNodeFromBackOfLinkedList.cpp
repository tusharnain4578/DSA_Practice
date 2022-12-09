#include <iostream>
using namespace std;

// Definition for singly-linked list.
struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode *removeNthFromEnd(ListNode *head, int n)
{
    // reference ---> https://www.youtube.com/watch?v=Lhu3MsXZy-Q

    ListNode *dummy = new ListNode(-1, head);
    ListNode *slow = dummy, *fast = dummy;

    for (int i = 0; i < n; i++)
        fast = fast->next;

    while (fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next;
    }
    slow->next = slow->next->next;

    return dummy->next;
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

    ListNode *h = removeNthFromEnd(t1, 1);

    while (h)
    {
        cout << h->val << " ";
        h = h->next;
    }

    return 0;
}
