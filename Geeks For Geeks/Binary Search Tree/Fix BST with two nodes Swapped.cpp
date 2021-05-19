#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;
};

Node *prevv = NULL, *first = NULL, *second = NULL;

void fixBST(Node *root)
{
    if (root == NULL)
        return;

    fixBST(root->left);

    if (prevv != NULL && root->data < prevv->data)
    {
        if (first == NULL)
        {
            first = prevv;
        }
        second = root;
    }
    prevv = root;
    fixBST(root->right);
}

//It is also based on the fact that inorder traversal is sorted for BST
//Try the same on simple array which has two swapped elements