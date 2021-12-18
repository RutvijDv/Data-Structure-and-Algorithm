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

// DP Solution
int solve(int l, int r, vector<vector<int>> &dp)
{

    if (l > r)
    {
        dp[l][r] = 0;
        return 0;
    }
    if (l == r)
    {
        dp[l][r] = 1;
        return 1;
    }

    int response = 0;

    for (int i = l; i <= r; i++)
    {

        int left = dp[l][i - 1] == -1 ? solve(l, i - 1, dp) : dp[l][i - 1];
        int right = dp[i + 1][r] == -1 ? solve(i + 1, r, dp) : dp[i + 1][r];

        int add = max(left * right, max(left * 1, right * 1));
        response += add;
    }

    dp[l][r] = response;
    return response;
}

int numTrees(int n)
{
    vector<vector<int>> dp(n + 2, vector<int>(n + 2, -1));

    int res = solve(1, n, dp);

    return res;
}