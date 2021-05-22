#include <bits/stdc++.h>
using namespace std;

void bfs(vector<int> adj[], vector<int> &res, int i, vector<bool> visited)
{
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

    for (int i = 0; i < V; i++)
    {
        if (!visited[i])
            bfs(adj, res, i, visited);
    }

    return res;
}