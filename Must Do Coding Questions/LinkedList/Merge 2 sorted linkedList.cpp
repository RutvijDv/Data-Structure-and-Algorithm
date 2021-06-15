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

//Iterative O(n) time O(1) space
Node *mergeTwoLists(Node *l1, Node *l2)
{
    Node *head, *ptr;
    if (l1 == NULL)
        return l2;
    if (l2 == NULL)
        return l1;

    if (l1->data <= l2->data)
    {
        head = ptr = l1;
        l1 = l1->next;
    }
    else
    {
        head = ptr = l2;
        l2 = l2->next;
    }

    while (l1 != NULL && l2 != NULL)
    {
        if (l1->data <= l2->data)
        {
            ptr->next = l1;
            ptr = ptr->next;
            l1 = l1->next;
        }
        else
        {
            ptr->next = l2;
            ptr = ptr->next;
            l2 = l2->next;
        }
    }

    if (l1 != NULL)
        ptr->next = l1;
    if (l2 != NULL)
        ptr->next = l2;

    return head;
}

//Recursive Solution O(n) time and O(n) space
Node *sortedMerge(Node *a, Node *b)
{
    if (a == NULL)
        return b;
    if (b == NULL)
        return a;

    Node *res;

    if (a->data < b->data)
    {
        res = a;
        res->next = sortedMerge(a->next, b);
    }
    else
    {
        res = b;
        res->next = sortedMerge(a, b->next);
    }

    return res;
}