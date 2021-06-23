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

int util(Node *root, int &res)
{

    if (root == NULL)
        return 0;

    if (root->left == NULL && root->right == NULL)
        return root->data;

    int lh = util(root->left, res);
    int rh = util(root->right, res);

    if (root->left && root->right)
    {

        int out = lh + rh + root->data;

        res = max(res, out);
        return max(lh, rh) + root->data;
    }

    if (root->left)
        return lh + root->data;
    else
        return rh + root->data;
}

int maxPathSum(Node *root)
{
    int res = INT_MIN;

    int val = util(root, res);

    if (res == INT_MIN)
        return val;
    else
        return res;
}