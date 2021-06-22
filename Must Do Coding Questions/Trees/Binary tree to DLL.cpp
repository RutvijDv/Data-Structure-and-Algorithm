#include <bits/stdc++.h>
using namespace std;

struct Node
{
    Node *left;
    Node *right;
    int data;
    Node(int x)
    {
        data = x;
        left = right = NULL;
    }
};

class Solution
{
public:
    Node *prev = NULL;

    Node *bToDLL(Node *root)
    {
        if (root == NULL)
            return NULL;

        Node *head = bToDLL(root->left);

        if (prev == NULL)
        {
            head = root;
            prev = head;
        }
        else
        {
            prev->right = root;
            root->left = prev;

            prev = root;
        }

        bToDLL(root->right);

        return head;
    }
};