#include <iostream>
#include <queue>
using namespace std;
// practice ---> https://practice.geeksforgeeks.org/problems/merge-k-sorted-linked-lists/1

struct Node
{
    int data;
    Node *next;

    Node(int x)
    {
        data = x;
        next = NULL;
    }
};

// Comparator for min-heap
class comp
{
public:
    bool operator()(Node *a, Node *b)
    {
        return a->data > b->data;
    }
};

// same approach as in Merge K Sorted Array
// Using Min Heap
//  reference --> https://www.youtube.com/watch?v=u8LQt_iUKps
Node *mergeKLists(Node *arr[], int K)
{
    Node *head = new Node(-1);
    Node *temp = head;

    priority_queue<Node *, vector<Node *>, comp> pq;

    for (int i = 0; i < K; i++)
        if (arr[i])
            pq.push(arr[i]);

    while (!pq.empty())
    {
        Node *least = pq.top();
        pq.pop();

        temp->next = least;
        temp = temp->next;

        if (least->next)
            pq.push(least->next);
    }

    return head->next;
}