#include <bits/stdc++.h>
using namespace std;

struct Node
{
    Node *next = NULL;
    int data;
    Node(int x)
    {
        data = x;
        next = NULL;
    }
};

//Brute force solution ---> Use 2 loops

//O(m+n) space using solution ---> Use hash table to store the visited nodes

//Proper Solution
int intersectPoint(Node *head1, Node *head2)
{
    int n1 = 0, n2 = 0;
    Node *temp;

    for (temp = head1; temp; temp = temp->next)
        n1++;

    for (temp = head2; temp; temp = temp->next)
        n2++;

    int d = abs(n1 - n2);

    Node *ptr1 = head1;
    Node *ptr2 = head2;

    if (n1 > n2)
    {
        while (d--)
            ptr1 = ptr1->next;
    }
    else
    {
        while (d--)
            ptr2 = ptr2->next;
    }

    while (ptr1 && ptr2)
    {
        if (ptr1 == ptr2)
            return ptr1->data;
        ptr1 = ptr1->next;
        ptr2 = ptr2->next;
    }

    return -1;
}

//2-Pointer Technique
Node *intersectPoint1(Node *head1, Node *head2)
{

    Node *ptr1 = head1;
    Node *ptr2 = head2;

    if (ptr1 == NULL || ptr2 == NULL)
    {

        return NULL;
    }

    while (ptr1 != ptr2)
    {

        ptr1 = ptr1->next;
        ptr2 = ptr2->next;

        if (ptr1 == ptr2)
        {
            return ptr1;
        }

        if (ptr1 == NULL)
        {
            ptr1 = head2;
        }

        if (ptr2 == NULL)
        {

            ptr2 = head1;
        }
    }

    return ptr1;
}

//Tricky solution but may not be legit
int intersectPoint(Node *head1, Node *head2)
{
    for (Node *temp = head1; temp; temp = temp->next)
    {
        temp->data += 2000;
    }

    for (Node *temp = head2; temp; temp = temp->next)
    {
        if (temp->data > 1000)
            return temp->data - 2000;
    }

    return -1;
}
