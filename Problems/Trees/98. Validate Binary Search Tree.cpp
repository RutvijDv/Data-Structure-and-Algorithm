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

bool solve(TreeNode *root, long long min, long long max)
{

    if (root == NULL)
        return true;

    bool check = (root->val > min && root->val < max);

    return (solve(root->left, min, root->val) && solve(root->right, root->val, max) && check);
}

bool isValidBST(TreeNode *root)
{

    bool res = solve(root, INT_MIN - 1ll, INT_MAX + 1ll);

    return res;
}