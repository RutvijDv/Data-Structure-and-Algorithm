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

// Recursive Solution
vector<TreeNode *> uniqueTrees(int start, int end)
{
    vector<TreeNode *> res;

    if (start > end)
    {
        res.push_back(NULL);
        return res;
    }

    if (start == end)
    {
        TreeNode *b = new TreeNode(start);
        res.push_back(b);
        return res;
    }

    for (int i = start; i <= end; i++)
    {

        vector<TreeNode *> left = uniqueTrees(start, i - 1);
        vector<TreeNode *> right = uniqueTrees(i + 1, end);

        for (int j = 0; j < left.size(); j++)
        {
            for (int k = 0; k < right.size(); k++)
            {
                TreeNode *a = new TreeNode(i);
                a->left = left[j];
                a->right = right[k];
                res.push_back(a);
            }
        }
    }
    return res;
}

vector<TreeNode *> generateTrees(int n)
{

    vector<TreeNode *> res = uniqueTrees(1, n);

    return res;
}

// DP Solution
vector<TreeNode *> uniqueTrees(int start, int end, vector<vector<vector<TreeNode *>>> &dp)
{

    vector<TreeNode *> res;

    if (start > end)
    {
        res.push_back(NULL);
        dp[start][end] = res;
        return res;
    }

    if (start == end)
    {
        TreeNode *b = new TreeNode(start);
        res.push_back(b);
        dp[start][end] = res;
        return res;
    }

    for (int i = start; i <= end; i++)
    {

        vector<TreeNode *> left;
        vector<TreeNode *> right;

        if (dp[start][i - 1].size() != 0)
        {
            left = dp[start][i - 1];
        }
        else
        {
            left = uniqueTrees(start, i - 1, dp);
        }

        if (dp[i + 1][end].size() != 0)
        {
            right = dp[i + 1][end];
        }
        else
        {
            right = uniqueTrees(i + 1, end, dp);
        }

        for (int j = 0; j < left.size(); j++)
        {
            for (int k = 0; k < right.size(); k++)
            {
                TreeNode *a = new TreeNode(i);
                a->left = left[j];
                a->right = right[k];
                res.push_back(a);
            }
        }
    }

    dp[start][end] = res;
    return res;
}

vector<TreeNode *> generateTrees(int n)
{

    vector<TreeNode *> temp;
    vector<vector<vector<TreeNode *>>> dp(n + 2, vector<vector<TreeNode *>>(n + 2, temp));

    vector<TreeNode *> res = uniqueTrees(1, n, dp);

    return res;
}