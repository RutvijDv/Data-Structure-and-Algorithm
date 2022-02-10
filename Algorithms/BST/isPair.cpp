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

// inorder method
void treeToList(Node *root, vector<int> &list)
{
    if (root == NULL)
        return;

    treeToList(root->left, list);
    list.push_back(root->key);
    treeToList(root->right, list);
}

bool isPairPresent(Node *root, int target)
{
    vector<int> a2;

    treeToList(root, a2);

    int start = 0;

    int end = a2.size() - 1;

    while (start < end)
    {

        if (a2[start] + a2[end] == target)
        {
            cout << "Pair Found: " << a2[start] << " + " << a2[end] << " "
                 << "= " << target;
            return true;
        }

        if (a2[start] + a2[end] > target) // decrements end
        {
            end--;
        }

        if (a2[start] + a2[end] < target) // increments start
        {
            start++;
        }
    }

    cout << "No such values are found!";
    return false;
}

// Hashing method
bool isPairSum(Node *root, int sum, unordered_set<int> &s)
{
    if (root == NULL)
        return false;

    if (isPairSum(root->left, sum, s) == true)
        return true;

    if (s.find(sum - root->key) != s.end())
        return true;
    else
        s.insert(root->key);
    return isPairSum(root->right, sum, s);
}