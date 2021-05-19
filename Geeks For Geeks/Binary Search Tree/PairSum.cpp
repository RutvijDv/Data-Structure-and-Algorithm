#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;
};

bool util(Node *root, unordered_map<int, bool> &map, int X)
{

    if (root == NULL)
        return false;

    if (map[X - root->data] == true)
        return true;
    else
    {
        map[root->data] = true;
        return (util(root->left, map, X) || util(root->right, map, X));
    }
}

bool findPair(Node *root, int X)
{
    unordered_map<int, bool> map;
    bool ans = util(root, map, X);

    return ans;
}