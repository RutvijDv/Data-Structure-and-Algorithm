#include <bits/stdc++.h>
using namespace std;

// BFS based solution
vector<int> topoSort(int V, vector<int> adj[])
{
    vector<int> indegree(V, 0);
    vector<int> res;

    for (int i = 0; i < V; i++)
    {
        for (auto j : adj[i])
        {
            indegree[j]++;
        }
    }

    queue<int> q;

    for (int i = 0; i < V; i++)
    {
        if (indegree[i] == 0)
        {
            q.push(i);
            res.push_back(i);
        }
    }

    while (!q.empty())
    {

        int x = q.front();
        q.pop();

        for (auto j : adj[x])
        {
            indegree[j]--;

            if (indegree[j] == 0)
            {
                q.push(j);
                res.push_back(j);
            }
        }
    }
    return res;
}

// DFS based solution
void dfs(vector<int> adj[], vector<bool> &visited, stack<int> &st, int u)
{

    if (visited[u])
        return;

    visited[u] = true;

    for (auto v : adj[u])
    {
        dfs(adj, visited, st, v);
    }

    st.push(u);
}

vector<int> topoSort(int V, vector<int> adj[])
{
    vector<int> res;
    vector<bool> visited(V, false);
    stack<int> st;

    for (int i = 0; i < V; i++)
    {
        if (!visited[i])
        {
            dfs(adj, visited, st, i);
        }
    }

    while (!st.empty())
    {
        int x = st.top();
        st.pop();
        res.push_back(x);
    }

    return res;
}