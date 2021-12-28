#include <bits/stdc++.h>
using namespace std;

// BFS based solution
void shortestDistance(vector<int> adj[], int V, int s, int dist[])
{
    bool visited[V];
    for (int i = 0; i < V; i++)
        visited[i] = false;

    queue<int> q;

    visited[s] = true;
    dist[s] = 0;
    q.push(s);

    while (q.empty() == false)
    {
        int u = q.front();
        q.pop();

        for (int v : adj[u])
        {
            if (visited[v] == false)
            {
                dist[v] = dist[u] + 1;
                visited[v] = true;
                q.push(v);
            }
        }
    }
}