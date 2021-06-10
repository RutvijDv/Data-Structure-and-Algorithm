#include <bits/stdc++.h>
using namespace std;

struct Node
{
    Node *next = NULL;
    int data;
};

//Iterative

int getNthFromLast(Node *head, int n)
{
    Node *slow = head;
    Node *fast = head;

    while (fast != NULL && n--)
    {
        fast = fast->next;
    }

    if (n > 0)
        return -1;

    while (fast != NULL)
    {
        fast = fast->next;
        slow = slow->next;
    }

    return slow->data;
}

//Recursive

int solve(Node *root, int &res, int &n)
{
    if (root == NULL)
    {
        return 0;
    }

    int count = solve(root->next, res, n) + 1;

    if (count == n)
        res = root->data;

    return count;
}

int getNthFromLast(Node *head, int n)
{
    int res = -1;
    solve(head, res, n);

    return res;
}