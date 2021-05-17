#include <bits/stdc++.h>

using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;

    Node(int val)
    {
        data = val;
        left = right = NULL;
    }
};

Node *getsucc(Node *curr)
{
    curr = curr->right;
    while (curr != NULL && curr->left != NULL)
        curr = curr->left;
    return curr;
}

Node *deleteNode(Node *root, int X)
{
    if (root == NULL)
        return root;

    if (root->data == X)
    {
        if (root->left == NULL)
        {
            Node *temp = root->right;
            delete root;
            return temp;
        }
        else if (root->right == NULL)
        {
            Node *temp = root->left;
            delete root;
            return temp;
        }
        else
        {
            Node *succ = getsucc(root);
            root->data = succ->data;
            root->right = deleteNode(root->right, succ->data);
            return root;
        }
    }

    if (root->data < X)
    {
        root->right = deleteNode(root->right, X);
        return root;
    }

    if (root->data > X)
    {
        root->left = deleteNode(root->left, X);
        return root;
    }
}
