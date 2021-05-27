#include <bits/stdc++.h>
using namespace std;

int activitySelection(vector<int> start, vector<int> end, int n)
{
    vector<pair<int, int>> v;

    for (int i = 0; i < n; i++)
    {
        v.push_back(make_pair(start[i], end[i]));
    }

    sort(v.begin(), v.end(), [](pair<int, int> a, pair<int, int> b)
         { return a.second < b.second; });

    int res = 1;
    int prev = 0;

    for (int i = 1; i < n; i++)
    {
        if (v[prev].second < v[i].first)
        {
            prev = i;
            res++;
        }
    }

    return res;
}