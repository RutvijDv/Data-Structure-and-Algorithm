#include <bits/stdc++.h>
using namespace std;

bool dfs(vector<int> adj[], int i, vector<bool> &visited, int parent)
{

    visited[i] = true;

    for (auto j : adj[i])
    {
        if (j == parent)
            continue;
        if (!visited[j])
        {
            if (dfs(adj, j, visited, i))
                return true;
        }
        else
            return true;
    }

    return false;
}

bool isCycle(int V, vector<int> adj[])
{
    vector<bool> visited(V, false);

    for (int i = 0; i < V; i++)
    {
        if (!visited[i])
        {
            if (dfs(adj, i, visited, -1))
                return true;
            else
                continue;
        }
        // cout<<"new"<<endl;
    }
    return false;
}