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

//Simple Stroing data of inorder traversal od both trees and comparing

//Level Order Traversal

//Recursive
bool isIdentical(Node *r1, Node *r2)
{
    if (r1 == NULL && r2 == NULL)
        return true;

    if (r1 == NULL || r2 == NULL)
        return false;

    if ((r1->data) != (r2->data))
        return false;

    return (isIdentical(r1->left, r2->left) && isIdentical(r1->right, r2->right));
}