#include <iostream>
using namespace std;
// practice ---> https://www.youtube.com/watch?v=I5uKH3BWsLc

// this programm is not removig the starting 0's
//  like

// 0 0 0 0 0
// 0 0 0 2 3 4 0
// this is the output of this program, which should be
// 0
// 2 3 4 0
// you have to manually remove these, easy peasy 😎

class Node
{
public:
    int data;
    Node *next;
    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
};

// Reverse function for linked list
Node *reverse(Node *head)
{
    if (head == NULL or head->next == NULL)
        return head;

    Node *curr = head, *prev = NULL, *next = NULL;

    while (curr)
    {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    return prev;
}

// LL multiply with single number
Node *multiplyListWithADigit(Node *head, int x)
{
    Node *curr = head;

    Node *dummy = new Node(-1);
    Node *t = dummy;

    int carry = 0;

    while (curr != NULL or carry != 0)
    {
        int sum = carry + (curr ? curr->data : 0) * x;

        int nodeDigit = sum % 10;
        carry = sum / 10;

        t->next = new Node(nodeDigit);

        if (curr)
            curr = curr->next;

        t = t->next;
    }

    return dummy->next;
}

// returning new list by Adding two lists
Node *addTwoLinkedLists(Node *head1, Node *head2)
{
    Node *l1 = head1, *l2 = head2;

    Node *dummy = new Node(-1);
    Node *t = dummy;

    int carry = 0;

    while (l1 or l2 or carry)
    {
        int sum = (l1 ? l1->data : 0) + (l2 ? l2->data : 0) + carry;

        if (l1)
            l1 = l1->next;
        if (l2)
            l2 = l2->next;

        carry = sum / 10;
        int newDigit = sum % 10;
        t->next = new Node(newDigit);
        t = t->next;
    }
    return dummy->next;
}

// removing starting 0's function
Node *removeZeroes(Node *head)
{
    Node *curr = head;

    while (curr and curr->data == 0)
    {
        // this if condition is for avoiding removing the single 0 output
        if (curr->next == NULL)
            return curr;

        curr = curr->next;
    }

    return curr;
}

// LL multiply function
Node *multiplyLL(Node *head1, Node *head2)
{
    head1 = reverse(head1);
    head2 = reverse(head2);

    Node *head1_itr = head1;
    Node *head2_itr = head2;

    Node *ans = new Node(0);
    Node *t = ans;

    int i = 0;

    while (head2_itr)
    {
        // cout << "jjj";
        Node *product = multiplyListWithADigit(head1, head2_itr->data);

        for (int j = 0; j < i; j++)
        {
            Node *temp = product;
            product = new Node(0);
            product->next = temp;
        }

        ans = addTwoLinkedLists(product, ans);

        head2_itr = head2_itr->next;

        i++;
    }

    // reversing to get original product back
    ans = reverse(ans);

    // removing starting zeroes
    ans = removeZeroes(ans);

    return ans;
}

int main()
{
    Node *t1, *t2, *t3;
    t1 = new Node(2);
    t2 = new Node(4);
    t3 = new Node(3);
    t1->next = t2;
    t2->next = t3;
    t3->next = NULL;

    Node *p1, *p2, *p3;
    p1 = new Node(5);
    p2 = new Node(6);
    p3 = new Node(4);
    p1->next = p2;
    p2->next = p3;
    p3->next = NULL;

    Node *ans = multiplyLL(t1, p1);

    while (ans)
    {
        cout << ans->data << " ";
        ans = ans->next;
    }

    return 0;
}