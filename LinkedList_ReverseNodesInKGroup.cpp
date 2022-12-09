#include <iostream>
using namespace std;

// practice --> https://leetcode.com/problems/reverse-nodes-in-k-group/
struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode *reverseK(ListNode *head, int k, int length)
{
    if (length < k || head == NULL || head->next == NULL)
        return head;

    ListNode *curr = head, *prev = NULL, *next;

    int count = 0;
    while (curr != NULL && count < k)
    {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
        count++;
    }

    if (next != NULL)                               // instead of next here, can also use curr, they're same here
        head->next = reverseK(next, k, length - k); // instead of next here, can also use curr, they're same here

    return prev;
}

ListNode *reverseKNodes(ListNode *head, int k)
{
    // reference ---> https://www.youtube.com/watch?v=vqaO4oIJqnI
    ListNode *ptr = head;
    int length = 0;
    while (ptr)
    {
        length++;
        ptr = ptr->next;
    }
    return reverseK(head, k, length);
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

    ListNode *h = reverseKNodes(t1, 4);

    while (h != NULL)
    {
        cout << h->val << " ";
        h = h->next;
    }

    return 0;
}