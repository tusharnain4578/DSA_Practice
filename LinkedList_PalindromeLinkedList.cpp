#include <iostream>
#include <vector>
using namespace std;
// practice --> https://leetcode.com/problems/palindrome-linked-list/

// other way (recommended) -> // other way (simple) -> LinkedList_isPalidromeList.cpp

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

bool isPalindrome(ListNode *head)
{
    if (head == NULL)
        return false;
    vector<int> vec;
    ListNode *temp = head;

    while (temp)
    {
        vec.push_back(temp->val);
        temp = temp->next;
    }

    for (int i = 0; i < vec.size() / 2; i++)
        if (vec[i] != vec[vec.size() - i - 1])
            return false;

    return true;
}

int main()
{
    ListNode *t1, *t2, *t3, *t4, *t5, *t6;
    t1 = new ListNode(1);
    t2 = new ListNode(1);
    t3 = new ListNode(5);
    t4 = new ListNode(5);
    t5 = new ListNode(1);
    t6 = new ListNode(1);
    t1->next = t2;
    t2->next = t3;
    t3->next = t4;
    t4->next = t5;
    t5->next = t6;
    t6->next = NULL;

    cout << isPalindrome(t1);

    return 0;
}