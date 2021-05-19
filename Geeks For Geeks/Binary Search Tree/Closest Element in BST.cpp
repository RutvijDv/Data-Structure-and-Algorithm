#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;
};

int minDiff(Node *root, int K)
{
    if (root == NULL)
        return INT_MAX;

    if (root->data == K)
        return 0;

    if (K < root->data)
    {
        return min(abs(K - root->data), minDiff(root->left, K));
    }
    else
    {
        return min(abs(K - root->data), minDiff(root->right, K));
    }
};