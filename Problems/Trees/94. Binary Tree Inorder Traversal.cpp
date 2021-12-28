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

void traversal(TreeNode *root, vector<int> &res)
{

    if (root == NULL)
        return;

    traversal(root->left, res);
    res.push_back(root->val);
    traversal(root->right, res);

    return;
}

vector<int> inorderTraversal(TreeNode *root)
{

    vector<int> res;

    traversal(root, res);

    return res;
}