#include <bits/stdc++.h>
using namespace std;

int kMostFrequent(int arr[], int n, int k)
{
    priority_queue<int, vector<int>, greater<int>> pq;
    unordered_map<int, int> mp;

    for (int i = 0; i < n; i++)
    {
        mp[arr[i]]++;
    }

    for (auto x : mp)
    {
        if (pq.size() < k)
        {
            pq.push(x.second);
        }
        else
        {
            if (x.second > pq.top())
            {
                pq.pop();
                pq.push(x.second);
            }
        }
    }

    int res = 0;
    while (!pq.empty())
    {
        res += pq.top();
        pq.pop();
    }

    return res;
}