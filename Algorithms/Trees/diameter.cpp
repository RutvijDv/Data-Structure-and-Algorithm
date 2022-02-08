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
int height(Node *root)
{
    if (root == NULL)
        return 0;
    else
        return (1 + max(height(root->left), height(root->right)));
}

int diameter(Node *root)
{
    if (root == NULL)
        return 0;
    int d1 = 1 + height(root->left) + height(root->right);
    int d2 = diameter(root->left);
    int d3 = diameter(root->right);

    return max(d1, max(d2, d3));
}

// ----------------------------------------------------------------

// Efficient solution
int util(struct Node *root, int &maxDia)
{

    if (root == NULL)
        return 0;

    int hl = util(root->left, maxDia);
    int hr = util(root->right, maxDia);

    maxDia = max(maxDia, 1 + hl + hr);

    return 1 + max(hl, hr);
}

int diameter(struct Node *root)
{
    int maxDia = 0;
    util(root, maxDia);

    return maxDia;
}