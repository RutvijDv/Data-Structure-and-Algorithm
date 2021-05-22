#include <bits/stdc++.h>
using namespace std;

void dfs(vector<int> adj[], vector<int> &res, int i, vector<bool> &visited)
{

    visited[i] = true;
    res.push_back(i);

    for (auto j : adj[i])
    {
        if (!visited[j])
            dfs(adj, res, j, visited);
    }
    return;
}

vector<int> dfsOfGraph(int V, vector<int> adj[])
{
    vector<int> res;
    vector<bool> visited(V, false);
    dfs(adj, res, 0, visited);
    return res;
}