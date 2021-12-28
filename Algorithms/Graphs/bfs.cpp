#include <bits/stdc++.h>
using namespace std;

vector<int> bfsOfGraph(int V, vector<int> adj[])
{
    vector<int> res;

    vector<bool> visited(V, false);

    queue<int> q;
    q.push(0);

    while (!q.empty())
    {
        int i = q.front();
        q.pop();

        res.push_back(i);

        for (auto j : adj[i])
        {
            if (!visited[j])
            {
                visited[j] = true;
                q.push(j);
            }
        }
    }

    return res;
}
