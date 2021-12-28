#include <bits/stdc++.h>
using namespace std;

// Simple approach
int getMinIndex(vector<int> &dis, vector<bool> &visited)
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

    return p.second;
}

vector<int> dijkstra(int V, vector<vector<int>> adj[], int S)
{
    vector<int> dis(V, INT_MAX);

    vector<bool> visited(V, false);

    dis[S] = 0;

    for (int i = 0; i < V; i++)
    {

        int u = getMinIndex(dis, visited);

        visited[u] = true;

        for (auto x : adj[u])
        {

            int v = x[0];
            int w = x[1];

            if (!visited[v] && dis[v] > dis[u] + w)
            {
                dis[v] = dis[u] + w;
            }
        }
    }

    return dis;
}

// using PriorityQueue
vector<int> dijkstra(int V, vector<vector<int>> adj[], int S)
{
    vector<int> dis(V, INT_MAX);

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    dis[S] = 0;
    pq.push({0, S});

    while (!pq.empty())
    {
        pair<int, int> p = pq.top();
        pq.pop();

        int u = p.second;

        for (auto x : adj[u])
        {

            int v = x[0];
            int w = x[1];

            if (dis[v] > dis[u] + w)
            {
                dis[v] = dis[u] + w;
                pq.push({dis[v], v});
            }
        }
    }

    return dis;
}