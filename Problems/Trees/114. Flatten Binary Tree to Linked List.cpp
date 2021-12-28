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

void flatten(TreeNode *root)
{
    TreeNode *curr = NULL;
    fun(root, curr);
}

void fun(TreeNode *root, TreeNode *&curr)
{
    if (!root)
        return;

    TreeNode *left = root->left;
    TreeNode *right = root->right;

    if (curr)
    {
        curr->right = root;
        curr->left = NULL;
    }
    curr = root;
    fun(left, curr);
    fun(right, curr);
}