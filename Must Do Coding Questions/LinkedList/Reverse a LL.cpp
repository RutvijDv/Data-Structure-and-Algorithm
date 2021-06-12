#include <bits/stdc++.h>
using namespace std;

//O(1) space O(n) time using iteration

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

struct Node *reverseList(struct Node *head)
{
    if (head == NULL || head->next == NULL)
        return head;

    Node *prev = NULL;
    Node *curr = head;
    Node *next = head;

    while (curr != NULL)
    {

        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }

    return prev;
}

//Recusive O(n) time O(n) space

struct Node *reverseList(struct Node *head)
{
    if (head == NULL || head->next == NULL)
        return head;

    Node *rest = reverseList(head->next);
    head->next->next = head;

    head->next = NULL;

    return rest;
}

//Using Stack
struct Node *reverseList(struct Node *head)
{
    stack<Node *> st;

    Node *temp = head;

    while (temp->next != NULL)
    {
        st.push(temp);
        temp = temp->next;
    }

    head = temp;

    while (!st.empty())
    {
        temp->next = st.top();
        st.pop();
        temp = temp->next;
    }
    temp->next = NULL;

    return head;
}