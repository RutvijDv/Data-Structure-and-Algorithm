#include <bits/stdc++.h>
using namespace std;

void dfs(vector<int> adj[], int i, vector<bool> &visited, stack<int> &st)
{

    visited[i] = true;

    for (auto u : adj[i])
    {
        if (!visited[u])
            dfs(adj, u, visited, st);
    }

    st.push(i);
    return;
}

vector<int> topoSort(int V, vector<int> adj[])
{
    vector<int> res;
    vector<bool> visited(V, false);
    stack<int> st;

    for (int i = 0; i < V; i++)
    {
        if (!visited[i])
            dfs(adj, i, visited, st);
    }

    while (!st.empty())
    {
        int x = st.top();
        st.pop();
        res.push_back(x);
    }

    return res;
}