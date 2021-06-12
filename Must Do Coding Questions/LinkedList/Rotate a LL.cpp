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

Node *rotate(Node *head, int k)
{
    Node *temp = head;
    Node *prev;

    while (k--)
    {
        prev = temp;
        temp = temp->next;
    }
    if (temp == NULL)
        return head;

    prev->next = NULL;
    Node *curr = temp;

    while (curr->next != NULL)
        curr = curr->next;

    curr->next = head;

    return temp;
}
