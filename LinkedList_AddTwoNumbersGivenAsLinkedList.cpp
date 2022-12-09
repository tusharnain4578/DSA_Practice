#include <iostream>
using namespace std;

// practice ---> https://leetcode.com/problems/add-two-numbers/
struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
{
    // reference ---> https://www.youtube.com/watch?v=LBVsXSMOIk4
    ListNode *head1 = l1, *head2 = l2;

    int sum, carry = 0;
    ListNode *dummy = new ListNode(-1);
    ListNode *ptr = dummy;
    while (head1 != NULL || head2 != NULL || carry)
    {
        sum = (head1 ? head1->val : 0) + (head2 ? head2->val : 0) + carry;

        if (head1)
            head1 = head1->next;
        if (head2)
            head2 = head2->next;

        carry = sum / 10;
        ptr->next = new ListNode(sum % 10);
        ptr = ptr->next;
    }

    return dummy->next;
}

int main()
{
    ListNode *t1, *t2, *t3;
    t1 = new ListNode(2);
    t2 = new ListNode(4);
    t3 = new ListNode(3);
    t1->next = t2;
    t2->next = t3;
    t3->next = NULL;

    ListNode *p1, *p2, *p3;
    p1 = new ListNode(5);
    p2 = new ListNode(6);
    p3 = new ListNode(4);
    p1->next = p2;
    p2->next = p3;
    p3->next = NULL;

    ListNode *ans = addTwoNumbers(t1, p1);

    while (ans)
    {
        cout << ans->val << " ";
        ans = ans->next;
    }

    return 0;
}