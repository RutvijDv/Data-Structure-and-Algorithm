#include <bits/stdc++.h>
using namespace std;

struct Node
{
    Node *next = NULL;
    int data;
};

void deleteNode(Node *root)
{
    root->data = root->next->data;

    root->next = root->next->next;

    return;
}
