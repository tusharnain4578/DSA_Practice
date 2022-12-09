#include <iostream>
using namespace std;

// practice --> https://leetcode.com/problems/intersection-of-two-linked-lists/
struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
{
    // reference ---> https://www.youtube.com/watch?v=u4FWXfgS8jw
    // Worst Time Complexity will be O(2N)
    ListNode *ptr1 = headA, *ptr2 = headB;

    while (ptr1 != ptr2)
    {
        ptr1 = ptr1 == NULL ? headB : ptr1->next;
        ptr2 = ptr2 == NULL ? headA : ptr2->next;
    }
    return ptr1;
}

int main()
{
    ListNode *t1, *t2, *t3, *t4, *t5;
    t1 = new ListNode(1);
    t2 = new ListNode(2);
    t3 = new ListNode(3);
    t4 = new ListNode(15);
    t5 = new ListNode(5);
    t1->next = t2;
    t2->next = t3;
    t3->next = t4;
    t4->next = t5;
    t5->next = NULL;

    ListNode *p1, *p2, *p3, *p4, *p5;
    p1 = new ListNode(1);
    p2 = new ListNode(2);
    p3 = new ListNode(3);
    p4 = new ListNode(4);
    p5 = new ListNode(5);
    p1->next = p2;
    p2->next = p3;
    p3->next = t4;
    p4->next = p5;
    p5->next = NULL;

    cout << getIntersectionNode(t1, p1)->val;
    return 0;
}