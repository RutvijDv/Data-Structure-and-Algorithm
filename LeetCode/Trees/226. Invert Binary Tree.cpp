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

TreeNode *invertTree(TreeNode *root)
{

    if (root == NULL)
        return NULL;

    TreeNode *l = invertTree(root->right);
    TreeNode *r = invertTree(root->left);

    root->left = l;
    root->right = r;

    return root;
}