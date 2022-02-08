#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int key;
    struct Node *left;
    struct Node *right;
    Node(int k)
    {
        key = k;
        left = right = NULL;
    }
};

// Singly Linked List
class Solution1
{
    Node *prev = NULL;
    void flatten(Node *root)
    {
        if (root == NULL)
            return;
        cout << root->key << endl;

        Node *l = root->left;
        Node *r = root->right;

        if (prev == NULL)
        {
            prev = root;
        }
        else
        {
            prev->right = root;
            prev->left = NULL;
            prev = root;
        }

        flatten(l);

        flatten(r);

        return;
    }
};

// Doubly Linked List
class Solution2
{
    Node *prev = NULL;
    Node *bToDLL(Node *root, Node *prev = NULL)
    {
        if (root == NULL)
            return NULL;

        Node *head = bToDLL(root->left);

        if (prev == NULL)
            head = root;
        else
        {
            root->left = prev;
            prev->right = root;
        }

        prev = root;
        bToDLL(root->right);

        return head;
    }
};