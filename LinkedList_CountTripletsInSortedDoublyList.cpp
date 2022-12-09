#include <iostream>
using namespace std;
// practice --> https://www.codingninjas.com/codestudio/problems/count-triplets-in-a-sorted-doubly-linked-list-whose-sum-is-equal-to-a-given-value-x_985286

// same approact as sorted 3 sum

// Following is the class structure of the Node class:
class DLLNode
{
public:
    int data;
    DLLNode *next;
    DLLNode *prev;
};

int countPairsWithGivenSum(DLLNode *head, int target)
{
    int count = 0;

    DLLNode *left = head, *right = head;

    // placing right pointer
    while (right->next != NULL)
        right = right->next;

    while (left != right and left->prev != right)
    {
        if (left->data + right->data == target)
        {
            count++;
            left = left->next;
            right = right->prev;
        }
        else if (left->data + right->data > target)
            right = right->prev;
        else
            left = left->next;
    }

    return count;
}

int countTriplets(DLLNode *head, int target)
{
    DLLNode *curr = head;
    int ans = 0;

    while (curr->next)
    {
        int leftoverTarget = target - curr->data;

        ans += countPairsWithGivenSum(curr->next, leftoverTarget);
        curr = curr->next;
    }

    return ans;
}