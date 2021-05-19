#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;
};

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