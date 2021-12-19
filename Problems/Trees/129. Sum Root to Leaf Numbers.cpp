#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
    TreeNode *left;
    TreeNode *right;
    int val;
    TreeNode(int x)
    {
        val = x;
        left = right = NULL;
    }
};

void solve(TreeNode *root, int &res, long long &temp)
{

    if (!root)
        return;

    int mul = 10;

    temp = temp * mul;
    temp += root->val;

    if (!root->left && !root->right)
    {
        res += temp;
    }

    solve(root->left, res, temp);
    solve(root->right, res, temp);

    temp = temp - root->val;
    temp = temp / 10;

    return;
}

int sumNumbers(TreeNode *root)
{

    int res = 0;
    long long temp = 0;

    solve(root, res, temp);

    return res;
}