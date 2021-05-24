#include <bits/stdc++.h>
using namespace std;

bool dfs(vector<int> adj[], int i, vector<bool> &visited, vector<bool> &seen)
{

    visited[i] = true;
    seen[i] = true;

    for (auto j : adj[i])
    {
        if (!visited[j])
        {
            if (dfs(adj, j, visited, seen))
                return true;
        }
        else
        {
            if (seen[j])
                return true;
        }
    }
    seen[i] = false;
    return false;
}

bool isCyclic(int V, vector<int> adj[])
{
    vector<bool> visited(V, false);
    vector<bool> seen(V, false);

    for (int i = 0; i < V; i++)
    {
        if (!visited[i])
        {
            if (dfs(adj, i, visited, seen))
                return true;
        }
    }
    return false;
}