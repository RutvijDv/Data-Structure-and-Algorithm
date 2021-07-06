#include <bits/stdc++.h>
using namespace std;

void solve(vector<int> &nums, vector<int> &res, int l, int r)
{
    if (l <= r)
    {
        int mid = l + (r - l) / 2;
        int x = nums[mid];
        res.push_back(x);

        solve(nums, res, l, mid - 1);
        solve(nums, res, mid + 1, r);
    }

    return;
}

vector<int> sortedArrayToBST(vector<int> &nums)
{
    int n = nums.size();

    vector<int> res;

    solve(nums, res, 0, n - 1);

    return res;
}