#include <bits/stdc++.h>
using namespace std;

//Brute Force Solution -> Start with every node and search the sum

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

void solve(Node *root, int k, int &res, unordered_map<int, int> &map, int last)
{
    if (root == NULL)
        return;

    int curr = root->data + last;
    if (map[curr - k] > 0)
        res += map[curr - k];

    map[curr]++;
    last = curr;
    solve(root->left, k, res, map, last);
    solve(root->right, k, res, map, last);

    map[curr]--;

    return;
}

int paths(Node *root, int k)
{
    int res = 0;
    unordered_map<int, int> mp;
    mp[0] = 1;
    solve(root, k, res, mp, 0);
    return res;
}
int main()
{
    Node *root = new Node(1);
    root->left = new Node(2);
    root->left->left = new Node(1);
    root->left->right = new Node(2);
    root->right = new Node(-1);
    root->right->left = new Node(3);
    root->right->left->left = new Node(2);
    root->right->left->right = new Node(5);

    int k = 3;
    cout << "No of paths with sum equals to " << k
         << " are : " << paths(root, k) << "\n";

    return 0;
}
