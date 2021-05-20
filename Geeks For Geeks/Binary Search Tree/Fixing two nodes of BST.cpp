#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;
};

void util(Node *root, Node *&first, Node *&second, Node *&prev)
{
    if (root == NULL)
        return;

    util(root->left, first, second, prev);
    if (prev != NULL && root->data < prev->data)
    {
        if (first == NULL)
            first = prev;
        second = root;
    }
    prev = root;
    util(root->right, first, second, prev);

    return;
}

void correctBST(struct Node *root)
{
    Node *first = NULL, *second = NULL, *prev = NULL;
    util(root, first, second, prev);

    int temp = first->data;
    first->data = second->data;
    second->data = temp;

    return;
}

//Please Watch video for reference