#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;
};

bool util(Node *root, int maxi, int mini)
{
    if (root == NULL)
        return true;

    if (root->data >= maxi || root->data <= mini)
        return false;

    return util(root->left, root->data, mini) && util(root->right, maxi, root->data);
}

bool isBST(Node *root)
{
    return util(root, INT_MAX, INT_MIN);
}