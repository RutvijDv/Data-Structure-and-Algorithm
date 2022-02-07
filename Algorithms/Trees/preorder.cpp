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

// Recursive
void preorder(Node *root)
{
    if (root != NULL)
    {
        cout << root->key << " ";
        preorder(root->left);
        preorder(root->right);
    }
}

// Iterative
void preorderIterative(Node *root)
{
    if (root == NULL)
        return;

    stack<Node *> st;

    Node *curr = root;

    while (!st.empty() || curr != NULL)
    {
        while (curr != NULL)
        {
            cout << curr->data << " ";

            st.push(curr);
            curr = curr->left;
        }

        curr = st.top();
        st.pop();

        curr = curr->right;
    }
}
