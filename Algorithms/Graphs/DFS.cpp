#include <bits/stdc++.h>
using namespace std;

void dfs(vector<int> adj[], vector<int> &res, vector<bool> &visited, int i)
{

    res.push_back(i);
    visited[i] = true;

    for (int j : adj[i])
    {
        if (!visited[j])
        {
            dfs(adj, res, visited, j);
        }
    }

    return;
}

// Function to return a list containing the DFS traversal of the graph.
vector<int> dfsOfGraph(int V, vector<int> adj[])
{
    // Code here
    vector<int> res;
    vector<bool> visited(V, false);

    dfs(adj, res, visited, 0);
    return res;
}