#include <bits/stdc++.h>
using namespace std;

string rearrangeString(string str)
{
    int n = str.length();
    unordered_map<char, int> mp;
    priority_queue<pair<int, char>> pq;

    for (int i = 0; i < n; i++)
    {
        mp[str[i]]++;
    }

    for (auto x : mp)
    {
        pq.push({x.second, x.first});
    }

    string res = "";
    pair<int, char> p, last;
    last.first = 0;

    while (!pq.empty())
    {
        p = pq.top();
        pq.pop();

        res += p.second;
        p.first--;

        if (last.first > 0)
        {
            pq.push(last);
        }

        last = p;
    }

    return res;
}