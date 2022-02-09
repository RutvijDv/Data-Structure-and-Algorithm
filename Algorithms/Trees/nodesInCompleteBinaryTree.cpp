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

// Naive solution
int countNode(Node *root)
{
    if (root == NULL)
        return 0;
    else
        return 1 + countNode(root->left) + countNode(root->right);
}

// Efficient solution
int countNode(Node *root)
{
    int lh = 0, rh = 0;
    Node *curr = root;
    while (curr != NULL)
    {
        lh++;
        curr = curr->left;
    }
    curr = root;
    while (curr != NULL)
    {
        rh++;
        curr = curr->right;
    }
    if (lh == rh)
    {
        return pow(2, lh) - 1;
    }
    else
    {
        return 1 + countNode(root->left) + countNode(root->right);
    }
}
