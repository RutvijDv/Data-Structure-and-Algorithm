#include <bits/stdc++.h>
using namespace std;

struct Node
{
    Node *next = NULL;
    int data;
};

//Using swap of elements
//Note --> this doesnt preserve the order of elements, for that to be done you require to creat 2 new LinkedList and finally merge them

void swap(Node *a, Node *b)
{
    int temp = a->data;

    a->data = b->data;
    b->data = temp;

    return;
}

Node *partition(Node *root, int x)
{

    Node *less = root;
    Node *runner = root;

    while (runner != NULL)
    {
        if (runner->data < x)
        {
            swap(less, runner);
            less = less->next;
        }
        runner = runner->next;
    }

    return root;
}

//Without using swaps

Node *partition(Node *root, int x)
{

    Node *tail = root;
    Node *curr = root;

    while (curr != NULL)
    {
        Node *next = curr->next;
        if (curr->data < x)
        {
            curr->next = root;
            root = curr;
        }
        else
        {
            tail->next = curr;
            tail = curr;
        }
        curr = next;
    }
    tail->next = NULL;

    return root;
}