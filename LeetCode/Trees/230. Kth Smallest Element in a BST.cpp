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

int count(TreeNode *root)
{

    if (!root)
        return 0;

    return 1 + count(root->left) + count(root->right);
}

int kthSmallest(TreeNode *root, int k)
{

    if (!root)
        return 0;

    int lCount = count(root->left);

    if (lCount >= k)
        return kthSmallest(root->left, k);

    if (lCount + 1 == k)
        return root->val;

    if (lCount + 1 < k)
        return kthSmallest(root->right, k - (lCount + 1));

    return 0;
}

// Optimised

int count(TreeNode *root, int k, int &response)
{

    if (!root)
        return 0;

    int lCount = count(root->left, k, response);

    if (lCount + 1 == k)
    {
        response = root->val;
    }

    int rCount = count(root->right, k - 1 - lCount, response);

    return 1 + lCount + rCount;
}

int kthSmallest(TreeNode *root, int k)
{

    if (!root)
        return 0;

    int response = INT_MIN;

    count(root, k, response);

    return response;
}