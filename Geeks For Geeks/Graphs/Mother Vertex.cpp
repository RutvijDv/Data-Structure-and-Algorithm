#include <bits/stdc++.h>
using namespace std;

void dfs(vector<int> adj[], int i, vector<bool> &visited)
{

    visited[i] = true;

    for (auto j : adj[i])
    {
        if (!visited[j])
        {
            dfs(adj, j, visited);
        }
    }

    return;
}

int findMotherVertex(int V, vector<int> adj[])
{
    vector<bool> visited(V, false);

    int last;
    for (int i = 0; i < V; i++)
    {
        if (!visited[i])
        {
            dfs(adj, i, visited);
            last = i;
        }
    }

    fill(visited.begin(), visited.end(), false);
    dfs(adj, last, visited);

    for (int i = 0; i < V; i++)
    {
        if (visited[i] == false)
            return -1;
    }

    return last;
}