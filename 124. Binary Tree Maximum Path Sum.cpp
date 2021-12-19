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

int solve(TreeNode *root, int &maxSum)
{

    if (!root)
        return 0;

    int left = max(0, solve(root->left, maxSum));
    int right = max(0, solve(root->right, maxSum));

    maxSum = max(maxSum, left + right + root->val);

    return root->val + max(left, right);
}

int maxPathSum(TreeNode *root)
{

    int maxSum = INT_MIN;

    solve(root, maxSum);

    return maxSum;
}