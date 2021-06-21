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

vector<int> findSpiral(Node *root)
{
    vector<int> v;

    if (root == NULL)
        return v;

    stack<Node *> s1, s2;

    s1.push(root);

    bool flag = false;

    while (!s1.empty())
    {

        int s = s1.size();

        for (int i = 0; i < s; i++)
        {

            Node *temp = s1.top();
            s1.pop();
            v.push_back(temp->data);

            if (flag)
            {
                if (temp->left)
                    s2.push(temp->left);
                if (temp->right)
                    s2.push(temp->right);
            }
            else
            {
                if (temp->right)
                    s2.push(temp->right);
                if (temp->left)
                    s2.push(temp->left);
            }
        }

        s1.swap(s2);
        flag = !flag;
    }

    return v;
}