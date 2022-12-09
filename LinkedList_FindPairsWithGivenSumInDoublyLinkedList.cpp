#include <iostream>
#include <vector>
using namespace std;
// practice --> https://practice.geeksforgeeks.org/problems/find-pairs-with-given-sum-in-doubly-linked-list/1

// Linked List Class
class Node
{
public:
    int data;
    Node *next, *prev;
    Node(int val) : data(val), next(NULL), prev(NULL) {}
};

// same as we did in sorted Two Sum Approach
vector<pair<int, int>> findPairsWithGivenSum(Node *head, int target)
{
    vector<pair<int, int>> ans;

    Node *left = head, *right = head;

    // placing right pointer
    while (right->next != NULL)
        right = right->next;

    while (left != right and left->prev != right)
    {
        if (left->data + right->data == target)
        {
            ans.push_back(make_pair(left->data, right->data));
            left = left->next;
            right = right->prev;
        }
        else if (left->data + right->data > target)
            right = right->prev;
        else
            left = left->next;
    }

    return ans;
}