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

void utilSerial(Node *root, vector<int> &res)
{

    if (root == NULL)
    {
        res.push_back(-1);
        return;
    }

    res.push_back(root->data);
    utilSerial(root->left, res);
    utilSerial(root->right, res);
    return;
}

vector<int> serialize(Node *root)
{
    vector<int> res;
    utilSerial(root, res);
    return res;
}

Node *utilDeserial(vector<int> &a, int &i)
{

    if (a[i] == -1)
        return NULL;

    Node *root = new Node(a[i]);

    i++;
    root->left = utilDeserial(a, i);
    i++;
    root->right = utilDeserial(a, i);

    return root;
}

Node *deSerialize(vector<int> &a)
{
    int i = 0;
    Node *root = utilDeserial(a, i);

    return root;
}