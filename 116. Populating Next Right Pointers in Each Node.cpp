#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
    TreeNode *left;
    TreeNode *right;
    TreeNode *next;
    int val;
    TreeNode(int x)
    {
        val = x;
        left = right = next = NULL;
    }
};

TreeNode *connect(TreeNode *root)
{

    queue<TreeNode *> q;

    if (root)
        q.push(root);

    while (!q.empty())
    {

        int l = q.size();
        TreeNode *prev = NULL;

        for (int i = 0; i < l; i++)
        {

            TreeNode *curr = q.front();
            q.pop();

            if (prev)
            {
                prev->next = curr;
            }
            prev = curr;

            if (curr->left)
                q.push(curr->left);
            if (curr->right)
                q.push(curr->right);
        }
    }

    return root;
}