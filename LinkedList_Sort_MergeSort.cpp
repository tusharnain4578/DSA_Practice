#include <iostream>
using namespace std;
// practice ---> https://leetcode.com/problems/sort-list/

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

// reference --> https://www.youtube.com/watch?v=rM5EEA_rbNY
ListNode *findMiddleNode(ListNode *head)
{
    ListNode *slow, *fast;

    slow = head, fast = head->next;

    while (fast and fast->next)
    {
        fast = fast->next->next;
        slow = slow->next;
    }

    return slow;
}

ListNode *merge(ListNode *left, ListNode *right)
{
    if (left == NULL)
        return right;

    if (right == NULL)
        return left;

    ListNode *ans = new ListNode(-1);
    ListNode *temp = ans;

    while (left != NULL and right != NULL)
    {
        if (left->val < right->val)
        {
            temp->next = left;

            left = left->next;
        }
        else
        {
            temp->next = right;

            right = right->next;
        }

        temp = temp->next;
    }

    if (left != NULL)
        temp->next = left;

    if (right != NULL)
        temp->next = right;

    return ans->next;
}

ListNode *mergeSort(ListNode *head)
{
    if (head == NULL or head->next == NULL)
        return head;

    ListNode *mid = findMiddleNode(head);

    ListNode *left = head;
    ListNode *right = mid->next;

    mid->next = NULL;

    left = mergeSort(left);
    right = mergeSort(right);

    ListNode *result = merge(left, right);

    return result;
}

ListNode *sortList(ListNode *head)
{
    return mergeSort(head);
}

int main()
{
    ListNode *t1, *t2, *t3, *t4, *t5, *t6;
    t1 = new ListNode(1);
    t2 = new ListNode(5);
    t3 = new ListNode(3);
    t4 = new ListNode(2);
    t5 = new ListNode(4);
    t6 = new ListNode(6);
    t1->next = t2;
    t2->next = t3;
    t3->next = t4;
    t4->next = t5;
    t5->next = t6;
    t6->next = NULL;

    ListNode *ans = sortList(t1);

    while (ans)
    {
        cout << ans->val << " ";
        ans = ans->next;
    }

    return 0;
}