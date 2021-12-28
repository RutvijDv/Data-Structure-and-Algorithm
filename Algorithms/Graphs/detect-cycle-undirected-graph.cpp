#include <bits/stdc++.h>
using namespace std;

// DFS based solution
bool dfs(vector<int> adj[], vector<bool> &visited, int i, int parent)
{
    if (visited[i])
        return true;

    visited[i] = true;

    for (int j : adj[i])
    {
        if (j == parent)
            continue;
        if (dfs(adj, visited, j, i))
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
            if (dfs(adj, visited, i, -1))
                return true;
            else
                continue;
        }
    }

    return false;
}

// BFS based Solution
bool isCycle(int V, vector<int> adj[])
{

    vector<bool> visited(V, false);

    queue<int> q;

    vector<int> parent(V, -1);

    for (int i = 0; i < V; i++)
    {
        if (!visited[i])
        {
            q.push(i);
            visited[i] = true;

            while (!q.empty())
            {
                int u = q.front();
                q.pop();

                for (auto v : adj[u])
                {

                    if (parent[u] == v)
                        continue;
                    if (visited[v])
                        return true;

                    q.push(v);
                    parent[v] = u;
                    visited[u] = true;
                }
            }
        }
    }

    return false;
}