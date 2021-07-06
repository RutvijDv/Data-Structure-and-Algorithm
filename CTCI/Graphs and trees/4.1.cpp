#include <bits/stdc++.h>
using namespace std;

//Breadth First Search
bool bfs(int i, vector<int> adj[], vector<int> &visited, int end)
{
    queue<int> q;
    q.push(i);
    visited[i] = true;

    while (!q.empty())
    {
        int x = q.front();
        q.pop();

        for (auto y : adj[x])
        {
            if (!visited[y])
            {
                if (y == end)
                {
                    return true;
                }
                q.push(y);
                visited[y] = true;
            }
        }
    }

    return false;
}

bool bfsOfGraph(int V, vector<int> adj[])
{
    vector<int> visited(V, false);

    return (bfs(5, adj, visited, 6));
}

//Depth First Search
bool dfs(int n, vector<int> adj[], vector<bool> &visited, vector<int> &res, int end)
{
    res.push_back(n);
    visited[n] = true;

    for (auto j : adj[n])
    {
        if (!visited[j])
        {
            if (j == end)
            {
                return true;
            }
            if (dfs(j, adj, visited, res, end))
                return true;
        }
    }

    return false;
}

bool dfsOfGraph(int V, vector<int> adj[])
{
    vector<int> res;
    vector<bool> visited(V, false);

    return dfs(0, adj, visited, res, 4);
}