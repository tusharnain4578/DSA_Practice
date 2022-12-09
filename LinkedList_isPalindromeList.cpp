#include <iostream>
using namespace std;
// practice --> https://leetcode.com/problems/palindrome-linked-list/

// other way (simple) -> LinkedList_PalidromeLinkedList.cpp
struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode *reverse(ListNode *head)
{
    if (head == NULL || head->next == NULL)
        return head;

    ListNode *prev = NULL, *next;

    while (head)
    {
        next = head->next;
        head->next = prev;
        prev = head;
        head = next;
    }
    return prev;
}

bool isPalindrome(ListNode *head)
{
    // reference ---> https://www.youtube.com/watch?v=-DtNInqFUXs
    ListNode *slow = head, *fast = head;
    while (fast->next && fast->next->next)
    {
        slow = slow->next;
        fast = fast->next->next;
    }

    slow->next = reverse(slow->next);

    ListNode *t = head;
    slow = slow->next;

    while (slow)
    {
        if (slow->val != t->val)
            return false;

        slow = slow->next;
        t = t->next;
    }
    return true;
}

int main()
{
    ListNode *t1, *t2, *t3, *t4, *t5;
    t5 = new ListNode(2, NULL);
    t4 = new ListNode(1, t5);
    t3 = new ListNode(1, t4);
    t2 = new ListNode(1, t3);
    t1 = new ListNode(2, t2);
    // t1->next = t2;
    // t2->next = t3;
    // t3->next = t4;
    // t4->next = t5;
    // t5->next = NULL;

    ListNode *s1, *s2, *s3, *s4, *s5;
    s5 = new ListNode(10, NULL);
    s4 = new ListNode(8, s5);
    s3 = new ListNode(6, s4);
    s2 = new ListNode(4, s3);
    s1 = new ListNode(2, s2);
    // s1->next = s2;
    // s2->next = s3;
    // s3->next = s4;
    // s4->next = s5;
    // s5->next = NULL;
    cout << isPalindrome(t1);

    return 0;
}