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

void solve(TreeNode *root, int targetSum, vector<vector<int>> &res, vector<int> &temp)
{

    if (root == NULL)
        return;

    int val = root->val;

    targetSum -= val;

    temp.push_back(root->val);

    if (targetSum == 0 && !root->left && !root->right)
    {
        res.push_back(temp);
    }

    solve(root->left, targetSum, res, temp);
    solve(root->right, targetSum, res, temp);

    temp.pop_back();

    return;
}

vector<vector<int>> pathSum(TreeNode *root, int targetSum)
{

    vector<vector<int>> res;
    vector<int> temp;

    solve(root, targetSum, res, temp);

    return res;
}