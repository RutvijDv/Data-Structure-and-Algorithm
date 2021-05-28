#include <bits/stdc++.h>
using namespace std;

bool solve(vector<int> &a, int b, int sum, vector<int> &temp, vector<vector<int>> &res, int index)
{
    if (sum == b)
    {
        res.push_back(temp);
        return true;
    }
    if (sum > b)
        return false;

    int n = a.size();
    bool flag = false;

    for (int i = index; i < n; i++)
    {
        temp.push_back(a[i]);
        sum += a[i];
        if (solve(a, b, sum, temp, res, i))
            flag = true;
        sum -= a[i];
        temp.pop_back();
    }

    if (flag)
        return true;
    else
        return false;
}

vector<vector<int>> combinationSum(vector<int> &A, int B)
{
    vector<vector<int>> res;
    vector<int> temp;

    sort(A.begin(), A.end());

    vector<int>::iterator ip;
    ip = unique(A.begin(), A.end());
    A.resize(distance(A.begin(), ip));

    solve(A, B, 0, temp, res, 0);

    return res;
}