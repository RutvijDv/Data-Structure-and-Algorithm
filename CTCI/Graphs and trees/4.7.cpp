#include <bits/stdc++.h>
using namespace std;

void solve(vector<vector<int>> graph, int i, vector<bool> &visited, vector<int> &res)
{
    for (int j = 0; j < graph[i].size(); j++)
    {
        int x = graph[i][j];
        if (visited[x] == false)
            solve(graph, x, visited, res);
    }
    visited[i] = true;
    res.push_back(i);
    return;
}

vector<int> findOrder(int n, vector<pair<int, int>> &pre)
{
    vector<vector<int>> graph(n);
    vector<bool> visited(n, false);
    vector<int> res;

    for (int i = 0; i < pre.size(); i++)
    {

        int x = pre[i].first;
        int y = pre[i].second;

        graph[x].push_back(y);
    }

    for (int i = 0; i < n; i++)
    {
        if (visited[i] == false && graph[i].size() != 0)
            solve(graph, i, visited, res);
        else
        {
            visited[i] = true;
            res.push_back(i);
        }
    }

    return res;
}
