#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int key;
    struct Node *left;
    struct Node *right;
    Node(int k)
    {
        key = k;
        left = right = NULL;
    }
};

// Top View
vector<int> topView(Node *root)
{
    map<int, int> map;
    vector<int> res;

    queue<pair<Node *, int>> q;
    pair<Node *, int> p;
    q.push({root, 0});

    while (!q.empty())
    {

        p = q.front();
        q.pop();
        Node *temp = p.first;
        int dist = p.second;

        if (!map[dist])
            map[dist] = temp->key;

        if (temp->left)
            q.push({temp->left, dist - 1});
        if (temp->right)
            q.push({temp->right, dist + 1});
    }

    for (auto itr = map.begin(); itr != map.end(); itr++)
    {
        res.push_back(itr->second);
    }

    return res;
}

// Left View
void leftViewUtil(Node *root, int level, int *max_level)
{
    // Base Case
    if (root == NULL)
        return;

    if (*max_level < level)
    {
        cout << root->key << " ";
        *max_level = level;
    }

    leftViewUtil(root->left, level + 1, max_level);
    leftViewUtil(root->right, level + 1, max_level);
}

// Right View
void rightViewUtil(struct Node *root,
                   int level, int *max_level)
{
    // Base Case
    if (root == NULL)
        return;

    // If this is the last Node of its level
    if (*max_level < level)
    {
        cout << root->key << "\t";
        *max_level = level;
    }

    // Recur for right subtree first,
    // then left subtree
    rightViewUtil(root->right, level + 1, max_level);
    rightViewUtil(root->left, level + 1, max_level);
}

// Bottom View
vector<int> bottomView(Node *root)
{
    map<int, int> map;
    vector<int> res;

    queue<pair<Node *, int>> q;
    pair<Node *, int> p;
    q.push({root, 0});

    while (!q.empty())
    {

        p = q.front();
        q.pop();
        Node *temp = p.first;
        int dist = p.second;

        map[dist] = temp->key;

        if (temp->left)
            q.push({temp->left, dist - 1});
        if (temp->right)
            q.push({temp->right, dist + 1});
    }

    for (auto itr = map.begin(); itr != map.end(); itr++)
    {
        res.push_back(itr->second);
    }

    return res;
}