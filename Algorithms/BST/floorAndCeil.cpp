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

// Floor
Node *floor(Node *root, int x)
{
    Node *res = NULL;
    while (root != NULL)
    {
        if (root->key == x)
            return root;
        else if (root->key > x)
            root = root->left;
        else
        {
            res = root;
            root = root->right;
        }
    }
    return res;
}

// Ceil
Node *ceil(Node *root, int x)
{
    Node *res = NULL;
    while (root != NULL)
    {
        if (root->key == x)
            return root;
        else if (root->key < x)
            root = root->right;
        else
        {
            res = root;
            root = root->left;
        }
    }
    return res;
}
