#include <iostream>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
// reference ---> https://www.youtube.com/watch?v=n5_9DMCX0Yk

ListNode *merge(ListNode *h1, ListNode *h2)
{
    if (h1 == NULL)
        return h2;
    if (h2 == NULL)
        return h1;

    ListNode *head1 = h1, *head2 = h2;

    ListNode *dummyNode = new ListNode(-1);
    ListNode *t = dummyNode;

    // same as while(head1 != NULL && head2 != NULL)
    while (head1 && head2)
    {
        if (head1->val < head2->val)
        {
            t->next = head1;
            head1 = head1->next;
        }
        else
        {
            t->next = head2;
            head2 = head2->next;
        }
        t = t->next;
    }

    // while (head1 != NULL)
    // {
    //     t->next = head1;
    //     head1 = head1->next;
    //     t = t->next;
    // }
    // while (head2 != NULL)
    // {
    //     t->next = head2;
    //     head2 = head2->next;
    //     t = t->next;
    // }

    // Instead of the above crap, it's smart to use the below method for leftover data

    if (head1)
        t->next = head1;
    else
        t->next = head2;

    return dummyNode->next;
}

int main()
{
    // List 1;
    ListNode *t1, *t2, *t3, *t4, *t5;
    t1 = new ListNode(1);
    t2 = new ListNode(3);
    t3 = new ListNode(5);
    t4 = new ListNode(7);
    t5 = new ListNode(9);
    t1->next = t2;
    t2->next = t3;
    t3->next = t4;
    t4->next = t5;
    t5->next = NULL;

    // List 2
    ListNode *p1, *p2, *p3, *p4, *p5;
    p1 = new ListNode(2);
    p2 = new ListNode(4);
    p3 = new ListNode(6);
    p4 = new ListNode(8);
    p5 = new ListNode(10);
    p1->next = p2;
    p2->next = p3;
    p3->next = p4;
    p4->next = p5;
    p5->next = NULL;

    ListNode *h = merge(p1, t1);

    while (h != NULL)
    {
        cout << h->val << " ";
        h = h->next;
    }

    return 0;
}