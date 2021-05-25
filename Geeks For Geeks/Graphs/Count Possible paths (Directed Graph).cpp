#include <bits/stdc++.h>
using namespace std;

void dfs(vector<int> adj[], int s, int d, int &count, vector<bool> &visited)
{
    if (s == d)
    {
        count++;
        return;
    }

    visited[s] = true;

    for (auto j : adj[s])
    {
        dfs(adj, j, d, count, visited);
    }

    visited[s] = false;

    return;
}

int countPaths(int V, vector<int> adj[], int source, int destination)
{
    int count = 0;
    vector<bool> visited(V, false);
    dfs(adj, source, destination, count, visited);
    return count;
}

// Visited vector can be completely ignored if your directed graph is acyclic