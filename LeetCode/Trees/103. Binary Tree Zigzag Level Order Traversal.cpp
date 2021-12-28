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

vector<vector<int>> zigzagLevelOrder(TreeNode *root)
{

    stack<TreeNode *> s1, s2;
    TreeNode *curr = root;

    vector<vector<int>> res;

    if (curr)
        s1.push(curr);

    bool flag = false;

    while (!s1.empty())
    {

        int x = s1.size();
        vector<int> temp;

        while (x--)
        {

            curr = s1.top();
            s1.pop();
            temp.push_back(curr->val);

            if (flag)
            {
                if (curr->right)
                    s2.push(curr->right);
                if (curr->left)
                    s2.push(curr->left);
            }
            else
            {
                if (curr->left)
                    s2.push(curr->left);
                if (curr->right)
                    s2.push(curr->right);
            }
        }

        s1.swap(s2);
        flag = !flag;

        res.push_back(temp);
    }

    return res;
}