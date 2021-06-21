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

bool check(Node *root, int l, int r)
{
    if (root == NULL)
        return true;

    int value = root->data;

    if (!(value > l && value < r))
        return false;

    return (check(root->left, l, value) && check(root->right, value, r));
}

bool isBST(Node *root)
{
    if (root == NULL)
        return true;

    int l = INT_MIN, r = INT_MAX;
    return (check(root->left, l, root->data) && check(root->right, root->data, r));
}