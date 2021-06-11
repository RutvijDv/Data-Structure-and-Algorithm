#include <bits/stdc++.h>
using namespace std;

struct Node
{
    Node *next = NULL;
    int data;
};

Node *sum(Node *a, Node *b)
{
    Node *res = new Node;
    res->data = 0;

    Node *resrun = res;
    int carry = 0;
    int sum = 0;

    while (a != NULL || b != NULL)
    {
        sum += carry;
        if (a != NULL)
        {
            sum += a->data;
            a = a->next;
        }
        if (b != NULL)
        {
            sum += b->data;
            b = b->next;
        }

        carry = sum / 10;
        sum = sum % 10;

        Node *x = new Node;
        x->data = sum;

        resrun->next = x;
    }

    if (carry > 0)
    {
        Node *x = new Node;
        x->data = carry;

        resrun->next = x;
    }

    return res->next;
}