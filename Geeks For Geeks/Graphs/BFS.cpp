#include <bits/stdc++.h>
using namespace std;

void bfs(vector<int> adj[], vector<int> &res, int i, int V)
{

    bool visited[V];
    for (int i = 0; i < V; i++)
        visited[i] = false;

    queue<int> q;
    q.push(i);

    while (!q.empty())
    {
        int x = q.front();
        q.pop();
        res.push_back(x);
        for (auto j : adj[x])
        {
            if (!visited[j])
            {
                visited[j] = true;
                q.push(j);
            }
        }
    }
    return;
}

vector<int> bfsOfGraph(int V, vector<int> adj[])
{
    vector<int> res;
    vector<bool> visited(V, false);

    bfs(adj, res, 0, V);

    return res;
}