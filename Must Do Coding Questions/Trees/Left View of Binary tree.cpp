#include <bits/stdc++.h>
using namespace std;

struct Node
{
    Node *left;
    Node *right;
    int data;
    Node(int x)
    {
        data = x;
        left = right = NULL;
    }
};

//Using PreOrder
void preOrder(Node *root, vector<int> &res, int level)
{
    if (root == NULL)
        return;

    if (res.size() < level)
        res.push_back(root->data);

    preOrder(root->left, res, level + 1);
    preOrder(root->right, res, level + 1);

    return;
}

vector<int> leftView(Node *root)
{
    vector<int> res;
    int level = 1;

    preOrder(root, res, level);

    return res;
}

//Using LevelOrder
vector<int> leftView(Node *root)
{
    vector<int> res;
    queue<Node *> q;

    if (root == NULL)
        return res;

    q.push(root);

    while (!q.empty())
    {
        int s = q.size();
        for (int i = 0; i < s; i++)
        {
            Node *temp = q.front();
            q.pop();

            if (i == 0)
                res.push_back(temp->data);

            if (temp->left)
                q.push(temp->left);
            if (temp->right)
                q.push(temp->right);
        }
    }

    return res;
}