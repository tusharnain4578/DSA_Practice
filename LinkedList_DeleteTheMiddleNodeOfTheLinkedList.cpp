#include <iostream>
using namespace std;
// practice ---> https://leetcode.com/problems/delete-the-middle-node-of-a-linked-list/

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode *deleteMiddle(ListNode *head)
{

    if (head == NULL or head->next == NULL)
    {
        delete head;
        return NULL;
    }

    ListNode *fast, *slow, *prev;
    fast = slow = head;

    while (fast and fast->next)
    {
        prev = slow;
        slow = slow->next;
        fast = fast->next->next;
    }
    prev->next = slow->next;
    delete slow;

    return head;
}