#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;
};

vector<int> merge(Node *root1, Node *root2)
{
    vector<int> res;
    stack<Node *> s1, s2;
    Node *curr = root1;
    Node *surr = root2;

    while (!s1.empty() || curr != NULL || surr != NULL || !s2.empty())
    {

        while (curr != NULL)
        {
            s1.push(curr);
            curr = curr->left;
        }
        while (surr != NULL)
        {
            s2.push(surr);
            surr = surr->left;
        }

        if (s1.empty() || s2.empty())
        {
            if (s2.empty())
            {
                if (!s1.empty())
                {
                    curr = s1.top();
                    s1.pop();
                    res.push_back(curr->data);
                    curr = curr->right;
                }
                // return res;
            }
            if (s1.empty())
            {
                if (!s2.empty())
                {
                    surr = s2.top();
                    s2.pop();
                    res.push_back(surr->data);
                    surr = surr->right;
                }
                // return res;
            }
        }

        else
        {
            curr = s1.top();
            surr = s2.top();

            if (curr->data <= surr->data)
            {
                s1.pop();
                res.push_back(curr->data);
                curr = curr->right;
                surr = NULL;
            }
            else
            {
                s2.pop();
                res.push_back(surr->data);
                surr = surr->right;
                curr = NULL;
            }
        }
    }
    return res;
}