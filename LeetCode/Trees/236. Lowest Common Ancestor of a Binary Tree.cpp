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

TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
{

    if (!root)
        return NULL;

    if (root == p || root == q)
        return root;

    TreeNode *left = lowestCommonAncestor(root->left, p, q);

    TreeNode *right = lowestCommonAncestor(root->right, p, q);

    if (left != NULL && right != NULL)
        return root;

    if (left)
        return left;
    else
        return right;
}