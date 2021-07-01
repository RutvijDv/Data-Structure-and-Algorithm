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

//Simple ---> get both the numbers by traversing both LinkedList and create a new one

//Better --->traversing and creating both at time
Node *sum(Node *a, Node *b)
{
    Node *res = new Node(0);

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

        Node *x = new Node(sum);

        resrun->next = x;
    }

    if (carry > 0)
    {
        Node *x = new Node(carry);

        resrun->next = x;
    }

    return res->next;
}