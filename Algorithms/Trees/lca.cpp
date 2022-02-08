#include <bits/stdc++.h>
using namespace std;

// Tree Node
struct Node
{
    int data;
    Node *left;
    Node *right;
};

// Naive Solution
bool findPath(Node *root, vector<Node *> &p, int n)
{
    if (root == NULL)
        return false;
    p.push_back(root);
    if (root->data == n)
        return true;

    if (findPath(root->left, p, n) || findPath(root->right, p, n))
        return true;

    p.pop_back();
    return false;
}

Node *lca(Node *root, int n1, int n2)
{
    vector<Node *> path1, path2;
    if (findPath(root, path1, n1) == false || findPath(root, path2, n2) == false)
        return NULL;

    int i;
    for (i = 0; i < min(path1.size(), path2.size()); i++)
        if (path1[i + 1] != path2[i + 1])
            return path1[i];
    return path1[i - 1];
}

// Efficient solution
Node *lca(Node *root, int n1, int n2)
{
    if (root == NULL)
        return NULL;
    if (root->data == n1 || root->data == n2)
        return root;

    Node *lca1 = lca(root->left, n1, n2);
    Node *lca2 = lca(root->right, n1, n2);

    if (lca1 != NULL && lca2 != NULL)
        return root;

    if (lca1 != NULL)
        return lca1;
    else
        return lca2;
}