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

//Use level order traversal line by line

//Efficient
bool check(Node *n1, Node *n2)
{

    if (n1 == NULL && n2 == NULL)
        return true;
    if (n1 == NULL || n2 == NULL)
        return false;

    if (n1->data != n2->data)
        return false;

    return (check(n1->left, n2->right) && check(n1->right, n2->left));
}

bool isSymmetric(struct Node *root)
{
    if (root == NULL)
        return true;
    return check(root->left, root->right);
}