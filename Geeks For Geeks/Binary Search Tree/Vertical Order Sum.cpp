#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;
};

void util(Node *root, map<int, int> &mapp, int hd)
{
    if (root == NULL)
        return;

    util(root->left, mapp, hd - 1);
    mapp[hd] += root->data;
    util(root->right, mapp, hd + 1);

    return;
}

vector<int> verticalOrder(Node *root)
{
    map<int, int> mapp;
    vector<int> res;

    util(root, mapp, 0);

    for (auto x : mapp)
    {
        res.push_back(x.second);
    }

    return res;
}