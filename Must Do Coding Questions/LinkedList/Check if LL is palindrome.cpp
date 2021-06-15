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

//Using Stack ---> 2 traversals.

//Iterative ---> Get Middle and reverse the remainig list
bool isPalindrome(Node *head)
{
    Node *slow = head;
    Node *fast = head;

    int count = 0;
    while (fast != NULL && fast->next != NULL)
    {
        count++;
        slow = slow->next;
        fast = fast->next->next;
    }

    Node *prev = NULL;
    Node *curr = slow;
    Node *next = slow;

    while (curr != NULL)
    {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }

    Node *a = prev;
    Node *b = head;

    while (a && b)
    {
        if (a->data != b->data)
            return false;
        a = a->next;
        b = b->next;
    }

    return true;
}
