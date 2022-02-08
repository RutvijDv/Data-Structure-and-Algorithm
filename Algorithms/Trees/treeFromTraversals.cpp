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

int findIndex(int arr[], int start, int target)
{
    int i = 0;
    while (arr[start + i] != target)
        i++;
    return i;
}

// Building tree from inorder and preorder
Node *buildUtil1(int inorder[], int preorder[], int inStart, int preStart, int n)
{
    if (n == 0)
        return NULL;

    Node *ret = new Node(preorder[preStart]);

    int i = findIndex(inorder, inStart, preorder[preStart]);

    ret->left = buildUtil1(inorder, preorder, inStart, preStart + 1, i);
    ret->right = buildUtil1(inorder, preorder, inStart + i + 1, preStart + i + 1, n - i - 1);

    return ret;
}

// Building tree from inorder and postorder
Node *buildUtil2(int inorder[], int postorder[], int inStart, int &postStart, int n)
{
    if (n == 0)
        return NULL;

    Node *ret = new Node(postorder[postStart]);

    int i = findIndex(inorder, inStart, postorder[postStart]);

    postStart--;

    ret->right = buildUtil2(inorder, postorder, inStart + i + 1, postStart, n - i - 1);
    ret->left = buildUtil2(inorder, postorder, inStart, postStart, i);

    return ret;
}
