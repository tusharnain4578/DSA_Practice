#include <iostream>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode *reverse(ListNode *head)
{
    if (head == NULL || head->next == NULL)
        return head;

    ListNode *reveresedList = reverse(head->next);
    head->next->next = head;
    head->next = NULL;

    return reveresedList;
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

    ListNode *h = reverse(t1);
    while (h != NULL)
    {
        cout << h->val << " ";
        h = h->next;
    }

    return 0;
}