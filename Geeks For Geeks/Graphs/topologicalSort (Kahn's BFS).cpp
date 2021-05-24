#include <bits/stdc++.h>
using namespace std;

vector<int> topoSort(int V, vector<int> adj[])
{
    vector<int> res;
    vector<int> indegree(V, 0);

    for (int i = 0; i < V; i++)
    {
        for (auto u : adj[i])
        {
            indegree[u]++;
        }
    }

    queue<int> q;

    for (int i = 0; i < V; i++)
    {
        if (indegree[i] == 0)
            q.push(i);
    }

    while (!q.empty())
    {

        int v = q.front();
        q.pop();

        res.push_back(v);
        for (auto u : adj[v])
        {
            indegree[u]--;
            if (indegree[u] == 0)
                q.push(u);
        }
    }

    return res;
}