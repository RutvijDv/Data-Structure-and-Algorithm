#include <bits/stdc++.h>
using namespace std;

void permute(vector<int> arr, int n, int idx, vector<vector<int>> &res, vector<int> temp, bool flag)
{

    if (idx == n)
    {
        res.push_back(temp);
        return;
    }

    if (!(idx > 0 && arr[idx] == arr[idx - 1] && flag))
    {
        temp.push_back(arr[idx]);
        permute(arr, n, idx + 1, res, temp, false);
        temp.pop_back();
    }

    permute(arr, n, idx + 1, res, temp, true);

    return;
}

vector<vector<int>> AllSubsets(vector<int> arr, int n)
{
    sort(arr.begin(), arr.end());
    vector<vector<int>> res;
    vector<int> temp;
    permute(arr, n, 0, res, temp, false);
    sort(res.begin(), res.end());
    return res;
}