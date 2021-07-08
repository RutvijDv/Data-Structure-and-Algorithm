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

//Simple
void preorder(Node *root, vector<int> &res)
{
    if (root == NULL)
    {
        res.push_back(-1);
        return;
    }

    res.push_back(root->data);
    preorder(root->left, res);
    preorder(root->right, res);

    return;
}

bool solve(vector<int> t, vector<int> s)
{
    int i = 0, j = 0;

    while (i < t.size() && j < s.size())
    {

        if (t[i] == s[j])
        {
            j++;
        }
        else
        {
            j = 0;
        }
        i++;
    }

    if (j == s.size())
        return true;
    else
        return false;
}

bool isSubTree(Node *T, Node *S)
{
    vector<int> t;
    vector<int> s;

    preorder(T, t);
    preorder(S, s);

    return solve(t, s);
}

//Alternative
bool check(Node *a, Node *b)
{
    if (a == NULL && b == NULL)
        return true;

    if (a == NULL || b == NULL)
        return false;

    if (a->data == b->data)
        return (check(a->left, b->left) && check(a->right, b->right));
    else
        return false;
}

bool solve(Node *root, Node *s)
{
    if (root == NULL)
        return false;

    if (root->data == s->data)
    {
        if (check(root, s))
            return true;
    }
    if (solve(root->left, s))
        return true;
    if (solve(root->right, s))
        return true;

    return false;
}

bool isSubTree(Node *T, Node *S)
{
    return solve(T, S);
}

//Alrternative
//match preorder and inorder of both