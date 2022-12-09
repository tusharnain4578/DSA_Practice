#include <iostream>
#include <queue>
using namespace std;
// practice ---> https://www.codingninjas.com/codestudio/problems/sort-a-k-sorted-doubly-linked-list_1118118

// same approach used in Array_SortKSortedArray.cpp

/****************************************************************/
// Following is the class structure of the Node class:
class Node
{
public:
    int data;
    Node *next;
    Node *prev;
    Node(int data)
    {
        this->data = data;
        this->next = NULL;
        this->prev = NULL;
    }
};
/*****************************************************************/

// Custom Comparator for priority queue
// Comparator for making it min heap

class customComparator
{
public:
    bool operator()(Node *a, Node *b)
    {
        return a->data > b->data;
    }
};

Node *sortedDll(Node *head, int k)
{
    priority_queue<Node *, vector<Node *>, customComparator> pq;

    Node *temp = head;

    Node *newHead = new Node(-1);
    Node *ptr = newHead;

    while (temp)
    {
        pq.push(temp);

        if (pq.size() > k)
        {
            Node *node = pq.top();
            pq.pop(); // extracting minimum node from min-heap priority queue

            ptr->next = node;
            node->prev = ptr;
            ptr = ptr->next; // or ptr = node, they're some btw
        }
        temp = temp->next;
    }

    while (!pq.empty())
    {
        Node *node = pq.top();
        pq.pop(); // extracting minimum node from min-heap priority queue

        ptr->next = node;
        node->prev = ptr;
        ptr = ptr->next;
    }

    newHead->next->prev = NULL;
    return newHead->next;
}