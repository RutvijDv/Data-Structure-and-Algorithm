#include <bits/stdc++.h>
using namespace std;

struct Node
{
    Node *left;
    Node *right;
    Node *nextRight;
    int data;
    Node(int x)
    {
        data = x;
        left = right = nextRight = NULL;
    }
};

//Using Level Order
void connect(Node *root)
{
    Node *curr = root;
    queue<Node *> q;
    q.push(root);

    while (!q.empty())
    {
        int count = q.size();

        for (int i = 0; i < count; i++)
        {
            curr = q.front();
            q.pop();

            if (i != count - 1)
                curr->nextRight = q.front();
            else
                curr->nextRight = NULL;

            if (curr->left)
                q.push(curr->left);
            if (curr->right)
                q.push(curr->right);
        }
    }
    return;
}