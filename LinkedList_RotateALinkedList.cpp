#include <iostream>
using namespace std;

// practice --> https://leetcode.com/problems/rotate-list/
struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode *rotateRight(ListNode *head, int k)
{
    // reference ---> https://www.youtube.com/watch?v=9VPm6nEbVPA
    if (head == NULL || head->next == NULL || k == 0)
        return head;
    int length = 0;
    ListNode *temp = head;
    ListNode *ans;
    while (temp->next)
    {
        length++;
        temp = temp->next;
    }
    length++;
    k = k % length;

    temp->next = head;

    k = length - k;
    while (k--)
        temp = temp->next;

    ans = temp->next;
    temp->next = NULL;
    return ans;
}

int main()
{
    ListNode *t1, *t2, *t3, *t4, *t5, *t6;
    t1 = new ListNode(1);
    t2 = new ListNode(2);
    t3 = new ListNode(3);
    t4 = new ListNode(4);
    t5 = new ListNode(5);
    // t6 = new ListNode(6);
    t1->next = t2;
    t2->next = t3;
    t3->next = t4;
    t4->next = t5;
    t5->next = NULL;

    ListNode *h = rotateRight(t1, 12);

    while (h)
    {
        cout << h->val << " ";
        h = h->next;
    }

    return 0;
}