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

int getMax(TreeNode *root, unordered_map<TreeNode *, int> &mp)
{

    if (!root)
        return 0;

    if (mp[root])
        return mp[root];

    int ansWithNode, ansWithoutNode;

    ansWithNode = root->val;

    if (root->left)
    {
        ansWithNode += getMax(root->left->left, mp) + getMax(root->left->right, mp);
    }

    if (root->right)
    {
        ansWithNode += getMax(root->right->left, mp) + getMax(root->right->right, mp);
    }

    ansWithoutNode = getMax(root->left, mp) + getMax(root->right, mp);

    mp[root] = max(ansWithNode, ansWithoutNode);

    return mp[root];
}

int rob(TreeNode *root)
{

    unordered_map<TreeNode *, int> mp;

    return getMax(root, mp);
}