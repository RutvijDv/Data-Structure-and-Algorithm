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

TreeNode *solve(vector<int> &preorder, vector<int> &inorder, int &idx, int l, int r, unordered_map<int, int> &mp)
{

    int inorderIdx = mp[preorder[idx]];
    TreeNode *currNode = new TreeNode(preorder[idx]);

    if (inorderIdx > l)
    {
        idx++;
        currNode->left = solve(preorder, inorder, idx, l, inorderIdx - 1, mp);
    }

    if (inorderIdx < r)
    {
        idx++;
        currNode->right = solve(preorder, inorder, idx, inorderIdx + 1, r, mp);
    }

    return currNode;
}

TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder)
{

    unordered_map<int, int> mp;

    for (int i = 0; i < inorder.size(); i++)
    {
        mp[inorder[i]] = i;
    }

    int idx = 0;

    TreeNode *res = solve(preorder, inorder, idx, 0, inorder.size() - 1, mp);

    return res;
}