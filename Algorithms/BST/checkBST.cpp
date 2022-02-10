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

// Naive
int maxValue(Node *root)
{
    if (root == NULL)
        return INT_MIN;

    int res = root->key;
    int lres = maxValue(root->left);
    int rres = maxValue(root->right);
    if (lres > res)
        res = lres;
    if (rres > res)
        res = rres;
    return res;
}

int minValue(Node *root)
{
    if (root == NULL)
        return INT_MAX;

    int res = root->key;
    int lres = minValue(root->left);
    int rres = minValue(root->right);
    if (lres < res)
        res = lres;
    if (rres < res)
        res = rres;
    return res;
}
int isBST(Node *root)
{
    if (root == NULL)
        return 1;

    if (root->left != NULL && maxValue(root->left) > root->key)
        return 0;

    if (root->right != NULL && minValue(root->right) < root->key)
        return 0;

    if (!isBST(root->left) || !isBST(root->right))
        return 0;

    return 1;
}

// Efficient 1
bool isBST1(Node *root, int min, int max)
{
    if (root == NULL)
        return true;

    return (root->key > min && root->key < max &&
            isBST1(root->left, min, root->key) && isBST1(root->right, root->key, max));
}

// Efficient 2
int prevv = INT_MIN;
bool isBST2(Node *root)
{
    if (root == NULL)
        return true;

    if (isBST2(root->left) == false)
        return false;

    if (root->key <= prevv)
        return false;
    prevv = root->key;

    return isBST2(root->right);
}