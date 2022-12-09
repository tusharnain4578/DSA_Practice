#include <iostream>
using namespace std;

// practice --> https://leetcode.com/problems/delete-node-in-a-linked-list/
struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

void deleteNode(ListNode *node)
{
    node->val = node->next->val;
    node->next = node->next->next;
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

    ListNode *ans = t1;
    deleteNode(t4);
    while (ans)
    {
        cout << ans->val << " ";
        ans = ans->next;
    }

    return 0;
}