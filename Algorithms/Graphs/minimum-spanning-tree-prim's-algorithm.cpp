#include <bits/stdc++.h>
using namespace std;

// Simple approach
pair<int, int> getMinIndex(vector<int> &dis, vector<bool> &visited)
{

    pair<int, int> p = {INT_MAX, -1};

    for (int i = 0; i < dis.size(); i++)
    {
        if (!visited[i] && p.first > dis[i])
        {
            p.first = dis[i];
            p.second = i;
        }
    }

    return p;
}

int spanningTree(int V, vector<vector<int>> adj[])
{
    vector<int> dis(V, INT_MAX);
    vector<bool> visited(V, false);

    int res = 0;

    dis[0] = 0;

    for (int i = 0; i < V; i++)
    {

        pair<int, int> p = getMinIndex(dis, visited);

        int u = p.second;
        int w = p.first;

        res += w;

        visited[u] = true;

        for (auto x : adj[u])
        {

            int v = x[0];
            int w = x[1];

            if (!visited[v] && dis[v] > w)
            {
                dis[v] = w;
            }
        }
    }

    return res;
}

// using PriorityQueue
int spanningTree(int V, vector<vector<int>> adj[])
{
    vector<int> dis(V, INT_MAX);
    vector<bool> visited(V, false);

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    int res = 0;

    dis[0] = 0;
    pq.push({0, 0});

    while (!pq.empty())
    {
        pair<int, int> p = pq.top();
        pq.pop();

        int u = p.second;
        int w = p.first;

        if (visited[u])
            continue;

        res += w;

        visited[u] = true;

        for (auto x : adj[u])
        {

            int v = x[0];
            int w1 = x[1];

            if (!visited[v] && dis[v] > w1)
            {
                dis[v] = w1;
                pq.push({dis[v], v});
            }
        }
    }

    return res;
}