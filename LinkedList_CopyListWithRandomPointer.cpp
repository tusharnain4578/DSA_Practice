#include <iostream>
using namespace std;

// practice --> https://leetcode.com/problems/copy-list-with-random-pointer/
//  Definition for a Node.
class Node
{
public:
    int val;
    Node *next;
    Node *random;

    Node(int _val)
    {
        val = _val;
        next = NULL;
        random = NULL;
    }
};

Node *copyRandomList(Node *head)
{
    // reference ---> https://www.youtube.com/watch?v=VNf6VynfpdM

    Node *itr = head;

    // Create copy linked list with mapping it to the original one
    while (itr)
    {
        Node *copy = new Node(itr->val);
        copy->next = itr->next;
        itr->next = copy;
        itr = itr->next->next;
    }

    itr = head;

    // linking random pointers for copied linked list
    while (itr)
    {
        if (itr->random)
            itr->next->random = itr->random->next;
        itr = itr->next->next;
    }

    Node *ans = new Node(-1);
    Node *t = ans;
    itr = head;

    // Extracting Copied linked list from original, and retrieving original linked list back

    while (itr)
    {
        t->next = itr->next;
        itr->next = itr->next->next;
        itr = itr->next;
        t = t->next;
    }

    return ans->next;
}

int main()
{
    Node *t1, *t2, *t3, *t4, *t5;
    t1 = new Node(1);
    t2 = new Node(2);
    t3 = new Node(3);
    t4 = new Node(4);
    t5 = new Node(5);
    t1->next = t2;
    t2->next = t3;
    t3->next = t4;
    t4->next = t5;
    t5->next = NULL;

    t1->random = t3;
    t2->random = NULL;
    t3->random = t5;
    t4->random = t2;
    t5->random = t1;

    Node *fans = copyRandomList(t1);
    Node *ans = fans;
    while (ans)
    {
        cout << ans->val << " ";
        ans = ans->next;
    }
    cout << endl;

    ans = fans;

    while (ans)
    {
        if (ans->random)
            cout << ans->random->val << " ";
        else
            cout << "NULL"
                 << " ";
        ans = ans->next;
    }
    return 0;
}