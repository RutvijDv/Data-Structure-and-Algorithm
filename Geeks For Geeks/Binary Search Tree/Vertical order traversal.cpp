#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;
};

vector<int> verticalOrder(Node *root)
{
    map<int, vector<int>> map;
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

        map[dist].push_back(temp->data);

        if (temp->left)
            q.push({temp->left, dist - 1});
        if (temp->right)
            q.push({temp->right, dist + 1});
    }

    for (auto itr = map.begin(); itr != map.end(); itr++)
    {
        for (auto x : itr->second)
        {
            res.push_back(x);
        }
    }

    return res;
}