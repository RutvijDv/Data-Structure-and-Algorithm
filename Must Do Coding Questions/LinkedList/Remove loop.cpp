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

//Simple
void removeLoop(Node *loopNode, Node *head)
{
    Node *ptr1 = loopNode;
    Node *ptr2 = loopNode;

    int k = 1;

    while (ptr1->next != ptr2)
    {
        ptr1 = ptr1->next;
        k++;
    }

    ptr1 = head;
    ptr2 = head;

    while (k--)
        ptr1 = ptr1->next;

    while (ptr1 != ptr2)
    {
        ptr1 = ptr1->next;
        ptr2 = ptr2->next;
    }

    while (ptr1->next != ptr2)
        ptr1 = ptr1->next;

    ptr1->next = NULL;

    return;
}

void removeLoop(Node *head)
{
    Node *slow = head;
    Node *fast = head;

    while (fast && fast->next)
    {
        fast = fast->next->next;
        slow = slow->next;
        if (fast == slow)
            break;
    }
    if (fast != slow)
        return;

    removeLoop(slow, head);
    return;
}

//Using Floyd's Algorithm again
void removeLoop(Node *head)
{
    Node *slow = head;
    Node *fast = head;

    while (fast && fast->next)
    {
        fast = fast->next->next;
        slow = slow->next;
        if (fast == slow)
            break;
    }
    //If no loops exist
    if (fast != slow)
        return;

    fast = head;

    //in cases like  1->2->3->4->5->loop  fast and slow both are at head
    if (fast == slow)
    {
        while (slow->next != fast)
        {
            slow = slow->next;
        }
    }
    else
    {
        while (slow->next != fast->next)
        {
            fast = fast->next;
            slow = slow->next;
        }
    }

    slow->next = NULL;
    return;
}