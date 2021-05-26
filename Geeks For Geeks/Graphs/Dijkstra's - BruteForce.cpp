#include <bits/stdc++.h>
using namespace std;

vector<int> dijkstra(int V, vector<vector<int>> adj[], int S)
{
    vector<int> res(V, INT_MAX);
    vector<bool> fixed(V, false);

    res[S] = 0;

    for (int i = 0; i < V; i++)
    {
        int d = INT_MAX, v;
        for (int j = 0; j < V; j++)
        {
            if (!fixed[j] && res[j] < d)
            {
                v = j;
                d = res[j];
            };
        }
        fixed[v] = true;

        for (auto j : adj[v])
        {
            int u = j[0];
            int d = j[1];
            if (d > 0 && res[u] > res[v] + d)
            {
                res[u] = res[v] + d;
            }
        }
    }

    return res;
}