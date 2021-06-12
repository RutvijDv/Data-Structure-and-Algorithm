
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

//O(n) space --> Use Hashing

//(1) space ---> Modify linkedList Data Structures to keep a flag of every node
struct Node
{
    int data;
    struct Node *next;
    int flag;
};

//Floyd's Algorithm (Hare-Rabbit Approach)

bool detectLoop(Node *head)
{
    Node *slow = head;
    Node *fast = head;

    while (fast && fast->next)
    {
        fast = fast->next->next;
        slow = slow->next;
        if (fast == slow)
            return true;
    }

    return false;
}