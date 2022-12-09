#include <iostream>
using namespace std;
// practice ---> https://leetcode.com/problems/odd-even-linked-list/

// Definition for singly-linked list.
struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode *oddEvenList(ListNode *head)
{
    ListNode *evenHead, *oddHead, *even, *odd;

    evenHead = new ListNode(-1);
    oddHead = new ListNode(-1);

    even = evenHead, odd = oddHead;

    ListNode *curr = head;

    int count = 1;

    while (curr)
    {
        if (count % 2)
        {
            odd->next = curr;
            odd = odd->next;
        }
        else
        {
            even->next = curr;
            even = even->next;
        }
        curr = curr->next;
        count++;
    }

    odd->next = evenHead->next;
    even->next = NULL;

    return oddHead->next;
}