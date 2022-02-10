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

void inorder(Node *root)
{
    if (root != NULL)
    {
        inorder(root->left);
        cout << root->key << " ";
        inorder(root->right);
    }
}

Node *prevv = NULL, *first = NULL, *second = NULL;
void fixBST(Node *root)
{
    if (root == NULL)
        return;
    fixBST(root->left);
    if (prevv != NULL && root->key < prevv->key)
    {
        if (first == NULL)
            first = prevv;
        second = root;
    }
    prevv = root;

    fixBST(root->right);
}