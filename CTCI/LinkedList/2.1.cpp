#include <bits/stdc++.h>
using namespace std;

struct Node
{
    Node *next = NULL;
    int data;
};

//O(n) time with O(n) space

Node *removeDuplicates(Node *head)
{
    unordered_set<int> seen;

    Node *curr = head->next;
    Node *prev = head;
    seen.insert(head->data);

    while (curr != NULL)
    {
        if (seen.find(curr->data) != seen.end())
        {
            prev->next = curr->next;
            free(curr);
            curr = prev->next;
        }
        else
        {
            seen.insert(curr->data);
            curr = curr->next;
            prev = prev->next;
        }
    }
    return head;
}

//O(n^2) time with O(1) space ---> use 2 loops