#include <iostream>
using namespace std;
// practice ---> https://practice.geeksforgeeks.org/problems/reverse-a-doubly-linked-list/1

class Node
{
public:
    int data;
    Node *prev, *next;

    Node(int data) : data(data), prev(NULL), next(NULL) {}
};

Node *reverse(Node *head)
{
    // Basically, in every node, we just have to swap the prev and next node
    //  reference ---> https://www.youtube.com/watch?v=toz8PrZRFMc
    if (head == NULL or head->next == NULL)
        return head;

    Node *curr = head;

    while (curr->next)
        curr = curr->next;

    head = curr;

    while (curr)
    {
        Node *temp = curr->next;
        curr->next = curr->prev;
        curr->prev = temp;
        curr = curr->next;
    }

    return head;
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

    Node *ans = reverse(list);

    while (ans)
    {
        cout << ans->data << " ";
        ans = ans->next;
    }

    return 0;
}