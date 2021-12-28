#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
    TreeNode *left;
    TreeNode *right;
    int val;
    TreeNode(int x)
    {
        val = x;
        left = right = NULL;
    }
};

struct ListNode
{
    ListNode *next = NULL;
    int val;
    ListNode(int x)
    {
        val = x;
        next = NULL;
    }
};

TreeNode *solve(ListNode *head, int l)
{

    if (head == NULL || l == 0)
        return NULL;

    if (l == 1)
    {
        TreeNode *response = new TreeNode(head->val);
        return response;
    }

    int mid;

    if (l % 2 == 1)
        mid = l / 2 + 1;
    else
        mid = l / 2;

    ListNode *curr = head;

    for (int i = 0; i < mid - 1; i++)
    {
        curr = curr->next;
    }

    TreeNode *response = new TreeNode(curr->val);

    if (l % 2 == 1)
    {
        response->left = solve(head, mid - 1);
        response->right = solve(curr->next, mid - 1);
    }
    else
    {
        response->left = solve(head, mid - 1);
        response->right = solve(curr->next, mid);
    }

    return response;
}

TreeNode *sortedListToBST(ListNode *head)
{

    int l = 0;
    ListNode *curr = head;

    while (curr != NULL)
    {
        l++;
        curr = curr->next;
    }

    TreeNode *res = solve(head, l);

    return res;
}