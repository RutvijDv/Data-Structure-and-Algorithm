#include <bits/stdc++.h>
using namespace std;

//Simple -> store inorder traversal of tree in tree class and return random number from that array when required

//Space optimised
struct Node
{
    Node *left;
    Node *right;
    int data;
    int child;
    Node(int x)
    {
        data = x;
        child = 0;
        left = right = NULL;
    }
};

class tree
{
private:
    vector<int> traversal;
    Node *root = NULL;
    int n = 0;

public:
    void insert(int x)
    {
        if (root == NULL)
        {
            root = new Node(x);
            n++;
            return;
        }

        Node *curr = root;

        while (true)
        {
            if (x < curr->data)
            {
                curr->child++;
                if (curr->left == NULL)
                {
                    Node *a = new Node(x);
                    curr->left = a;
                    n++;
                    return;
                }
                curr = curr->left;
            }
            else
            {
                curr->child++;
                if (curr->right == NULL)
                {
                    Node *a = new Node(x);
                    curr->right = a;
                    n++;
                    return;
                }
                curr = curr->right;
            }
        }
    }

    Node *find(int x)
    {
        if (root == NULL)
            return NULL;

        Node *curr = root;

        while (true)
        {
            if (curr == NULL)
            {
                return NULL;
            }
            if (x == curr->data)
            {
                return curr;
            }
            else if (x < curr->data)
            {
                if (curr->left == NULL)
                {
                    return NULL;
                }
                curr = curr->left;
            }
            else
            {
                if (curr->right == NULL)
                {
                    return NULL;
                }
                curr = curr->right;
            }
        }
    }

    Node *getmin(Node *curr)
    {
        while (curr->left != NULL)
        {
            curr = curr->left;
        }

        return curr;
    }

    Node *delutil(Node *curr, int x)
    {
        if (curr == NULL)
            return NULL;

        if (x < curr->data)
        {
            curr->child--;
            curr->left = delutil(curr->left, x);
        }

        else if (x > curr->data)
        {
            curr->child--;
            curr->right = delutil(curr->right, x);
        }
        else
        {
            if (curr->left == NULL)
                return curr->right;
            if (curr->right == NULL)
                return curr->left;

            Node *temp = getmin(curr->right);
            curr->data = temp->data;

            curr->child--;
            curr->right = delutil(curr->right, temp->data);

            return curr;
        }
    }

    void del(int x)
    {
        Node *curr = root;
        root = delutil(curr, x);
        return;
    }

    int randomUtil(Node *curr, int x)
    {
        int y = 0;
        if (curr->left)
            y = curr->left->child + 1;

        if (x == y + 1)
            return curr->data;
        else if (x <= y)
            return randomUtil(curr->left, x);
        else
            return randomUtil(curr->right, x - y - 1);
    }

    int getRandom()
    {
        int x = rand() % n;
        Node *curr = root;
        return randomUtil(curr, x);
    }
};
