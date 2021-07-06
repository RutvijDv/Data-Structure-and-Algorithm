#include <bits/stdc++.h>
using namespace std;

//Brute Force
bool compare(vector<int> a, vector<int> b)
{

    if (a[0] > b[0])
        return true;
    else if (a[0] == b[0])
    {
        if (a[1] > b[1] || a[2] > b[2])
            return true;
        else
            return false;
    }
    else
        return false;
}

int solve(vector<vector<int>> &box, int idx, int n)
{

    if (idx == n)
        return 0;

    int out = 0;

    for (int i = idx + 1; i < n; i++)
    {
        if (box[i][1] < box[idx][1] && box[i][2] < box[idx][2])
        {
            int h = solve(box, i, n);
            out = max(out, h);
        }
    }

    out += box[idx][0];
    return out;
}

int maxHeight(int height[], int width[], int length[], int n)
{
    vector<vector<int>> box(n, vector<int>(3, 0));

    for (int i = 0; i < n; i++)
    {
        box[i][0] = height[i];
        box[i][1] = width[i];
        box[i][2] = length[i];
    }

    sort(box.begin(), box.end(), compare);

    int res = 0;

    for (int i = 0; i < n; i++)
    {
        int h = solve(box, 0, n);
        res = max(res, h);
    }

    return res;
}
//This brute force method can also be solved using Dp

// Better
bool compare(vector<int> a, vector<int> b)
{

    if (a[0] > b[0])
        return true;
    else if (a[0] == b[0])
    {
        if (a[1] > b[1] || a[2] > b[2])
            return true;
        else
            return false;
    }
    else
        return false;
}

int solve(vector<vector<int>> &box, int idx, int n, int last)
{

    if (idx == n)
        return 0;

    int res1 = 0, res2 = 0;

    if ((last == -1) || (box[last][1] > box[idx][1] && box[last][2] > box[idx][2]))
    {
        res1 = box[idx][0] + solve(box, idx + 1, n, idx);
    }

    res2 = solve(box, idx + 1, n, last);

    return max(res1, res2);
}

int maxHeight(int height[], int width[], int length[], int n)
{
    vector<vector<int>> box(n, vector<int>(3, 0));

    for (int i = 0; i < n; i++)
    {
        box[i][0] = height[i];
        box[i][1] = width[i];
        box[i][2] = length[i];
    }

    sort(box.begin(), box.end(), compare);

    int h = solve(box, 0, n, -1);
    return h;
}

//Using Dp
bool compare(vector<int> a, vector<int> b)
{

    if (a[0] > b[0])
        return true;
    else if (a[0] == b[0])
    {
        if (a[1] > b[1] || a[2] > b[2])
            return true;
        else
            return false;
    }
    else
        return false;
}

int solve(vector<vector<int>> &box, int idx, int n, int last, vector<int> dp)
{

    if (idx == n)
        return 0;
    if (dp[idx] != 0)
        return dp[idx];

    int res1 = 0, res2 = 0;

    if ((last == -1) || (box[last][1] > box[idx][1] && box[last][2] > box[idx][2]))
    {
        res1 = box[idx][0] + solve(box, idx + 1, n, idx, dp);
    }

    res2 = solve(box, idx + 1, n, last, dp);

    dp[idx] = max(res1, res2);
    return dp[idx];
}

int maxHeight(int height[], int width[], int length[], int n)
{
    vector<vector<int>> box(n, vector<int>(3, 0));
    vector<int> dp(n + 1, 0);

    for (int i = 0; i < n; i++)
    {
        box[i][0] = height[i];
        box[i][1] = width[i];
        box[i][2] = length[i];
    }

    sort(box.begin(), box.end(), compare);

    int h = solve(box, 0, n, -1, dp);
    return h;
}