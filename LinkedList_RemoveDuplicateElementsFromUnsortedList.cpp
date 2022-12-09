#include <iostream>
#include <unordered_map>
using namespace std;

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

// TC->O(N) and SC->O(N)
Node *removeDuplicates(Node *head)
{
    unordered_map<int, int> mp;

    Node *curr = head, *prev;

    while (curr)
    {
        mp[curr->data]++;

        if (mp[curr->data] > 1)
        {
            prev->next = curr->next;
            curr = curr->next;
        }
        else
        {
            prev = curr;
            curr = curr->next;
        }
    }

    return head;
}