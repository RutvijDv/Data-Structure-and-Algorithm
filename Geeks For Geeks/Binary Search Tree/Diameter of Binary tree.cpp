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

//Simple ---> use height function and util function both

//Efficient
int util(Node *root, int &res)
{
    if (root == NULL)
        return 0;

    int lh = util(root->left, res);
    int rh = util(root->right, res);

    res = max(res, lh + rh + 1);

    return 1 + max(lh, rh);
}

int diameter(Node *root)
{
    int res = INT_MIN;

    util(root, res);

    return res;
}