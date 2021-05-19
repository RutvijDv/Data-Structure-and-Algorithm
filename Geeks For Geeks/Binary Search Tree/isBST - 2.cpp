#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;
};

int prevv = INT_MIN;
bool isBST(Node *root)
{
    if (root == NULL)
        return true;

    if (!isBST(root->left))
        return false;

    if (root->data <= prevv)
        return false;
    prevv = root->data;

    return isBST(root->right);
}
