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

TreeNode *solve(vector<int> &postorder, vector<int> &inorder, int &idx, int l, int r, unordered_map<int, int> &mp)
{

    int inorderIdx = mp[postorder[idx]];
    TreeNode *currNode = new TreeNode(postorder[idx]);

    if (inorderIdx < r)
    {
        idx--;
        currNode->right = solve(postorder, inorder, idx, inorderIdx + 1, r, mp);
    }

    if (inorderIdx > l)
    {
        idx--;
        currNode->left = solve(postorder, inorder, idx, l, inorderIdx - 1, mp);
    }

    return currNode;
}

TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder)
{

    unordered_map<int, int> mp;

    for (int i = 0; i < inorder.size(); i++)
    {
        mp[inorder[i]] = i;
    }

    int idx = postorder.size() - 1;

    TreeNode *res = solve(postorder, inorder, idx, 0, inorder.size() - 1, mp);

    return res;
}