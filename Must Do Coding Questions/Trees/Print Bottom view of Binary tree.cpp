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

//Using Level Order
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

        map[dist] = temp->data;

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

//Using PreOrder Recursion with HashMap
void preOrder(Node *root, int hd, int level, map<int, pair<int, int>> &map)
{
    if (root == NULL)
        return;

    if (map.find(hd) != map.end())
    {

        if (map[hd].second <= level)
        {
            map[hd].first = root->data;
            map[hd].second = level;
        }
    }
    else
    {
        map[hd] = {root->data, level};
    }

    preOrder(root->left, hd - 1, level + 1, map);
    preOrder(root->right, hd + 1, level + 1, map);

    return;
}

vector<int> bottomView(Node *root)
{
    map<int, pair<int, int>> map;
    vector<int> res;

    preOrder(root, 0, 0, map);

    for (auto itr = map.begin(); itr != map.end(); itr++)
    {
        pair<int, int> p = itr->second;
        res.push_back(p.first);
    }

    return res;
}
