#include <bits/stdc++.h>
using namespace std;

struct node
{
    node *next = NULL;
    int data;
    node(int x)
    {
        data = x;
        next = NULL;
    }
};

//Recursive Solution

struct node *reverse(struct node *head, int k)
{
    if (head == NULL)
        return NULL;

    node *prev = NULL;
    node *curr = head;
    node *next = head;
    int count = k;

    while (count-- && curr != NULL)
    {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }

    head->next = reverse(curr, k);

    return prev;
}

//Stack based Solution

struct node *reverse(struct node *head, int k)
{
    stack<node *> st;

    node *curr = head;
    node *prev = NULL;
    node *next;

    while (curr != NULL)
    {

        int count = k;
        while (count-- && curr != NULL)
        {
            st.push(curr);
            curr = curr->next;
        }

        while (!st.empty())
        {

            if (prev == NULL)
            {
                prev = st.top();
                head = prev;
                st.pop();
            }
            else
            {
                prev->next = st.top();
                prev = prev->next;
                st.pop();
            }
        }
    }
    prev->next = NULL;

    return head;
}