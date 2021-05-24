#include <bits/stdc++.h>
using namespace std;

bool isCyclic(int V, vector<int> adj[])
{
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

    int count = 0;
    while (!q.empty())
    {

        int v = q.front();
        q.pop();

        count++;
        for (auto u : adj[v])
        {
            indegree[u]--;
            if (indegree[u] == 0)
                q.push(u);
        }
    }

    return !(count == V);
}
