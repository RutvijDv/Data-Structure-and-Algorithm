#include <bits/stdc++.h>
using namespace std;

// DFS based solution
bool dfs(vector<int> adj[], vector<bool> &visited, vector<bool> &seen, int i)
{
    visited[i] = true;
    seen[i] = true;

    for (auto j : adj[i])
    {

        if (!visited[j])
        {
            if (dfs(adj, visited, seen, j))
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
            if (dfs(adj, visited, seen, i))
                return true;
            else
                continue;
        }
    }

    return false;
}

// BFS based solution
bool isCyclic(int V, vector<int> adj[])
{
    vector<int> indegree(V, 0);

    for (int i = 0; i < V; i++)
    {
        for (auto u : adj[i])
        {
            indegree[u]++;
        }
    }

    queue<int> q;

    for (int i = 0; i < V; i++)
    {
        if (indegree[i] == 0)
            q.push(i);
    }

    int count = 0;
    while (!q.empty())
    {
        int v = q.front();
        q.pop();

        count++;
        for (auto u : adj[v])
        {
            indegree[u]--;
            if (indegree[u] == 0)
                q.push(u);
        }
    }

    return !(count == V);
}