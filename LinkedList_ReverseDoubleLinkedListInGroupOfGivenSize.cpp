#include <iostream>
using namespace std;
// can't find any practice link 🥲
// All this work, did on my own

class Node
{
public:
    int data;
    Node *prev, *next;

    Node(int data) : data(data), prev(NULL), next(NULL) {}
};

Node *reverseK(Node *head, int k)
{

    if (head == NULL or head->next == NULL)
        return head;

    Node *curr = head, *prev = NULL, *next = NULL;
    int count = 0;

    while (curr != NULL and count < k)
    {
        next = curr->next;
        curr->next = prev;
        curr->prev = next;
        prev = curr;
        curr = next;

        count++;
    }

    if (next)
        head->next = reverseK(next, k);

    return prev;
}

int main()
{
    Node *list = new Node(1);
    Node *l1 = new Node(4);
    Node *l2 = new Node(7);
    Node *l3 = new Node(2);
    Node *l4 = new Node(9);
    Node *l5 = new Node(5);
    Node *l6 = new Node(0);
    Node *l7 = new Node(11);
    Node *l8 = new Node(8);
    Node *l9 = new Node(17);

    list->next = l1;
    l1->next = l2;
    l2->next = l3;
    l3->next = l4;
    l4->next = l5;
    l5->next = l6;
    l6->next = l7;
    l7->next = l8;
    l8->next = l9;

    l9->prev = l8;
    l8->prev = l7;
    l7->prev = l6;
    l6->prev = l5;
    l5->prev = l4;
    l4->prev = l3;
    l3->prev = l2;
    l2->prev = l1;
    l1->prev = list;

    Node *ans = reverseK(list, 4);

    while (ans)
    {
        cout << ans->data << " ";
        ans = ans->next;
    }

    return 0;
}