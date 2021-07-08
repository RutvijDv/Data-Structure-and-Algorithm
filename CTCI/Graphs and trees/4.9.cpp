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

void weave(vector<int> left, vector<int> right, vector<vector<int>> &result, vector<int> prefix)
{
    if (left.size() == 0 || right.size() == 0)
    {
        vector<int> x(prefix);
        x.insert(x.end(), left.begin(), left.end());
        x.insert(x.end(), right.begin(), right.end());
        result.push_back(x);
        return;
    }

    int x = left[0];
    left.erase(left.begin());
    prefix.push_back(x);
    weave(left, right, result, prefix);
    prefix.pop_back();
    left.insert(left.begin(), x);

    int y = right[0];
    right.erase(right.begin());
    prefix.push_back(y);
    weave(left, right, result, prefix);
    prefix.pop_back();
    right.insert(right.begin(), y);

    return;
}

vector<vector<int>> generate(Node *root)
{
    vector<vector<int>> res;

    if (root == NULL)
    {
        vector<int> x;
        res.push_back(x);
        return res;
    }

    vector<int> prefix;
    prefix.push_back(root->data);
    vector<vector<int>> leftSeq = generate(root->left);
    vector<vector<int>> rightSeq = generate(root->right);

    for (int i = 0; i < leftSeq.size(); i++)
    {
        for (int j = 0; j < rightSeq.size(); j++)
        {
            vector<vector<int>> result;
            weave(leftSeq[i], rightSeq[j], result, prefix);
            res.insert(res.end(), result.begin(), result.end());
        }
    }

    return res;
}

int main()
{
    struct Node *root = new Node(5);
    root->left = new Node(1);
    root->right = new Node(9);
    root->left->left = new Node(0);
    root->left->right = new Node(3);

    vector<vector<int>> sequence = generate(root);

    for (int i = 0; i < sequence.size(); i++)
    {
        for (int j = 0; j < sequence[i].size(); j++)
        {
            cout << sequence[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
