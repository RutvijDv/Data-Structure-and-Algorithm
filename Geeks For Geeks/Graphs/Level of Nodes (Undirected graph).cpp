#include <bits/stdc++.h>
using namespace std;

int nodeLevel(int V, vector<int> adj[], int X)
{
    if (X >= V)
        return -1;

    vector<bool> visited(V, false);
    vector<int> level(V, -1);
    int l = 0;

    queue<int> q;
    visited[0] = true;
    q.push(0);

    level[0] = l;

    while (!q.empty())
    {
        int x = q.front();
        q.pop();
        for (auto j : adj[x])
        {
            if (!visited[j])
            {
                visited[j] = true;
                q.push(j);
                level[j] = level[x] + 1;
            }
        }
    }

    return level[X];
}