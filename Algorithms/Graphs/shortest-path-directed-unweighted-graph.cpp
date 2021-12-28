#include <bits/stdc++.h>
using namespace std;

vector<int> topoSort(int V, vector<vector<int>> adj)
{
    vector<int> indegree(V, 0);
    vector<int> res;

    for (int i = 0; i < V; i++)
    {
        for (auto j : adj[i])
        {
            indegree[j]++;
        }
    }

    queue<int> q;

    for (int i = 0; i < V; i++)
    {
        if (indegree[i] == 0)
        {
            q.push(i);
            res.push_back(i);
        }
    }

    while (!q.empty())
    {

        int x = q.front();
        q.pop();

        for (auto j : adj[x])
        {
            indegree[j]--;

            if (indegree[j] == 0)
            {
                q.push(j);
                res.push_back(j);
            }
        }
    }
    return res;
}

vector<vector<int>> transform(vector<vector<int>> adj[], int V)
{
    vector<vector<int>> adjList;
    return adjList;
}

vector<int> shortestDistance(vector<vector<int>> adj[], int V)
{

    vector<int> res(V, INT_MAX);

    vector<vector<int>> adjList = transform(adj, V);

    vector<int> topoSorted = topoSort(V, adjList);

    for (int i = 0; i < V; i++)
    {
        int u = topoSorted[i];

        for (auto j : adj[u])
        {
            int v = j[0];
            int w = j[1];

            res[v] = min(res[v], res[u] + w);
        }
    }

    return res;
}