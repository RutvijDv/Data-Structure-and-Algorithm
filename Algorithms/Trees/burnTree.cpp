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

pair<bool, int> util(Node *root, int target, int &dis)
{

    if (root == NULL)
        return {false, 0};

    pair<bool, int> l = util(root->left, target, dis);
    pair<bool, int> r = util(root->right, target, dis);

    int lh = l.second;
    int rh = r.second;

    if (root->key == target)
    {
        dis = max(dis, max(lh, rh) + 1);

        return {true, 1};
    }

    if (l.first || r.first)
    {
        dis = max(dis, lh + rh + 1);

        if (l.first)
        {
            return {true, 1 + lh};
        }
        else
        {
            return {true, 1 + rh};
        }
    }
    else
    {
        return {false, 1 + max(lh, rh)};
    }
}

int minTime(Node *root, int target)
{
    int dis = -1;
    util(root, target, dis);

    return dis - 1;
}