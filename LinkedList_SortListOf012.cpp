#include <iostream>
#include <vector>
using namespace std;
// practice --->https://practice.geeksforgeeks.org/problems/given-a-linked-list-of-0s-1s-and-2s-sort-it/1

//   Node is defined as
struct Node
{
    int data;
    struct Node *next;
    Node(int x)
    {
        data = x;
        next = NULL;
    }
};

Node *segregate(Node *head)
{
    vector<int> vec(3, 0);

    Node *temp = head;

    while (temp)
    {
        vec[temp->data]++;
        temp = temp->next;
    }

    temp = head;
    int i = 0;

    while (temp)
    {
        if (vec[i] == 0)
        {
            i++;
        }
        else
        {
            temp->data = i;
            vec[i]--;
            temp = temp->next;
        }
    }

    return head;
}