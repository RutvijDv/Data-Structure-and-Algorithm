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

//Using Level Order travrsal
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
        for (int i = 0; i < itr->second.size(); i++)
        {
            res.push_back(itr->second[i]);
        }
    }

    return res;
}
