#include <bits/stdc++.h>
using namespace std;

int minSwaps(vector<int> &nums)
{
    int n = nums.size();
    unordered_map<int, int> mp;
    vector<int> temp = nums;

    sort(nums.begin(), nums.end());
    for (int i = 0; i < n; i++)
        mp[nums[i]] = i;

    vector<bool> visited(n, false);

    int res = 0;

    for (int i = 0; i < n; i++)
    {
        if (temp[i] == nums[i] || visited[i])
            continue;

        int j = i;
        int count = 0;

        while (!visited[j])
        {
            visited[j] = true;
            j = mp[temp[j]];
            count++;
        }

        res += count - 1;
    }

    return res;
}