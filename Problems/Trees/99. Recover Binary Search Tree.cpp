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

void solve(TreeNode *root, TreeNode *&first, TreeNode *&middle, TreeNode *&last, TreeNode *&prev)
{

    if (!root)
        return;

    solve(root->left, first, middle, last, prev);

    if (root->val < prev->val)
    {
        if (first != NULL)
        {
            last = root;
        }
        else
        {
            first = prev;
            middle = root;
        }
    }
    prev = root;

    solve(root->right, first, middle, last, prev);

    return;
}

void recoverTree(TreeNode *root)
{

    TreeNode *first = NULL, *middle = NULL, *last = NULL;
    TreeNode *prev = new TreeNode(INT_MIN);

    solve(root, first, middle, last, prev);

    if (last != NULL)
    {
        int temp = first->val;
        first->val = last->val;
        last->val = temp;
    }
    else
    {
        int temp = first->val;
        first->val = middle->val;
        middle->val = temp;
    }

    return;
}